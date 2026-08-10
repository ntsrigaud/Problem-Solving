// Leetcode #202 - Happy Number

class Solution {
public:
  static constexpr int BASE = 10;

  bool isHappy(int n) {
    auto digitsSquaresSum = [](int num) -> int {
      int res = 0;
      while (num != 0) {
        int digit = num % BASE;
        res += digit * digit;
        num /= BASE;
      }

      return res;
    };

    int next = digitsSquaresSum(n);
    while (next != 1 && next != 4) {
      next = digitsSquaresSum(next);
    }

    return next == 1;
  }
};
