// Leetcode #0414: Third Maximum Number

#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

class Solution {
public:
  int thirdMax(std::vector<int> &nums) {
    std::vector<int64_t> max(3, std::numeric_limits<int64_t>::min());

    for (int n : nums) {
      if (n == max[0] || n == max[1] || n == max[2]) {
        continue;
      }

      if (n > max[0]) {
        max[2] = max[1];
        max[1] = max[0];
        max[0] = n;
      } else if (n > max[1]) {
        max[2] = max[1];
        max[1] = n;
      } else if (n > max[2]) {
        max[2] = n;
      }
    }

    if (max[2] == std::numeric_limits<int64_t>::min()) {
      return max[0];
    }

    return max[2];
  }
};
