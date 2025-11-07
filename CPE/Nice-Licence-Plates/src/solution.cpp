#include "solution.h"
#include <cmath>
#include <stdexcept>
#include <string>

// Implement problem-specific methods here
std::string Solution::nice_licence_plate(const std::string &plate) const {
  // We assume that the testcases are all correct, and omit testing input values

  auto convert_base26 = [](const std::string &n) -> int {
    int sum = 0;
    for (char c : n) {
      if (c < 'A' || c > 'Z')
        throw std::invalid_argument("Invalid value for integer conversion");
      sum = sum * 26 + static_cast<int>(c - 'A');
    }
    return sum;
  };

  auto to_int = [](const std::string &in) -> int {
    auto tmp = in;
    int sum = 0;
    int multiplier = 1;

    while (!tmp.empty()) {
      if (tmp.back() < '0' || tmp.back() > '9')
        throw std::invalid_argument("Invalid value for integer conversion");
      sum += static_cast<int>(tmp.back() - '0') * multiplier;
      tmp.pop_back();
      multiplier *= 10;
    }

    return sum;
  };

  auto pos = plate.find('-');
  if (pos == std::string::npos)
    return "not nice";

  auto first_part = plate.substr(0, pos);
  auto second_part = plate.substr(pos + 1, plate.size());

  if (first_part.size() != 3 || second_part.size() != 4)
    return "not nice";

  int a = 0;
  int b = 0;

  try {
    a = convert_base26(first_part);
    b = to_int(second_part);

    return (abs(a - b) <= 100) ? "nice" : "not nice";
  } catch (...) {
    return "not nice";
  }
};
