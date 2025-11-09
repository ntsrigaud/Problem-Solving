#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <set>
#include <stdexcept>
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

const int INVALID = -1;
const int NOT_COMPLETE = 0;
const int COMPLETE = 1;

const char LEFT = 'L';
const char RIGHT = 'R';

class Node {
public:
  Node(int v, const std::string &pos) : value(v), position(pos) {};

  void setChild(char p, const std::shared_ptr<Node> &n) {
    if (p == LEFT) {
      left = n;
    } else {
      right = n;
    }
  };

  std::shared_ptr<Node> getChild(char p) const {
    return (p == LEFT) ? left : right;
  }

  std::string getPosition() const { return position; };
  int getValue() const { return value; };

private:
  int value;
  std::string position;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
};

class Tree {
public:
  explicit Tree(const std::shared_ptr<Node> &h,
                std::vector<std::shared_ptr<Node>> &nodes)
      : head(h) {
    insertNodes(nodes);
  };

  void levelOrderTraversal() {
    std::queue<std::shared_ptr<Node>> q;

    q.push(head);
    while (!q.empty()) {
      std::cout << q.front()->getValue();

      auto left_child = q.front()->getChild(LEFT);
      auto right_child = q.front()->getChild(RIGHT);
      q.pop();

      if (left_child) {
        q.push(left_child);
      }
      if (right_child) {
        q.push(right_child);
      }

      if (!q.empty()) {
        std::cout << ' ';
      }
    }

    std::cout << '\n';
  };

private:
  std::shared_ptr<Node> head;

  void insertNodes(std::vector<std::shared_ptr<Node>> &nodes) {
    auto comp_nodes = [](const std::shared_ptr<Node> &a,
                         const std::shared_ptr<Node> &b) {
      return a->getPosition() < b->getPosition();
    };
    std::sort(nodes.begin(), nodes.end(), comp_nodes);

    // Remove the head node if present
    if (nodes[0]->getPosition().empty()) {
      nodes.erase(nodes.begin());
    }

    std::shared_ptr<Node> parent;
    std::string node_path;

    for (const auto &n : nodes) {
      parent = head;
      node_path = n->getPosition();

      while (node_path.size() > 1) {
        // Traverse to the node position
        parent = parent->getChild(node_path.front());
        node_path = node_path.substr(1, node_path.length());
      }

      if (parent->getChild(node_path.front()) != nullptr) {
        throw std::runtime_error("Overwriting tree node");
      }

      parent->setChild(node_path.front(), n);
    }
  };
};

int main() {
  char open_par = 0;
  char comma = 0;
  int value = 0;

  int tree_state = INVALID;

  std::string position;
  std::string parent;

  std::vector<std::shared_ptr<Node>> nodes;

  std::shared_ptr<Node> head;

  std::set<std::string> position_set;
  std::set<int> value_set;

  while (std::cin >> open_par >> value >> comma >> position) {
    // Initialize for new processing
    tree_state = COMPLETE;
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
        tree_state = INVALID;
        break;
      }

      // Test the value
      if (tree_state == COMPLETE && value_set.find(value) != value_set.end()) {
        // Update only once
        tree_state = NOT_COMPLETE;
      }

      value_set.emplace(value);
      position_set.emplace(position);
      nodes.emplace_back(std::make_shared<Node>(value, position));
    }

    // Remove last ')'
    std::cin.ignore();

    if (tree_state == INVALID) {
      std::cout << "not complete\n";
      continue; // Proceed to next input sequence directly
    }

    // Check for head node
    bool head_found = false;
    for (const auto &n : nodes) {
      if (!head_found && n->getPosition().empty()) {
        head_found = true;
        head = n;
        continue;
      }

      if (head_found && n->getPosition().empty()) {
        tree_state = INVALID;
        break;
      }
    }

    if (tree_state == INVALID) {
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
          tree_state = INVALID;
          break;
        }
      }
    }

    if (tree_state == INVALID) {
      std::cout << "not complete\n";
      continue; // Proceed to next input sequence directly
    }

    // Tree display
    Tree bin_tree(head, nodes);
    bin_tree.levelOrderTraversal();

    // Display level order traversal
    if (tree_state == NOT_COMPLETE) {
      std::cout << "not complete\n";
    }
  }

  return 0;
}
