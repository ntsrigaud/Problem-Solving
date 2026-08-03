// Leetcode #70 - Climbing Stairs

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    };

    int step_one = 1;
    int step_two = 1;
    int tmp = 0;

    while (n >= 2) {
      tmp = step_two;
      step_two = step_one;
      step_one = step_one + tmp;
      --n;
    }

    return step_one;
  }
};
