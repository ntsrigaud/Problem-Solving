// Leetcode #168 - Excel Sheet Column Title

#include <string>

class Solution {
public:
  static constexpr int ALPHA_BASE = 26;

  std::string convertToTitle(int columnNumber) {
    // Remove 1 and Convert to base 26
    std::string res;

    while (columnNumber > 0) {
      --columnNumber;
      char conv_digit = (columnNumber % ALPHA_BASE) + 'A';
      res = conv_digit + res;
      columnNumber /= ALPHA_BASE;
    }

    return res;
  }
};
