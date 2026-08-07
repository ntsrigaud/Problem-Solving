// Leetcode #94 - Binary Tree Inorder Traversal

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
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    };

    if (root->left == nullptr && root->right == nullptr) {
      return {root->val};
    }

    std::vector<int> res;

    // Record left subtree
    if (root->left != nullptr) {
      res = inorderTraversal(root->left);
    }

    // Record root node
    res.push_back(root->val);

    // Record right subtree
    if (root->right != nullptr) {
      auto res_right = inorderTraversal(root->right);
      res.insert(res.end(), res_right.begin(), res_right.end());
    }

    return res;
  }
};
