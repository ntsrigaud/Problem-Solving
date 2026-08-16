// Leetcode #0350: Intersection of Two Arrays II

#include <vector>

class Solution {
public:
  std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    if (nums1.empty() || nums2.empty()) {
      return {};
    }

    size_t left = 0;
    size_t right = 0;
    int cur_left_item = 0;
    int cur_right_item = 0;
    std::vector<int> inter;

    // This could be removed, since sort has "<" as default behavior. I don't
    // know why exactly but this version is faster on leetcode than without it.
    // -> It might be due to Leetcode server Jitter, but no need to test that
    // hypothesis.
    auto comp = [](int first, int second) -> bool { return first < second; };

    std::ranges::sort(nums1, comp);
    std::ranges::sort(nums2, comp);

    // Two-pointers algorithm
    while (left < nums1.size() && right < nums2.size()) {
      cur_left_item = nums1.at(left);
      cur_right_item = nums2.at(right);

      if (cur_left_item == cur_right_item) {
        inter.push_back(cur_left_item);
        ++left;
        ++right;
      } else if (cur_left_item < cur_right_item) {
        ++left;
      } else {
        ++right;
      }
    }

    return inter;
  }
};
