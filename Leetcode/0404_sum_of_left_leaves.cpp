// Leetcode #0404: Sum of Left Leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right)
 *       : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  static bool isLeafNode(TreeNode *node) {
    return node != nullptr && node->left == nullptr && node->right == nullptr;
  }

public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int sum = 0;

    if (isLeafNode(root->left)) {
      sum += root->left->val;
    } else {
      sum += sumOfLeftLeaves(root->left);
    }

    return sum + sumOfLeftLeaves(root->right);
  }
};
