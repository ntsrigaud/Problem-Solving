// Leetcode #108 - Convert Sorted Array to Binary Search Tree -> NOT OPTIMAL

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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0) {
      return nullptr;
    };
    if (nums.size() == 1) {
      return new TreeNode(nums.at(0));
    };

    // Break the array and recursively pick the median as root
    auto median = nums.size() / 2;
    auto *root = new TreeNode(nums.at(median));

    std::vector<int> left(nums.begin(), nums.begin() + median);
    std::vector<int> right(nums.begin() + median + 1, nums.end());

    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);

    return root;
  }
};
