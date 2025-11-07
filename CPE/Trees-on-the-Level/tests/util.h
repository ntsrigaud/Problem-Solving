// Small test helper to run the Solution on a string and capture output.
#ifndef TESTS_UTIL_H
#define TESTS_UTIL_H

#include "solution.h"
#include <sstream>
#include <string>

inline std::string runSolution(const std::string &input) {
  Solution sol;
  std::istringstream in(input);
  std::ostringstream out;
  sol.process(in, out);
  return out.str();
}

#endif // TESTS_UTIL_H
