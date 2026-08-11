// Leetcode #0219 - Contains Duplicate II

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
    std::unordered_set<size_t> window;

    for (size_t i = 0; i < nums.size(); ++i) {
      int num = nums.at(i);
      if (window.contains(num)) {
        return true;
      }

      window.insert(num);
      if (window.size() > k) {
        window.erase(nums.at(i - k));
      }
    }

    return false;
  }
};
