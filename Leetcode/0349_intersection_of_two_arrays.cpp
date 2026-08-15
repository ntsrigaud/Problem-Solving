// Leetcode #0349: Intersection of Two Arrays

#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> intersection(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    if (nums1.empty() || nums2.empty()) {
      return {};
    }

    std::set<int> inter;
    std::vector<int> max_vector;
    std::vector<int> min_vector;

    if (nums1.size() > nums2.size()) {
      max_vector = nums1;
      min_vector = nums2;
    } else {
      max_vector = nums2;
      min_vector = nums1;
    }

    for (const auto cur_elt : max_vector) {
      auto it =
          std::ranges::find(min_vector.begin(), min_vector.end(), cur_elt);

      if (it != min_vector.end()) {
        inter.insert(cur_elt);
      }
    }

    return std::vector<int>{inter.begin(), inter.end()};
  }
};
