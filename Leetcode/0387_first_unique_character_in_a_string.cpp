// Leetcode #0387: First Unique Character in a String

#include <array>
#include <climits>
#include <string>

class Solution {
  static constexpr int N_CHARS = 256;
  static constexpr int UNSEEN = 0;
  static constexpr int INVALID = -1;

public:
  int firstUniqChar(std::string s) {
    char cur_letter = 0;
    int i = 0;
    int s_len = static_cast<int>(s.length());
    int last_seen_index = 0;
    int min_index = INT_MAX;
    std::array<int, N_CHARS + 1> last_seen{0};

    for (i = 0; i < s_len; ++i) {
      cur_letter = s.at(i);
      last_seen_index = last_seen.at(cur_letter);

      if (last_seen_index == UNSEEN) {
        last_seen.at(cur_letter) = i + 1;
      } else if (last_seen_index > UNSEEN) {
        // Seen a second time
        last_seen.at(cur_letter) = INVALID;
      }
    }

    // Find the minimum valid index
    for (i = 0; i <= N_CHARS; ++i) {
      last_seen_index = last_seen.at(i);

      if (last_seen_index > UNSEEN) {
        min_index = std::min(min_index, last_seen_index);
      }
    }

    return (min_index == INT_MAX) ? INVALID : min_index - 1;
  }
};
