#include "solution.h"

#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace {
constexpr char NUMBER = '8';
constexpr char LEFT = 'L';
constexpr char RIGHT = 'R';
constexpr char POSITION = 'p';
constexpr int INVALID_NODE_VALUE = -1;

const std::string INVALID_NODE_POSITION = "I";

class TreeNode;
using NodePtr = std::shared_ptr<TreeNode>;

class TreeNode {
public:
  explicit TreeNode(int v, const std::string &pos)
      : value{v}, position{pos}, left{nullptr}, right{nullptr} {};

  int getValue() const { return value; };
  std::string getPosition() const { return position; };

  NodePtr getChild(char p) {
    if (p != LEFT && p != RIGHT) {
      return nullptr;
    }

    return (p == LEFT) ? left : right;
  };

  void setChild(char p, NodePtr &node) {
    if (p != LEFT && p != RIGHT) {
      throw std::invalid_argument("invalid child node position");
    }

    if (p == LEFT) {
      left = node;
    } else {
      right = node;
    }
  };

private:
  int value;
  std::string position;
  NodePtr left;
  NodePtr right;
};

// Token stream + parser utilities
class Token {
public:
  char kind;
  int value;
  std::string position;
  Token() : kind{0}, value{0} {};
  Token(char k) : kind{k}, value{0} {};
  Token(char k, int v) : kind{k}, value{v} {};
  Token(char k, std::string d) : kind{k}, value{0}, position{d} {};
};

class Token_stream {
public:
  explicit Token_stream(std::istream &is) : in(is) {}
  Token get();
  void putback(Token t);

private:
  std::stack<Token> buffer;
  std::istream &in;
};

void Token_stream::putback(Token t) { buffer.push(t); }
Token Token_stream::get() {
  if (!buffer.empty()) {
    Token t = buffer.top();
    buffer.pop();
    return t;
  }

  char ch = 0;

  // Read and skip whitespace/newlines
  while (in.get(ch) &&
         (std::isspace(static_cast<unsigned char>(ch)) || ch == '\n'))
    ;

  if (!in) {
    throw std::invalid_argument("no input");
  }

  switch (ch) {
  case '(':
  case ')':
  case ',':
    return Token{ch};
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': {
    in.putback(ch);
    int val = 0;
    in >> val;
    return Token{NUMBER, val};
  }
  default: {
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      std::string s;
      s += ch;

      while (in.get(ch) && (ch == LEFT || ch == RIGHT)) {
        s += ch;
      }
      in.putback(ch);
      return Token{POSITION, s};
    }
  }
  }

  throw std::invalid_argument(std::string("bad token ") + ch);
}

class Tree {
public:
  explicit Tree(NodePtr h) : head(h), tree_specified(true) {};

  void levelOrderTraversal(std::ostream &out) const {
    std::queue<NodePtr> q;

    q.push(head);
    while (!q.empty()) {
      out << q.front()->getValue() << " ";

      auto left_child = q.front()->getChild(LEFT);
      auto right_child = q.front()->getChild(RIGHT);
      if (left_child)
        q.push(left_child);
      if (right_child)
        q.push(right_child);

      q.pop();
    }
    out << '\n';
  };

  void insertNodes(std::vector<NodePtr> &node_list) {
    std::unordered_map<int, bool> duplicates;

    // Include head node value in duplicates tracking so duplicate values
    // between head and other nodes are detected as 'not complete'.
    if (tree_specified && head) {
      duplicates[head->getValue()] = false;
    }
    std::string node_path;
    NodePtr parent;

    // Sort nodes by position length so we attach parents before children
    auto comp_nodes = [](NodePtr &a, NodePtr &b) {
      return a->getPosition().length() < b->getPosition().length();
    };
    std::sort(node_list.begin(), node_list.end(), comp_nodes);

    for (auto &n : node_list) {
      if (tree_specified) {
        if (duplicates.count(n->getValue())) {
          tree_specified = false;
        } else {
          duplicates[n->getValue()] = false;
        }
      }

      parent = head;
      node_path = n->getPosition();

      while (node_path.size() > 1) {
        parent = parent->getChild(node_path.front());
        node_path = node_path.substr(1, node_path.size());
      }

      if (parent->getChild(node_path.front()) != nullptr) {
        throw std::runtime_error(
            "inserting new node to already taken position");
      }
      parent->setChild(node_path.front(), n);
    }
  };

  bool isCompletelySpecified() const { return tree_specified; };

private:
  NodePtr head;
  bool tree_specified;
};

} // namespace

// Process using provided streams. This is the testable implementation.
void Solution::process(std::istream &in, std::ostream &out) {
  // Construct a Token_stream that reads from `in`.
  Token_stream ts(in);

  // parser lambdas that use ts
  std::function<NodePtr()> primary = [&ts]() -> NodePtr {
    Token t = ts.get();

    if (t.kind == NUMBER) {
      int v = t.value;
      t = ts.get();

      if (t.kind != ',') {
        throw std::invalid_argument("',' expected");
      }

      t = ts.get();
      if (t.kind == ')') {
        ts.putback(t);
        return std::make_shared<TreeNode>(v, "");
      } else if (t.kind == POSITION) {
        return std::make_shared<TreeNode>(v, t.position);
      } else {
        throw std::invalid_argument("'position' expected");
      }
    } else if (t.kind == ')') {
      ts.putback(t);
      return std::make_shared<TreeNode>(INVALID_NODE_VALUE,
                                        INVALID_NODE_POSITION);
    }

    throw std::invalid_argument("'number' expected");
  };

  std::function<NodePtr()> expression = [&ts, &primary]() -> NodePtr {
    Token t = ts.get();

    if (t.kind == '(') {
      auto node = primary();
      t = ts.get();
      if (t.kind != ')') {
        throw std::invalid_argument("')' expected");
      }
      return node;
    }

    throw std::invalid_argument("'(' expected");
  };

  // Process multiple tree specifications until input exhausted.
  while (true) {
    std::vector<NodePtr> node_list;
    NodePtr head = nullptr;

    // Read a single tree's tokens until terminator "()"
    while (true) {
      Token t;
      try {
        auto new_node = expression();
        if (new_node->getValue() == INVALID_NODE_VALUE) {
          break; // end of this tree specification
        }

        if (new_node->getPosition().empty()) {
          if (head != nullptr) {
            throw std::invalid_argument("binary tree with multiple head nodes");
          }
          head = new_node;
        } else {
          node_list.push_back(new_node);
        }
      } catch (const std::invalid_argument &e) {
        // If the parser signalled no more input, stop processing groups.
        if (std::string(e.what()) == "no input") {
          // If we haven't collected any nodes for this group, we're done.
          if (node_list.empty() && head == nullptr) {
            return;
          }
          // Otherwise, propagate the error.
        }
        throw;
      }
    }

    // If this group is empty (i.e., immediate "()" with no nodes), then
    // it's the end of all input for UVa-style input. Stop processing.
    if (node_list.empty() && head == nullptr) {
      return;
    }

    if (node_list.empty()) {
      throw std::invalid_argument("empty node list");
    }

    if (head == nullptr) {
      throw std::invalid_argument("binary tree without head node");
    }

    Tree bin_tree(head);
    bin_tree.insertNodes(node_list);
    bin_tree.levelOrderTraversal(out);
    if (!bin_tree.isCompletelySpecified()) {
      out << "not complete\n";
    }
    // Continue to next group (if any)
  }
}

// Backwards-compatible wrapper that uses std::cin/std::cout for manual runs.
void Solution::run() { process(std::cin, std::cout); }
