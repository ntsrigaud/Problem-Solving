#include "solution.h"
#include <iostream>

int main() {
  try {
    Solution solution;

    // Main program logic here
    int testcase = 0;
    while (std::cin >> testcase && testcase != 0) {
      std::cout << solution.prime_gap(testcase) << '\n';
    }
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
