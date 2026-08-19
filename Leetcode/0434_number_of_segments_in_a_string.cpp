// Leetcode #0434: Number of Segments in a String

#include <sstream>
#include <string>

class Solution {
public:
  int countSegments(string s) {
    std::stringstream ss(s);
    std::string word;
    int count = 0;

    while (ss >> word) {
      ++count;
    }

    return count;
  }
};
