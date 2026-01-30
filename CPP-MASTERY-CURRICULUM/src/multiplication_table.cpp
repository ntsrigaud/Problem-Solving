#include <iostream>

// Print a multiplication table from 1x1 to 10x10 using nested loops.

constexpr int MAX_VALUE = 10;

int main() {
  auto display_mult_table = [](const int max_value) {
    int i = 0;
    int j = 0;

    for (i = 1; i <= max_value; ++i) {
      for (j = 1; j <= max_value; ++j) {
        std::cout << i << "x" << j << " = " << i * j << '\n';
      }
      std::cout << '\n';
    }
  };

  display_mult_table(MAX_VALUE);

  return 0;
}
