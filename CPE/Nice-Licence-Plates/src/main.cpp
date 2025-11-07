#include "solution.h"
#include <iostream>

int main() {
  try {
    Solution solution;

    // Main program logic here
    int testcases = 0;
    std::string licence_plate;
    std::cin >> testcases;

    for (int i = 0; i < testcases; ++i) {
      std::cin >> licence_plate;
      std::cout << solution.nice_licence_plate(licence_plate) << '\n';
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
