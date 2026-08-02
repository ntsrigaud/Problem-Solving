// Leetcode 28 - Find the Index of the First Occurrence in a String

#include <string>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    size_t i = 0;

    for (i = 0; i < haystack.size(); ++i) {
      if (haystack.size() - i >= needle.size()) {
        if (haystack.substr(i, needle.size()) == needle) {
          return static_cast<int>(i);
        }
      }
    }

    return -1;
  }
};
