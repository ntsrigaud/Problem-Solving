// Leetcode #0441: Arranging Coins

#include <cmath>

class Solution {
public:
  int arrangeCoins(int n) {
    int k = 0;

    // Total coins = k(k + 1) / 2 -> (-b + 4ac) / 2a
    k = (-1 +
         static_cast<int>(std::sqrt(1 + (8 * static_cast<long long>(n))))) /
        2;

    return k < 0 ? 0 : k;
  }
};
