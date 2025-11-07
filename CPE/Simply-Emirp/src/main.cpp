#include "constant.h"
#include "solution.h"
#include <iostream>

int main() {
  try {
    Solution solution;

    // Main program logic here
    int testcase = 0;
    std::string classification;

    while (std::cin >> testcase) {
      classification = solution.classify_prime(testcase);
      std::cout << testcase << " is " << classification << "." << NEWLINE;
    }

  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
