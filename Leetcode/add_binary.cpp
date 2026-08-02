// Leetcode #67 - Add Binary

#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    int maxLen =
        std::max(static_cast<int>(a.length()), static_cast<int>(b.length()));
    int carry = 0;
    int sum = 0;
    int i = maxLen - 1;
    std::string result;

    // Make them same size if necessary
    if (a.length() < maxLen) {
      a = std::string(maxLen - a.length(), '0') + a;
    }
    if (b.length() < maxLen) {
      b = std::string(maxLen - b.length(), '0') + b;
    }

    auto bin2Digit = [](char bin) -> int { return bin - '0'; };

    auto addBinDigits = [&](char x, char y) -> std::string {
      sum = (bin2Digit(x) + bin2Digit(y) + carry);
      carry = sum / 2;
      return std::to_string((sum % 2) + '0');
    };

    while (i >= 0) {
      result.insert(0, addBinDigits(a.at(i), b.at(i)));
      --i;
    }

    if (carry != 0) {
      result.insert(0, std::to_string(carry + '0'));
    }

    return result;
  }
};
