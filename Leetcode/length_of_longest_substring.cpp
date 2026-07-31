// Leetcode #3 - Longest Substring Without Repeating Characters
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, size_t> record;
    size_t maxLen = 0;

    auto nextLongest = [&](size_t i) -> size_t {
      size_t lastCount = 0;
      record.clear();

      while (i < s.length() && !record.contains(s[i])) {
        ++lastCount;
        record[s[i]] = 1;
        ++i;
      }

      return lastCount;
    };

    for (size_t i = 0; i < s.length(); ++i) {
      // Find the longest for each position
      auto lastCount = nextLongest(i);
      maxLen = (lastCount > maxLen) ? lastCount : maxLen;
    }

    return static_cast<int>(maxLen);
  }
};

int main() {
  Solution sol;
  std::string s = "abcabcbb";

  std::cout << s << " -> " << sol.lengthOfLongestSubstring(s) << '\n';

  return 0;
}
