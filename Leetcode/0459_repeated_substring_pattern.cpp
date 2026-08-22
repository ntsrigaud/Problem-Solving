// Leetcode #0459: Repeated Substring Pattern

#include <cstddef>
#include <string>
#include <string_view>

class Solution {
public:
  bool repeatedSubstringPattern(std::string s) {
    if (s.length() == 1) {
      return false; // Singe letter strings cannot have substrings
    }

    std::string_view s_view = s;

    auto canRecreateString = [&](const std::string_view &subs) -> bool {
      if (s.length() % subs.length() != 0) {
        return false;
      }

      // Parse the original string matching the pattern once
      auto subs_len = subs.length();
      for (size_t i = subs_len; i < s.length(); i += subs_len) {
        if (s_view.substr(i, subs_len) != subs) {
          return false;
        }
      }

      return true;
    };

    // Try from the largest substring
    auto mid = s.size() / 2;
    for (size_t i = mid; i > 0; --i) {
      if (s.length() % i == 0 && canRecreateString(s_view.substr(0, i))) {
        return true;
      }
    }

    return false;
  }
};
