// Leetcode #0257 - Binary Tree Paths

#include <string>
#include <vector>

/**
 * Definition for a binary tree node.
 */
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
  void helper(TreeNode *node, std::string progress,
              std::vector<std::string> &result) {
    if (node == nullptr) {
      result.push_back(progress);
    }

    auto new_progress =
        (progress.empty() ? "" : progress + "->") + std::to_string(node->val);

    // Leaf node
    if (node->left == nullptr && node->right == nullptr) {
      result.push_back(new_progress);
    }

    if (node->left != nullptr) {
      helper(node->left, new_progress, result);
    }

    if (node->right != nullptr) {
      helper(node->right, new_progress, result);
    }
  }

public:
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    if (root->left == nullptr && root->right == nullptr) {
      return {std::to_string(root->val)};
    };

    std::vector<std::string> result;
    helper(root, "", result);

    return result;
  }
};
