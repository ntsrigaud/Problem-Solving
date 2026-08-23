// Leetcode #0476: Number Complement

#include <algorithm>
#include <string>

class Solution {
public:
  int findComplement(int num) {
    auto getComp = [](int n) -> std::string {
      std::string bin_comp;
      int v;

      while (n > 0) {
        v = n % 2;
        bin_comp += (v == 1) ? '0' : '1';
        n /= 2;
      }

      std::ranges::reverse(bin_comp.begin(), bin_comp.end());

      return bin_comp;
    };

    auto toInt = [](const std::string &bin_comp) -> int {
      size_t len = bin_comp.length();
      int sum = 0;

      for (size_t i = 0; i < len; ++i) {
        if (bin_comp[i] == '1') {
          sum += static_cast<int>(std::pow(2, len - i - 1));
        }
      }

      return sum;
    };

    return toInt(getComp(num));
  }
};
