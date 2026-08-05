// Leetcode #7 - Reverse Integer

class Solution {
public:
  int reverse(int x) {
    std::string s = std::to_string(x);

    if (x < 0) {
      // Handle negative signs
      std::reverse(s.begin() + 1, s.end());
    } else {
      std::reverse(s.begin(), s.end());
    }

    try {
      auto val = std::stoll(s);
      return (val < INT_MIN || val > INT_MAX) ? 0 : static_cast<int>(val);
    } catch (...) {
      return 0;
    }
  }
};
