#include "solution.h"
#include <iostream>

int main() {
  try {
    Solution solution;

    // Main program logic here

  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
