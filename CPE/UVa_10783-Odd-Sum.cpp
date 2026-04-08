#include <iostream>

// UVa 10783 - Odd Sum

int odd_sum(int a, int b) {
  // Normally would assert a < b
  int sum = 0;
  for (int i = a; i <= b; ++i) {
    if (i % 2) {
      sum += i;
    }
  }

  return sum;
}

int main() {
  int t = 0;
  int res = 0;
  int a = 0;
  int b = 0;

  std::cin >> t;
  for (int i = 1; i <= t; ++i) {
    std::cin >> a >> b;
    res = odd_sum(a, b);
    std::cout << "Case " << i << ": " << res << '\n';
  }

  return 0;
}
