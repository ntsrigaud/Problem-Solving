// Leetcode #168 - Majority Element

#include <unordered_map>
#include <vector>

class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    std::unordered_map<int, int> num_count;
    int majority_element = nums.front();
    num_count[majority_element] = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
      ++num_count[nums.at(i)];
      if (nums.at(i) != majority_element &&
          num_count[nums.at(i)] > num_count[majority_element]) {
        majority_element = nums.at(i);
      }
    }

    return majority_element;
  }
};
