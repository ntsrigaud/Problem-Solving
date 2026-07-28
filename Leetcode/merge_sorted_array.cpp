// Leetcode #88: Merge Sorted Array

#include <iterator>
#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    std::vector<int> n1;
    std::copy(nums1.begin(), nums1.begin() + m, std::back_inserter(n1));

    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
      if (n1[i] <= nums2[j]) {
        nums1[k] = n1[i];
        ++i;
      } else {
        nums1[k] = nums2[j];
        ++j;
      }

      ++k;
    }

    while (i < m) {
      nums1[k] = n1[i];
      ++i;
      ++k;
    }

    while (j < n) {
      nums1[k] = nums2[j];
      ++j;
      ++k;
    }
  };
};
