// Leetcode #0258 - Add Digits

class Solution {
  static constexpr int MAGIC_NUMBER = 9;

public:
  int addDigits(int num) {
    // Find digital root using Congruence Modulo 9
    if (num == 0) {
      return 0;
    }

    return 1 + ((num - 1) % MAGIC_NUMBER);
  }
};
