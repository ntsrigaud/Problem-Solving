// Leetcode #3 - Longest Substring Without Repeating Characters
#include <iostream>
#include <vector>

constexpr size_t N_CHAR = 256;

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int left = 0;
    int maxLen = 0;
    int k = 0;
    std::vector<int> lastSeenPos(N_CHAR,
                                 -1); // Track last position of each character

    for (k = 0; k < s.length(); ++k) {
      // Sliding window
      if (lastSeenPos[s[k]] >= left) {
        maxLen = (k - left > maxLen) ? k - left : maxLen;

        // Directly jump to the next position after last seen position
        // inside current window
        left = lastSeenPos[s[k]] + 1;
      }

      lastSeenPos[s[k]] = k;
    }

    // Edge case: Single letter strings
    maxLen = (k - left > maxLen) ? k - left : maxLen;

    return maxLen;
  }
};

int main() {
  Solution sol;
  std::string s = "ccbbcc";

  std::cout << s << " -> " << sol.lengthOfLongestSubstring(s) << '\n';

  return 0;
}
