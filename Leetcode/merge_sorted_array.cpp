// Leetcode # 88 - Merge Sorted Array

#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = 0;
    int j = 0;

    std::vector<int> res;

    while (i < m && j < n) {
      if (nums1.at(i) <= nums2.at(j)) {
        res.push_back(nums1.at(i));
        ++i;
      } else {
        res.push_back(nums2.at(j));
        ++j;
      }
    }

    while (i < m) {
      res.push_back(nums1.at(i));
      ++i;
    }

    while (j < n) {
      res.push_back(nums2.at(j));
      ++j;
    }

    nums1 = res;
  }
};
