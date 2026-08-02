// Leetcode 27 - Remove Element

#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    if (nums.size() == 0) {
      return 0;
    };

    size_t left = 0;
    size_t right = 0;

    // Find first value to overwrite
    for (left = 0; left < nums.size(); ++left) {
      if (nums.at(left) == val) {
        right = left + 1;
        break;
      }
    }

    // Start overwriting
    while (left < nums.size() && right < nums.size()) {
      if (nums.at(right) != val) {
        nums.at(left) = nums.at(right);
        ++left;
      }

      ++right;
    }

    return static_cast<int>(left);
  }
};
