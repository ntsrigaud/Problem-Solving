// Leetcode #20 - Valid parentheses

#include <iostream>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    if (s.size() % 2 != 0) {
      return false;
    }

    // Use stack to match correct order
    std::string stack;

    auto updateStack = [&](const char p) -> bool {
      switch (p) {
      // Push matching closed brackets to check later
      case '(':
        stack.push_back(')');
        return true;
      case '{':
        stack.push_back('}');
        return true;
      case '[':
        stack.push_back(']');
        return true;
      default:
        if (!stack.empty() && stack.back() == p) {
          stack.pop_back();
          return true;
        }
        break;
      }

      return false;
    };

    for (const char p : s) {
      if (!updateStack(p)) {
        return false;
      };
    }

    return stack.empty();
  }
};

int main() {
  std::string testcase;
  Solution sol;

  while (std::cin >> testcase && !testcase.empty()) {
    std::cout << testcase << " -> "
              << (sol.isValid(testcase) ? "True" : "False") << '\n';
  }

  return 0;
}
