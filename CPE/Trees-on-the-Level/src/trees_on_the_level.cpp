#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

/*
 * UVA: Trees on the level
 * Link: https://onlinejudge.org/external/1/122.pdf
 *
 * Revision history:
 * Originally written by Neil Taison Rigaud, November 2025
 *
 * This program implements the solution to the "UVA: Trees on the level"
 * problem.
 *
 * Implementation procedure
 * ------------------------
 * 1) Build and traversse the binary tree
 *    - Parse token stream to create tree nodes
 *    - Add new nodes to tree until "()"
 *    - Perform level-order tree traversal
 *      - Initialize a queue with the tree HEAD node
 *      * Use a hash table to track the node values for the "tree complete
 * specification"
 *      - Pop the front node in the queue, display it and enqueue its children
 * if any
 *      - Repeat the process until the queue is empty
 * 2) Use a boolean variable `tree_specified` along with the hash table to
 * denote the tree specification
 *    - The keys of the hash table are the node values when first inserted.
 *    - The values corresponding to the keys are booleans to denote if the value
 * is duplicated or not.
 *    - `tree_specified` should be initialized to true.
 *      - When a duplicated node has been found, it should update to false only
 * once.
 *    - If the `tree_specified` is false, stop tracking the node values.
 *
 *
 * Token Stream - Input Parser Grammar
 * -----------------------------------
 * Expression:
 *   "(" Primary ")"
 * Primary:
 *   Number "," Position
 * Number:
 *   integer
 * Position:
 *   string | epsilon
 * */

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

  friend std::ostream &operator<<(std::ostream &out, const TreeNode &t) {
    out << "(" << t.value << ", " << t.position << ")";
    return out;
  }

private:
  int value;
  std::string position;
  NodePtr left;
  NodePtr right;
};

// Token stream class
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
  Token get();
  void putback(Token t);

private:
  std::stack<Token> buffer;
};

void Token_stream::putback(Token t) { buffer.push(t); }
Token Token_stream::get()
// Read characters from cin and compose a Token
{
  // Check if we already have a Token ready
  if (!buffer.empty()) {
    Token t = buffer.top();
    buffer.pop();
    return t;
  }
  char ch = 0;

  // Ignore all whitespaces
  while (std::cin.get(ch) && (std::isspace(ch) || ch == '\n'))
    ;

  if (ch == 0) {
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
    std::cin.putback(ch);
    int val = 0;
    std::cin >> val;
    return Token{NUMBER, val};
  }
  default: {
    if (std::isalpha(ch)) {
      std::string s;
      s += ch;

      while (std::cin.get(ch) && (ch == LEFT || ch == RIGHT)) {
        s += ch;
      }
      std::cin.putback(ch);
      return Token{POSITION, s};
    }
  }
  }

  throw std::invalid_argument("bad token " + std::to_string(ch));
};

Token_stream ts;

NodePtr primary() {
  Token t = ts.get();

  if (t.kind == NUMBER) {
    int v = t.value;
    t = ts.get();

    if (t.kind != ',') {
      throw std::invalid_argument("',' expected");
    }

    // Parse second member
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
    // End of input in main process
    ts.putback(t);
    return std::make_shared<TreeNode>(INVALID_NODE_VALUE,
                                      INVALID_NODE_POSITION);
  }

  throw std::invalid_argument("'number' expected");
};

NodePtr expression() {
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

class Tree {
public:
  explicit Tree(NodePtr h) : head(h) {};

  void levelOrderTraversal() const {
    std::queue<NodePtr> q;

    q.push(head);
    while (!q.empty()) {
      std::cout << q.front()->getValue() << " ";

      auto left_child = q.front()->getChild(LEFT);
      auto right_child = q.front()->getChild(RIGHT);
      if (left_child)
        q.push(left_child);
      if (right_child)
        q.push(right_child);

      q.pop();
    }
    std::cout << '\n';
  };

  void insertNodes(std::vector<NodePtr> &node_list) {
    std::string node_path;
    NodePtr parent;

    // Sort the node sequence for correct tree insertion
    auto comp_nodes = [](NodePtr &a, NodePtr &b) {
      return a->getPosition().length() < b->getPosition().length();
    };
    std::sort(node_list.begin(), node_list.end(), comp_nodes);

    // Insert nodes
    for (auto &n : node_list) {
      parent = head;
      node_path = n->getPosition();

      while (node_path.size() > 1) {
        // Traverse to left or right
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
  int tree_specified = true;
};

int main(int argc, char *argv[]) {
  // Assuming that only correct tree node sequences are provided.

  std::vector<NodePtr> node_list;
  NodePtr head;

  try {
    // Get nodes
    while (true) {
      auto new_node = expression();
      if (new_node->getValue() == INVALID_NODE_VALUE) {
        break;
      }

      // Extract head node from sequence
      if (new_node->getPosition().empty()) {
        if (head != nullptr) {
          throw std::invalid_argument("binary tree with multiple head nodes");
        }

        head = new_node;
      } else {
        node_list.push_back(new_node);
      }
    }

    if (node_list.empty()) {
      throw std::invalid_argument("empty node list");
      return -1;
    }

    // Build tree
    Tree bin_tree(head);
    bin_tree.insertNodes(node_list);
    bin_tree.levelOrderTraversal();
    if (!bin_tree.isCompletelySpecified()) {
      std::cout << "not complete\n";
    }

  } catch (const std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << "\n";
    return -1;
  } catch (const std::runtime_error &e) {
    std::cerr << "Runtime error: " << e.what() << "\n";
    return -1;
  } catch (...) {
    std::cerr << "An unexpected error occured.\n";
    return -1;
  };

  return 0;
}
