// Leetcode #190 - Reverse Bits

#include <string>

class Solution {
public:
  static constexpr int N_BITS = 32;

  int reverseBits(int n) {
    // Convert to binary && Reverse bits
    std::string bin_value;
    char cur_bit = 0;

    while (n != 0) {
      cur_bit = (n % 2) + '0';
      bin_value += cur_bit; // Added already in reverse order
      n /= 2;
    }

    // Handle missing bits
    auto n_missing_bits = N_BITS - bin_value.size();
    std::string missing_bits(n_missing_bits, '0');
    bin_value += missing_bits;

    // Convert back to decimal
    int result = 0;
    for (int i = bin_value.size() - 1; i >= 0; --i) {
      result += (bin_value.at(i) - '0') * std::pow(2, bin_value.size() - i - 1);
    }

    return result;
  }
};
