// Leetcode #0303: Range Sum Query - Immutable

#include <vector>

class NumArray {
  std::vector<int> data;

public:
  explicit NumArray(std::vector<int> &nums) { data = std::vector<int>(nums); }

  int sumRange(int left, int right) {
    int sum = 0;

    for (int i = left; i <= right && i < static_cast<int>(data.size()); ++i) {
      sum += data.at(i);
    }

    return sum;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
