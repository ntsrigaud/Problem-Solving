// Leetcode #66 - Plus One

#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int carry = 1;
    int sum = 0;

    for (int i = digits.size() - 1; i >= 0; --i) {
      if (carry == 0) {
        break;
      }

      if (carry == 1) {
        sum = (digits.at(i) + carry) % 10;
        carry = (digits.at(i) + carry) / 10;
        digits.at(i) = sum;
      }
    }

    // Prepend the left carry
    if (carry != 0) {
      digits.insert(digits.begin(), carry);
    }

    return digits;
  }
};
