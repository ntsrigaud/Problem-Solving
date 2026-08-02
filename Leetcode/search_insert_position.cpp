// Leetcode 35 - Search Insert Position

#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    size_t i = 0;

    for (i = 0; i < nums.size(); ++i) {
      if (nums.at(i) >= target) {
        return static_cast<int>(i);
      }
    }

    return static_cast<int>(nums.size());
  }
};
