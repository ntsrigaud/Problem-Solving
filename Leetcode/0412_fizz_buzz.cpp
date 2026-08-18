// Leetcode #0412: Fizz Buzz

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> answer;
    answer.reserve(n);

    for (size_t i = 1; i <= n; ++i) {
      if (i % 3 == 0 && i % 5 == 0) {
        answer.emplace_back("FizzBuzz");
      } else if (i % 3 == 0) {
        answer.emplace_back("Fizz");
      } else if (i % 5 == 0) {
        answer.emplace_back("Buzz");
      } else {
        answer.emplace_back(std::to_string(i));
      }
    }

    return answer;
  }
};
