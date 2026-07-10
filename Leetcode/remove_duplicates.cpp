#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

int removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    int j = i;
    std::unordered_map<int, int> count;

    for (j = i; j < nums.size(); ++j) {
      if (!count.count((nums.at(j)))) {
         nums[i] = nums[j];
         count[nums.at(j)] = 1;
         ++i;
      }
    }

    return i;
}

void print_array(const std::vector<int> &nums) {
  std::for_each(nums.begin(), nums.end(), [](int n) {
      std::cout << n << ' ';
      });
  std::cout << '\n';
}

int main () {
  std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  
  std::cout << "Original: ";
  print_array(nums);

  int k = removeDuplicates(nums);
  std::cout << "Removed " << k << " duplicate(s)\nResult: ";
  print_array(nums);

  return 0;
}
