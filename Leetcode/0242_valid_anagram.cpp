// Leetcode #0242 - Valid Anagram

#include <array>
#include <string>

class Solution {
  static constexpr int N_CHARS = 256;

public:
  bool isAnagram(std::string s, std::string t) {
    std::array<int, N_CHARS> record{0};

    for (char ch : s) {
      ++record.at(ch);
    }

    for (char ch : t) {
      if (record.at(ch) <= 0) {
        return false;
      }

      --record.at(ch);
    }

    // Check for leftovers
    for (const auto count : record) {
      if (count != 0) {
        return false;
      }
    }

    return true;
  }
};
