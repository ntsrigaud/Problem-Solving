#include "solution.h"
#include <iostream>

int main() {
  try {
    Solution solution;

    // Main program logic here
    StrPair in;
    while (std::cin >> in.first && std::cin >> in.second) {
      std::cout << solution.common_permutation(in) << '\n';
    }
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
