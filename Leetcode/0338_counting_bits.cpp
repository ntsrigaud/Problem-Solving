// Leetcode #0338: Counting Bits

#include <vector>

class Solution {
public:
  std::vector<int> countBits(int n) {
    std::vector<int> arr_bits;

    auto countSingleNumberBits = [](int i) {
      int n_bits = 0;

      while (i > 0) {
        n_bits += i % 2 == 1;
        i /= 2;
      }

      return n_bits;
    };

    for (int i = 0; i <= n; ++i) {
      arr_bits.push_back(countSingleNumberBits(i));
    }

    return arr_bits;
  }
};
