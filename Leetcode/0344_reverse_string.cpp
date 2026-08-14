// Leetcode #0344: Reverse String

#include <vector>

class Solution {
public:
  void reverseString(std::vector<char> &s) {
    size_t median = s.size() / 2;

    auto swapChars = [](char &first, char &second) -> void {
      char tmp = first;
      first = second;
      second = tmp;
    };

    for (size_t i = 0; i < median; ++i) {
      swapChars(s.at(i), s.at(s.size() - i - 1));
    }
  }
};
