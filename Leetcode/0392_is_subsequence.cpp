// Leetcode #0392 - Is Subsequence

#include <string>

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    // Two-pointers algorithm
    size_t left = 0;
    size_t right = 0;
    char l_letter = 0;
    char r_letter = 0;

    while (left < s.length() && right < t.length()) {
      l_letter = s.at(left);
      r_letter = t.at(right);

      if (l_letter == r_letter) {
        ++left;
      }

      ++right;
    }

    return left == s.length();
  }
};
