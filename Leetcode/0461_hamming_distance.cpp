// Leetcode 0461: Hamming Distance

#include <bit>

class Solution {
public:
  int hammingDistance(int x, int y) {
    return (x == y) ? 0
                    : std::popcount(static_cast<unsigned int>(x) ^
                                    static_cast<unsigned int>(y));
  }
};
