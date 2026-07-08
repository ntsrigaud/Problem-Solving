#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

#define ENDLINE '\n'

bool isValid(const std::string &s) {
  std::unordered_map<char, char> map{
      {'(', ')'},
      {'{', '}'},
      {'[', ']'},
  };

  std::stack<char> processed;

  auto find_key = [&](char val) -> char {
    for (const auto &p : map) {
      if (p.second == val) {
        return p.first;
      }
    }

    return '0';
  };

  for (char ch : s) {
    if (processed.empty() ||
        map.contains(ch)) { // Empty stack or opening bracket
      processed.push(ch);
    } else if (!map.contains(ch)) { // Ending bracket
      char key = find_key(ch);
      if (processed.top() != key) { // Match top of stack
        return false;
      } else {
        processed.pop();
      }
    }
  }

  return processed.empty();
}

int main() {
  std::string input;

  std::cin >> input;
  std::cout << (isValid(input) ? "True" : "False") << '\n';

  return 0;
}
