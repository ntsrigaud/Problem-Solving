// Leetcode #1037: Valid Boomerang

#include <vector>

class Solution {
public:
  bool isBoomerang(std::vector<std::vector<int>> &points) {
    auto areDistinct = [](const std::vector<int> &a,
                          const std::vector<int> &b) -> bool {
      return a.front() != b.front() || a.back() != b.back();
    };

    auto areAllDistinct = [&]() -> bool {
      return areDistinct(points[0], points[1]) &&
             areDistinct(points[1], points[2]) &&
             areDistinct(points[0], points[2]);
    };

    auto areCollinear = [&]() -> bool {
      auto dist = [](const std::vector<int> &a,
                     const std::vector<int> &b) -> std::pair<int, int> {
        return {b.front() - a.front(), b.back() - a.back()};
      };

      auto ab = dist(points[0], points[1]);
      auto bc = dist(points[1], points[2]);

      // Check if AB is a multiple of BC
      return ab.first * bc.second == ab.second * bc.first;
    };

    return areAllDistinct() && !areCollinear();
  }
};
