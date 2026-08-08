// Leetcode #118 - Pascal's Triangle

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> pascal_triangle;

    for (size_t r = 0; r < static_cast<size_t>(numRows); ++r) {
      if (r == 0) {
        pascal_triangle.push_back({1});
        continue;
      };

      if (r == 1) {
        pascal_triangle.push_back({1, 1});
        continue;
      };

      std::vector<int> row;
      auto prev_row = pascal_triangle.at(r - 1);
      for (size_t c = 0; c <= prev_row.size(); ++c) {
        // Cur element = sum of two element on top
        int cur_value = (c == 0 || c == prev_row.size())
                            ? 1
                            : prev_row.at(c - 1) + prev_row.at(c);
        row.push_back(cur_value);
      }
      pascal_triangle.push_back(row);
    }

    return pascal_triangle;
  }
};
