#include <algorithm>
#include <iostream>
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

enum class TreeState { INVALID, NOT_COMPLETE, COMPLETE };

struct Node {
  int value;
  std::string position;

  void print_node() const {
    std::cout << '(' << value << ", " << position << ')';
  };
};

int main() {
  char open_par;
  char comma;
  int value;

  TreeState tree_state;

  std::string position;
  std::string parent;

  std::vector<Node> nodes;

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
    nodes.push_back({value, position});

    // Retrieve the rest of nodes in the same sequence
    while (std::cin >> open_par && std::cin.peek() != ')') {
      // Retrieve the node values
      std::cin >> value >> comma >> position;

      nodes.push_back({value, position.substr(0, position.length() - 1)});
    }

  return 0;
}
