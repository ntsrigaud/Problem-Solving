#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int i = digits.size() - 1;
    int carry = 1;

    while (i >= 0) {
      if (carry) {
        carry = (digits[i] + 1) % 10 == 0;
        digits[i] = (digits[i] + 1) % 10;
        --i;
      } else
        break;
    }

    if (carry) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};

int main() {
  std::vector<int> nums{8, 9, 9, 9};
  Solution sol;

  auto printNums = [](std::vector<int> nums) -> void {
    std::cout << '[';
    std::for_each(nums.begin(), nums.end(),
                  [](int n) { std::cout << n << ','; });
    std::cout << "}\n";
  };

  std::cout << "Before: ";
  printNums(nums);
  sol.plusOne(nums);
  std::cout << "After: ";
  printNums(nums);

  return 0;
}
