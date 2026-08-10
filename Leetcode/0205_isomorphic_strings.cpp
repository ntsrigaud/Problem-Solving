// Leetcode #0205 - Isomorphic Strings

#include <array>
#include <string>
#include <unordered_map>

class Solution {
public:
  static constexpr size_t N_CHAR_ASCII = 256;

  bool isIsomorphic(std::string s, std::string t) {
    // Used for last-seen indices
    std::array<int, N_CHAR_ASCII> map_s{0};
    std::array<int, N_CHAR_ASCII> map_t{0};

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      auto c1 = s.at(i);
      auto c2 = t.at(i);

      // Check if the last time they were seen were at the same index
      if (map_s.at(c1) != map_t.at(c2)) {
        return false;
      }

      map_s.at(c1) = i + 1;
      map_t.at(c2) = i + 1;
    }

    return true;
  }
};
