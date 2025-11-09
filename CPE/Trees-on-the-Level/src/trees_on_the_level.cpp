#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
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
 * 1) Retrieve nodes in main in sequences until you encounter '()'
 *    - Retrieve the only the first node in the main loop
 *    - Retrieve the rest of nodes until you encounter '()'
 *
 * 2) Process sequence:
 *    a) Validate sequence:
 *       - Check if sequence contains a HEAD node
 *          -> Stop and output "not complete"
 *       - Check if sequence contains duplicate tree positions
 *          -> Stop and output "not complete"
 *       - Check if sequence misses tree positions
 *          -> Stop and output "not complete"
 *       - Check if sequence contains duplicate values
 *          -> Update tree_complete_specification to false
 *
 *    b) Display level order traversal
 *
 *    c) If tree_complete_specication == false, then output "not complete\n"
 *
 * 3) Proceed to 1) until end of input
 *
 * */

enum class TreeState : std::int8_t { INVALID, NOT_COMPLETE, COMPLETE };
enum class ChildPosition : std::int8_t { LEFT = 'L', RIGHT = 'R' };

class Node;
using NodePtr = std::shared_ptr<Node>;

class Node {
public:
  Node(int v, const std::string &pos) : value(v), position(pos) {};

  void setChild(const ChildPosition &p, const NodePtr &n) {
    if (p == ChildPosition::LEFT) {
      left = n;
    } else {
      right = n;
    }
  };

  [[nodiscard]] NodePtr getChild(const ChildPosition &p) const {
    return (p == ChildPosition::LEFT) ? left : right;
  }

  [[nodiscard]] std::string getPosition() const { return position; };
  [[nodiscard]] int getValue() const { return value; };

  void print_node() const {
    std::cout << '(' << value << ", " << position << ')';
  };

private:
  int value;
  std::string position;
  NodePtr left;
  NodePtr right;
};

int main() {
  char open_par = 0;
  char comma = 0;
  int value = 0;

  TreeState tree_state = TreeState::INVALID;

  std::string position;
  std::string parent;

  std::vector<NodePtr> nodes;

  std::set<std::string> position_set;
  std::set<int> value_set;

  while (std::cin >> open_par >> value >> comma >> position) {
    // Initialize for new processing
    tree_state = TreeState::COMPLETE;
    nodes.clear();
    position_set.clear();
    value_set.clear();

    // Remove ending parenthese
    position = position.substr(0, position.length() - 1);

    // Process the first node
    value_set.emplace(value);
    position_set.emplace(position);
    nodes.emplace_back(std::make_shared<Node>(value, position));

    // Retrieve the rest of nodes in the same sequence
    while (std::cin >> open_par && std::cin.peek() != ')') {
      // Retrieve the node values
      std::cin >> value >> comma >> position;

      // Test the position
      position = position.substr(0, position.length() - 1);
      if (position_set.find(position) != position_set.end()) {
        tree_state = TreeState::INVALID;
        break;
      }

      // Test the value
      if (tree_state == TreeState::COMPLETE &&
          value_set.find(value) != value_set.end()) {
        // Update only once
        tree_state = TreeState::NOT_COMPLETE;
      }

      value_set.emplace(value);
      position_set.emplace(position);
      nodes.emplace_back(std::make_shared<Node>(value, position));
    }

    if (tree_state == TreeState::INVALID) {
      std::cout << "not complete\n";
      continue; // Proceed to next input sequence directly
    }

    // Check for head node
    bool head_found = false;
    for (const auto &n : nodes) {
      if (!head_found && n->getPosition().empty()) {
        head_found = true;
        continue;
      }

      if (head_found && n->getPosition().empty()) {
        tree_state = TreeState::INVALID;
        break;
      }
    }

    if (tree_state == TreeState::INVALID) {
      std::cout << "not complete\n";
      continue; // Proceed to next input sequence directly
    }

    // Check for missing parent positions
    for (const auto &pos : position_set) {
      // Skip first level nodes directly connected to root
      if (pos.length() > 1) {
        parent = pos.substr(0, pos.length() - 1);
        if (position_set.find(parent) == position_set.end()) {
          std::cout << "Missing " << parent << " for " << pos << '\n';
          tree_state = TreeState::INVALID;
          break;
        }
      }
    }

    if (tree_state == TreeState::INVALID) {
      std::cout << "not complete\n";
      continue; // Proceed to next input sequence directly
    }

  return 0;
}
