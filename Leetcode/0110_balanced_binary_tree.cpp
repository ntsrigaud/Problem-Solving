// Leetcode #110 - Balanced Binary Tree

#include <algorithm>

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
public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    };

    if (!isBalanced(root->left) || !isBalanced(root->right)) {
      return false;
    }

    auto h_left = height(root->left);
    auto h_right = height(root->right);

    return (std::abs(h_left - h_right) <= 1);
  }

  int height(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    };
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    };

    return std::max(height(root->left), height(root->right)) + 1;
  };
};
