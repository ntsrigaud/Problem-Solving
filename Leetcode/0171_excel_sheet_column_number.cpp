// Leetcode #171 - Excel Sheet Column Number

#include <string>

class Solution {
public:
  static constexpr int BASE = 26;

  int titleToNumber(std::string columnTitle) {
    int res = 0;

    for (char c : columnTitle) {
      res = (res * BASE) + (c - 'A') + 1;
    }

    return res;
  }
};
