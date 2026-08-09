// Leetcode #136 - Single Number

#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    int single_number = nums.front();
    for (size_t i = 1; i < nums.size(); ++i) {
      single_number = single_number ^ nums.at(i);
    }

    return single_number;
  }
};
