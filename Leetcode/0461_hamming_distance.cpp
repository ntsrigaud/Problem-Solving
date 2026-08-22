// Leetcode 0461: Hamming Distance

#include <algorithm>
#include <cstddef>
#include <string>

class Solution {
public:
  int hammingDistance(int x, int y) {
    if (x == y) {
      return 0;
    }

    int distance = 0;

    auto toBin = [](int n) -> std::string {
      std::string res;

      while (n > 0) {
        res += static_cast<char>((n % 2) + '0');
        n /= 2;
      }

      std::ranges::reverse(res.begin(), res.end());
      return res;
    };

    auto x_bin = toBin(x);
    auto y_bin = toBin(y);

    size_t pad_len =
        std::abs(static_cast<int>(x_bin.length() - y_bin.length()));

    if (pad_len > 0) {
      std::string pad(pad_len, '0');

      if (x_bin.length() < y_bin.length()) {
        x_bin = pad + x_bin;
      } else {
        y_bin = pad + y_bin;
      }
    }

    for (size_t i = 0; i < x_bin.length(); ++i) {
      if (x_bin[i] != y_bin[i]) {
        ++distance;
      }
    }

    return distance;
  }
};
