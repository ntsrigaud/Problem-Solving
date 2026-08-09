// Leetcode #144 - Binary Tree Preorder Traversal

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
  std::vector<int> preorderTraversal(TreeNode *root) {
    // Preorder -> Root, Left, Right
    if (root == nullptr) {
      return {};
    };
    if (root->left == nullptr && root->right == nullptr) {
      return {root->val};
    };

    auto res_left = preorderTraversal(root->left);
    auto res_right = preorderTraversal(root->right);

    std::vector<int> full_result;
    full_result.reserve(res_left.size() + res_right.size() + 1);

    full_result.push_back(root->val);
    full_result.insert(full_result.end(), res_left.begin(), res_left.end());
    full_result.insert(full_result.end(), res_right.begin(), res_right.end());

    return full_result;
  }
};
