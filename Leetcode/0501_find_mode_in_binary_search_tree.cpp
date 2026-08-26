// Leetcode #0501: Find Mode in Binary Search Tree

#include <climits>
#include <vector>

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
  struct TravValues {
    TreeNode *prev = nullptr;
    int cur_count = 0;
    int max_count = INT_MIN;
  };

  void inorder(TreeNode *node, std::vector<int> &res, TravValues &tv) {
    if (node == nullptr) {
      return;
    }

    inorder(node->left, res, tv);

    // Update frequency counts
    if (tv.prev != nullptr && tv.prev->val == node->val) {
      ++tv.cur_count;
    } else {
      tv.cur_count = 1;
    }

    // Update the list based on the frequency
    if (tv.cur_count == tv.max_count) {
      res.push_back(node->val);
    } else if (tv.cur_count > tv.max_count) {
      tv.max_count = tv.cur_count;
      res.clear();
      res.push_back(node->val);
    }

    tv.prev = node;

    inorder(node->right, res, tv);
  };

public:
  std::vector<int> findMode(TreeNode *root) {
    std::vector<int> res;
    TravValues tv;

    // Inorder traversal to collect frequencies for BST
    inorder(root, res, tv);

    return res;
  }
};
