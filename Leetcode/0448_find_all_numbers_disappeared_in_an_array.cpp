// Leetcode #0448: Find all Numbers Disappeared in an Array

#include <vector>

class Solution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
    std::vector<int> disap_nums;

    for (int i = 0; i < nums.size(); ++i) {
      int index = std::abs(nums[i]) - 1;
      if (nums[index] > 0) {
        nums[index] = -nums[index];
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        disap_nums.push_back(i + 1);
      }
    }

    return disap_nums;
  }
};
