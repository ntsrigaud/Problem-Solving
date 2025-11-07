#include <iostream>

int is_odd(int n) {
  int r = 0;

  while (n > 0) {
    r = n % 2;
    n /= 2;
  }
  return r % 2;
}

int main() {
  int testcases = 0, val = 0;
  std::cin >> testcases;

  while (--testcases >= 0) {
    std::cin >> val;
    if (is_odd(val))
      std::cout << "The parity of " << val << " is odd.\n";
    else
      std::cout << "The parity of " << val << " is even.\n";
  }

  return 0;
}
