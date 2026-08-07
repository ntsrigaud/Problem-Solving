// Leetcode #108 - Convert Sorted Array to Binary Search Tree

#include <algorithm>
#include <iterator>
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
  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    return sortedArrayToBST(nums, 0, static_cast<int>(nums.size() - 1));
  }

  TreeNode *sortedArrayToBST(std::vector<int> &nums, int left, int right) {
    // Break the array and recursively pick the median as root
    if (left > right || right < left) {
      return nullptr;
    };

    if (left == right) {
      return new TreeNode(nums.at(left));
    };

    int median = left + ((right - left) / 2);
    auto *root = new TreeNode(nums.at(median));

    root->left = sortedArrayToBST(nums, left, median - 1);
    root->right = sortedArrayToBST(nums, median + 1, right);

    return root;
  };
};
