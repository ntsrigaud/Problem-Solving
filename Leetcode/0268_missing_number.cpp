// Leetcode #0268 - Missing Number

#include <algorithm>
#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    std::ranges::sort(
        nums, [](int first, int second) -> bool { return first <= second; });

    if (nums.front() != 0) {
      return 0;
    }

    if (nums.back() == static_cast<int>(nums.size())) {
      for (size_t i = 1; i < nums.size(); ++i) {
        if (nums.at(i) - nums.at(i - 1) != 1) {
          return nums.at(i - 1) + 1;
        }
      }
    }

    return nums.back() + 1;
  }
};
