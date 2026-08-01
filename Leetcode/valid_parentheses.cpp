// Leetcode #20 - Valid parentheses

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isValid(std::string s) {
    const std::unordered_map<char, char> CLOSED_BRACKET{
        {')', '('}, {'}', '{'}, {']', '['}};

    // Use stack to match correct order
    std::stack<char> record;
    for (const char p : s) {
      if (CLOSED_BRACKET.contains(p)) {
        if (record.empty() || record.top() != CLOSED_BRACKET.at(p)) {
          return false;
        } // Starting with closed bracket or not matching stack top
        record.pop();
      } else {
        record.push(p);
      }
    }

    return record.empty();
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
