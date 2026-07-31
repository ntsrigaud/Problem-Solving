// Leetcode #9 - Palindrome number

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  bool isPalindrome(int x) {
    auto x_str = std::to_string(x);
    int mid = x_str.length() / 2;

    for (size_t i = 0; i < mid; ++i) {
      if (x_str[i] != x_str[x_str.length() - i - 1]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  std::vector<int> testcases{1, 121, 123};

  std::ranges::for_each(testcases, [&](int x) -> void {
    std::cout << x << " -> " << sol.isPalindrome(x) << '\n';
    ;
  });

  return 0;
}
