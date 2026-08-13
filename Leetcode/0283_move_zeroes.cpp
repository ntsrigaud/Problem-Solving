// Leetcode #0283 - Move Zeroes

#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    // Two-pointers algorithm
    int left = 0;
    int right = 1;
    int nums_size = static_cast<int>(nums.size());

    // Find the first 0
    for (left = 0; left < nums_size && nums.at(left) != 0; ++left) {
    };
    right = left + 1;

    while (right < nums_size) {
      if (nums.at(right) != 0) {
        nums.at(left) = nums.at(right);
        nums.at(right) = 0;
        ++left;
      }

      ++right;
    }
  }
};
