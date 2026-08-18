// Leetcode #0415: Add Strings

#include <algorithm>
#include <cstddef>
#include <string>

class Solution {
  static constexpr int DEC_BASE = 10;

public:
  std::string addStrings(std::string num1, std::string num2) {
    size_t i = 0;
    int sum = 0;
    int carry = 0;
    std::string res;
    res.reserve(std::max(num1.size(), num2.size()) + 1);

    // Order in terms of length
    std::string min_num = num1;
    std::string max_num = num2;

    if (min_num.length() > max_num.length()) {
      max_num = num1;
      min_num = num2;
    }

    while (i < max_num.size()) {
      if (i < min_num.length()) {
        sum = (max_num[max_num.length() - i - 1] - '0') +
              (min_num[min_num.length() - i - 1] - '0') + carry;

        res += (sum % DEC_BASE) + '0';
        carry = sum / DEC_BASE;
      } else if (carry != 0) {
        sum = (max_num[max_num.length() - i - 1] - '0') + carry;

        res += (sum % DEC_BASE) + '0';
        carry = sum / DEC_BASE;
      } else {
        res += max_num[max_num.length() - i - 1];
      }

      ++i;
    }

    if (carry != 0) {
      res += "1";
    }

    std::ranges::reverse(res.begin(), res.end());
    return res;
  }
};
