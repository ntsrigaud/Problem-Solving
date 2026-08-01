// Leetcode #14 - Longest Common Prefix
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    size_t lastIndex = 0;
    size_t minLen = 200;
    size_t i = 0;
    char curLetter = 0;

    // Get the minimum string length
    std::ranges::for_each(strs, [&](const std::string &str) -> void {
      minLen = std::min(str.size(), minLen);
    });

    std::ranges::sort(
        strs, [](const std::string &str1, const std::string &str2) -> bool {
          return str1 < str2;
        });

    if (minLen == 0) {
      return "";
    }

    while (lastIndex < minLen) {
      curLetter = strs[0][lastIndex]; // All strings should be valid, so use the
                                      // first at template

      // Check each string for current index
      for (i = 1; i < strs.size(); ++i) {
        if (strs.at(i).at(lastIndex) != curLetter) {
          break;
        }
      };

      // At least one did not pass the check
      if (i != strs.size()) {
        if (lastIndex == 0) {
          return "";
        }
        break;
      }

      ++lastIndex;
    }

    // Return substring until lastIndex
    return strs.at(0).substr(0, lastIndex);
  }
};

int main() {
  std::vector<std::vector<std::string>> testCases{
      {"flower", "flow", "flight"},
      {"dog", "racecar", "car"},
      {""},
      {"ab", "a"},
      {"a", "b"},
  };

  Solution sol;
  std::ranges::for_each(testCases, [&](auto &testcase) -> void {
    auto prefix = sol.longestCommonPrefix(testcase);
    std::cout << (prefix.empty()
                      ? "There is no common prefix among the input strings."
                      : prefix)
              << '\n';
  });

  return 0;
}
