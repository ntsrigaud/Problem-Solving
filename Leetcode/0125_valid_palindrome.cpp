// Leetcode #125 - Valid Palindrome

#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  bool isPalindrome(std::string s) {
    // Sliding window using two-pointers algorithm
    size_t left = 0;
    size_t right = s.size() - 1;

    while (left < right) {
      if (std::isalnum(s.at(left)) == 0) {
        ++left;
      } else if (std::isalnum(s.at(right)) == 0) {
        --right;
      } else if (std::tolower(s.at(left)) != std::tolower(s.at(right))) {
        return false;
      } else {
        ++left;
        --right;
      }
    }

    return true;
  }
};

int main() {
  std::vector<std::string> testcases{"A man, a plan, a canal: Panama",
                                     "race a car", " ", "0P"};

  Solution sol;
  for (auto &t : testcases) {
    auto is_palindrome = sol.isPalindrome(t);
    std::cout << "\"" << t << "\" is " << (is_palindrome ? "" : "not ")
              << "a palindrome.\n";
  }

  return 0;
}
