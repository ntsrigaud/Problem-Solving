// Leetcode #191 - Number of 1 Bits

class Solution {
public:
  int hammingWeight(int n) {
    // Convert to binary while counting the ones
    int one_count = 0;
    while (n != 0) {
      one_count += (n % 2);
      n /= 2;
    }

    return one_count;
  }
};
