// Leetcode #0217 - Contains Duplicate

#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> map;

    for (int n : nums) {
      if (map.contains(n)) {
        return true;
      }

      map.insert(n);
    }

    return false;
  }
};
