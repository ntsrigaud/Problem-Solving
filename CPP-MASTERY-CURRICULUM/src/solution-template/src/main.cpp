#include "solution.h"
#include "constant.h"
#include <iostream>
#include <stdexcept>

int main() {
  try {
    Solution solution;

    // Main program logic here

  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << "\n";
  } catch (...) {
    std::cerr << "An unexpected error has occurred.\n";
  }

  return 0;
}
