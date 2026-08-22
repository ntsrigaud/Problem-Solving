// Leetcode 0461: Hamming Distance

#include <cstddef>

class Solution {
public:
  int hammingDistance(int x, int y) {
    if (x == y) {
      return 0;
    }

    int distance = 0;
    int diff = x ^ y; // Assuming that they will all be >= 0

    while (diff > 0) {
      distance += diff % 2;
      diff /= 2;
    }

    return distance;
  }
};
