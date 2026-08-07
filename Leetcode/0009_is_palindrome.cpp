// Leetcode #9 - Palindrome number

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) {
      return false;
    }

    int revHalf = 0;
    while (x > revHalf) {
      revHalf = (revHalf * 10) + (x % 10);
      x /= 10;
    }

    // Odd size -> Get rid of middle element
    return revHalf == x || revHalf / 10 == x;
  }
};

int main() {
  Solution sol;
  std::vector<int> testcases{1, 121, 123, 10, 100};

  std::ranges::for_each(testcases, [&](int x) -> void {
    std::cout << x << " -> " << sol.isPalindrome(x) << '\n';
    ;
  });

  return 0;
}
