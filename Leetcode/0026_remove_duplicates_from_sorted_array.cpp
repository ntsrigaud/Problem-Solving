// Leetcode #26 - Remove Duplicates from Sorted Array

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() == 1) {
      return 1;
    }

    size_t left = 0;
    size_t right = 0;

    // Find the first duplicate position to overwrite
    for (left = 1; left < nums.size(); ++left) {
      if (nums.at(left) == nums.at(left - 1)) {
        right = left + 1;
        break;
      }
    }

    while (right < nums.size() && left < nums.size()) {
      // Found a new number
      if (nums.at(right) != nums.at(right - 1)) {
        nums.at(left) = nums.at(right);
        ++left;
      }

      ++right;
    }

    return static_cast<int>(left);
  }
};

int main() {
  std::vector<std::vector<int>> testcases = {
      {1},
      {1, 2},
      {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
  };

  Solution sol;
  int k = 0;

  auto printResult = [](const std::vector<int> &nums, int k) -> void {
    for (size_t i = 0; i < k && i < nums.size(); ++i) {
      std::cout << nums.at(i) << ", ";
    }
    std::cout << '\n';
  };

  for (auto &testcase : testcases) {
    k = sol.removeDuplicates(testcase);
    std::cout << k << " -> ";
    printResult(testcase, k);
  }

  return 0;
}
