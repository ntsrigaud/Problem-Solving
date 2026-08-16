// Leetcode #0345: Reverse Vowels of a String

#include <cctype>
#include <string>

class Solution {
public:
  std::string reverseVowels(std::string s) {
    int left = 0;
    int right = static_cast<int>(s.size() - 1);

    auto isVowel = [](char c) -> bool {
      c = tolower(c);
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    while (left < right) {
      // Fing left vowel first
      while (left < right && !isVowel(s[left])) {
        ++left;
      }

      // Find the right vowel to swap if any
      while (left < right && !isVowel(s[right])) {
        --right;
      }

      // Swap and move inward if both are found
      if (left < right) {
        std::swap(s[left], s[right]);
        ++left;
        --right;
      }
    }

    return s;
  }
};
