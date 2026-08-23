// Leetcode #0485: Max Consecutive Ones

#include <vector>

class Solution {
public:
  int findMaxConsecutiveOnes(std::vector<int> &nums) {
    int max_conseq_ones = 0;
    int count = 0;

    for (int n : nums) {
      if (n == 1) {
        ++count;
      } else {
        max_conseq_ones = std::max(count, max_conseq_ones);
        count = 0;
      }
    }

    return std::max(count, max_conseq_ones);
  }
};
