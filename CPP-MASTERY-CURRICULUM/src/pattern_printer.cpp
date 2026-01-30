#include <iostream>

// Print a pattern of size N
// *
// **
// ***
// ****
// *****

constexpr int DEFAULT_SIZE = 5;

int main() {
  auto pattern_printer = [](int n) -> void {

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        std::cout << '*';
      }
      std::cout << '\n';
    }
  };

  pattern_printer(DEFAULT_SIZE);

  return 0;
}
