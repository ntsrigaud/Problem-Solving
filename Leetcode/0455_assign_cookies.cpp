// Leetcode #0455: Assign Cookies

#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
public:
  int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
    std::ranges::sort(g);
    std::ranges::sort(s);

    if (s.empty() || g.front() > s.back()) {
      return 0;
    }

    size_t nextValidCookie = 0;
    int maxContentChildren = 0;

    auto getOptimalCookie = [&](int childGreed) -> int {
      // Get the least sufficient cookie
      for (size_t i = nextValidCookie; i < s.size(); ++i) {
        if (s[i] >= childGreed) {
          nextValidCookie = i + 1;
          return s[i];
        }
      }

      return -1;
    };

    for (auto childGreed : g) {
      if (getOptimalCookie(childGreed) != -1) {
        ++maxContentChildren;
      } else {
        break; // No need to continue after finding first unsatisfied
      }
    }

    return maxContentChildren;
  }
};
