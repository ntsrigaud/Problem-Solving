// Leetcode #0228 - Summary Ranges

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> summaryRanges(std::vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }

    std::vector<std::string> rangeSummaries;
    int left = 0;
    int right = 1;

    auto addSummary = [&](int first, int second) -> void {
      if (first == second) {
        rangeSummaries.push_back(std::to_string(first));
      } else {
        rangeSummaries.push_back(std::to_string(first) + "->" +
                                 std::to_string(second));
      }
    };

    while (right < nums.size()) {
      if (nums.at(right - 1) + 1 != nums.at(right)) {
        addSummary(nums.at(left), nums.at(right - 1));
        left = right;
      }

      ++right;
    }

    addSummary(nums.at(left), nums.at(right - 1));

    return rangeSummaries;
  }
};
