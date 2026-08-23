// Leetcode #0492: Construct the Rectangle

#include <cmath>
#include <vector>

class Solution {
public:
  std::vector<int> constructRectangle(int area) {
    // Check for square root first
    int floored_sqrt = static_cast<int>(std::sqrt(area));

    // Check all other combinations from-top-to-bottom
    for (int w = floored_sqrt; w >= 1; --w) {
      if (area % w == 0) {
        if (area / w < w) {
          return {w, area / w};
        }

        return {area / w, w};
      }
    }

    return {area, 1};
  }
};
