// Leetcode #3 - Longest Substring Without Repeating Characters
#include <iostream>
#include <set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    size_t i = 0;
    size_t maxLen = 0;
    std::set<int> record; // Track the duplicates

    for (size_t k = 0; k < s.length(); ++k) {
      // Sliding window
      if (record.contains(s[k])) {
        maxLen = (record.size() > maxLen) ? record.size() : maxLen;
        // Overwrite all until new lower bound
        while (s[i] != s[k]) {
          record.erase(s[i++]);
        }

        // Overwrite previous duplicate
        ++i;
      } else {
        record.insert(s[k]);
      }
    }

    // Edge case: Single letter strings
    maxLen = (record.size() > maxLen) ? record.size() : maxLen;

    return static_cast<int>(maxLen);
  }
};

int main() {
  Solution sol;
  std::string s = "pwwkew";

  std::cout << s << " -> " << sol.lengthOfLongestSubstring(s) << '\n';

  return 0;
}
