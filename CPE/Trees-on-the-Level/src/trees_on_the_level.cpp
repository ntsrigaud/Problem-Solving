#include <iostream>
#include <memory>
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

const std::string HEAD = "H";
const std::string INVALID_NODE_POSITION = "I";

class TreeNode {
public:
  explicit TreeNode(int v, const std::string &pos) : value{v}, position{pos} {};

  int getValue() const { return value; };
  std::string getPosition() const { return position; };

  std::shared_ptr<TreeNode> getChild(int n) {
    if (n != 0 || n != 1) {
      return nullptr;
    }

    return (n == 0) ? left : right;
  };

  friend std::ostream &operator<<(std::ostream &out, const TreeNode &t) {
    out << "(" << t.value << ", " << t.position << ")";
    return out;
  }

private:
  int value;
  std::string position;
  std::shared_ptr<TreeNode> left;
  std::shared_ptr<TreeNode> right;
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

std::shared_ptr<TreeNode> primary() {
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
      return std::make_shared<TreeNode>(v, HEAD);
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

std::shared_ptr<TreeNode> expression() {
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
  explicit Tree(std::shared_ptr<TreeNode> h) : head(h) {};

  void levelOrderTraversal() const { std::cout << "Level order traversal\n"; };

  bool isCompletelySpecified() const { return tree_specified; };

private:
  std::shared_ptr<TreeNode> head;
  int tree_specified = true;
};

int main(int argc, char *argv[]) {

  // Get nodes
  while (true) {
    TreeNode new_node = expression();
    if (new_node.getValue() == INVALID_NODE_VALUE) {
      break;
    }

    std::cout << "Created: " << new_node << std::endl;
  }

  return 0;
}
