// Leetcode #0367: Valid Perfect Square

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 1) {
      return 1;
    }

    for (long i = 0; i < num; ++i) {
      if (i * i == num) {
        return true;
      } else if (i * i > num) {
        return false;
      }
    }
    return false;
  }
};
