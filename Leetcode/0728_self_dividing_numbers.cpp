// Leetcode #0728: Self Dividing Numbers

#include <vector>

class Solution {
public:
  std::vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> nums;

    auto isSelfDividing = [](int n) -> bool {
      int digit = 0;
      int tmp_n = n;

      while (tmp_n > 0) {
        digit = tmp_n % 10;
        if (digit == 0 || n % digit != 0) {
          return false;
        }

        tmp_n /= 10;
      }

      return true;
    };

    for (int n = left; n <= right; ++n) {
      if (isSelfDividing(n)) {
        nums.push_back(n);
      }
    }

    return nums;
  }
};
