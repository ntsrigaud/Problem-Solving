#include <cmath>
#include <iostream>

// UVa 10055: Hashmat the brave

int main() {
  long long a = 0, b = 0;

  while (std::cin >> a >> b) {
    std::cout << std::abs(b - a) << '\n';
  }

  return 0;
}
