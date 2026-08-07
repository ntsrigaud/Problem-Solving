// Leetcode 58 - Length of Last Word

#include <string>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    std::string lastWord;
    int i = 0; // Using size_t causes underflow at end of the loop

    for (i = static_cast<int>(s.length() - 1); i >= 0; --i) {
      if (s.at(i) == ' ' && lastWord.length() != 0) {
        break; // Were already recording
      }

      if (s.at(i) != ' ') {
        lastWord += s.at(i); // The order doesn't matter
      }
    }

    return static_cast<int>(lastWord.length());
  }
};
