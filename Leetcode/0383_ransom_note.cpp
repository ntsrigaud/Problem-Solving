// Leetcode #0383: Ransom Note

#include <string>
#include <unordered_map>

class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> record;

    // Record the magazine letters
    for (char c : magazine) {
      ++record[c];
    }

    for (char c : ransomNote) {
      --record[c];
      if (record[c] < 0) {
        return false;
      }
    }

    return true;
  }
};
