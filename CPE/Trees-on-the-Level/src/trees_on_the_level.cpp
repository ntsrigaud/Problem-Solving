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
 * 1) Retrieve and save input nodes:
 *    - Parse the first node input from a sequence until no input is found
 *    - Save the first node
 *    - Parse the rest of the sequence until "()"
 *      - Use a set to track node duplicate positions
 *        -> Tree is not completely specified.
 *        -> Display "not complete\n"
 *      - Check if all required tree positions are filled.
 *        - Apart from HEAD, all children must have a parent.
 *      - Display the levelOrderTraversal if tree is VALID and contains all
 * parents.
 *        -> Sort the list in ascending order by their positions
 *        -> Display the values of each node.
 *        * Since the level order starts from LEFT to RIGHT and the sorted node
 * list correspond to that order, we obtain the correct sequence just by sorting
 * the list.
 *
 * Solution reference:
 * https://github.com/Diusrex/UVA-Solutions/blob/master/122%20Trees%20on%20the%20level.cpp
 * */

const std::string HEAD = "H";

struct Node {
  long long value = 0;
  std::string position;

  // Overload to allow sorting
  bool operator<(const Node &other) const {
    return (position.size() == other.position.size())
               ? position < other.position
               : position.size() < other.position.size();
  }
};

bool containsAllPositions(const std::set<std::string> &positions)
// Check if all binary tree positions are available
{

  if (positions.find(HEAD) == positions.end()) {
    return false;
  }

  for (const auto &p : positions) {
    if (p.size() == 1) {
      continue;
    }

    if (positions.find(p.substr(0, p.size() - 1)) == positions.end()) {
      return false;
    }
  }

  return true;
}

int main() {
  bool valid = false;
  char comma = 0;
  char op_par = 0;
  long long value = 0;
  std::string position;
  std::string p;
  std::set<std::string> positions;
  std::vector<Node> nodes;

  while (std::cin >> op_par >> value >> comma >> position) {
    valid = true;
    nodes.clear();
    positions.clear();

    position =
        position.substr(0, position.size() - 1); // remove closing parenthese

    // Get the first node data
    nodes.emplace_back(Node{value, position});
    positions.insert(position.empty() ? HEAD : position);

    // Parse the rest of inputs until ()
    while (std::cin >> op_par, std::cin.peek() != ')') {
      // Get the input
      std::cin >> value >> comma >> position;
      position = position.substr(0, position.size() - 1);

      p = (position.empty()) ? HEAD
                             : position; // Allow check for multiple HEAD nodes

      // Check for duplicate positions
      if (valid && positions.find(p) != positions.end()) {
        valid = false;
      }
      positions.insert(p);

      nodes.emplace_back(Node{value, position});
    }

    std::cin.ignore(); // Last parenthese from "()"

    if (valid && containsAllPositions(positions)) {
      std::sort(nodes.begin(), nodes.end());

      // Level Order Traversal
      for (size_t i = 0; i < nodes.size(); ++i) {
        std::cout << nodes[i].value;
        if (i + 1 < nodes.size()) {
          std::cout << ' ';
        }
      }
      std::cout << '\n';
    } else {
      std::cout << "not complete\n";
    }
  }

  return 0;
}
