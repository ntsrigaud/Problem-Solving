#include <iostream>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int i = 0;
    int j = 0;

    for (i = 0; i < nums.size(); ++i) {
      if (nums.at(i) == val) {
        for (j = i + 1; j < nums.size(); ++j) {
          if (nums.at(j) != val) {
            nums.at(i) = nums.at(j);
            ++i;
          }
        }
        break;
      }
    }

    return i;
  }
};

void print_array(const std::vector<int> &arr, int k=-1) {
  k = (k < 0) ? arr.size() : k;

  for (int i = 0; i < k; ++i) {
    std::cout << arr.at(i) << ' ';
  }
  std::cout << '\n';

}

int main () {
  Solution sol;
  std::vector<int> nums{0, 0, 1, 2, 2, 3, 1, 3};

  std::cout << "Before: ";
  print_array(nums);

  int k = sol.removeElement(nums, 2);

  std::cout << "After: ";
  print_array(nums, k);
  
  return 0;
}
