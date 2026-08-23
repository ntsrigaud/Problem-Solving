// Leetcode #0482: License Key Formatting

#include <cctype>
#include <string>

class Solution {
  static constexpr char SEP = '-';

public:
  std::string licenseKeyFormatting(std::string s, int k) {
    auto k_len = static_cast<size_t>(k);
    auto s_len = s.length();
    size_t group_count = 0;
    int i = static_cast<int>(
        s_len - 1); // Start at the end since first group can be shorter
    std::string formatted_license;

    auto toUpper = [](char c) -> char {
      return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    };

    // Start grouping from the end
    for (; i >= 0; --i) {
      if (std::isalnum(s[i]) != 0) {
        if (group_count == 0 && !formatted_license.empty()) {
          formatted_license += SEP;
        }

        formatted_license += toUpper(s[i]);
        group_count = (group_count + 1) % k_len;
      }
    }

    std::ranges::reverse(formatted_license.begin(), formatted_license.end());

    return formatted_license;
  }
};
