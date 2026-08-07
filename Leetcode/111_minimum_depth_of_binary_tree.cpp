// Leetcode #111 - Minimum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 */
#include <algorithm>
#include <cstddef>
#include <queue>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    };

    // Using BFS insted of DFS for avoiding redundant depth recursions
    std::queue<TreeNode *> q;
    int minLevel = 1;

    auto isLeafNode = [](TreeNode *node) -> bool {
      return node->left == nullptr && node->right == nullptr;
    };

    // Stop when first leaf node is found
    q.push(root);
    while (!q.empty()) {
      size_t levelSize = q.size();

      // Check for leaf node in the current level
      for (size_t i = 0; i < levelSize; ++i) {
        auto *qFront = q.front();
        q.pop();

        if (isLeafNode(qFront)) {
          return minLevel;
        }

        if (qFront->left != nullptr) {
          q.push(qFront->left);
        };
        if (qFront->right != nullptr) {
          q.push(qFront->right);
        };
      }

      ++minLevel;
    }

    return minLevel;
  }
};
