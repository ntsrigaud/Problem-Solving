// Leetcode #0389 - Find the Difference

#include <cstddef>
#include <string>
#include <unordered_map>

class Solution {
public:
  char findTheDifference(std::string s, std::string t) {
    if (s.empty()) {
      return t.front();
    }

    size_t i = 0;
    std::unordered_map<char, int> record;

    // Map out all original chars
    for (char c : s) {
      ++record[c];
    }

    for (char c : t) {
      --record[c];
      if (record.at(c) < 0) {
        return c;
      }
    }

    return 0;
  }
};
