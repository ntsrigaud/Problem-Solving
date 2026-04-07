#include <iostream>

// UVa 10323 - Factorial! You Must be Kidding!!! (YZU)

long long fact(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  long long a = n, b = 0;

  for (int i = 1; i < n; ++i) {
    b = a;
    a = b * (n - i);
  }

  return a;
}

void solve(int n) {
  // Handle the "Joke" Negative Numbers
  if (n < 0) {
    std::cout << ((n % 2) == 0 ? "Underflow!" : "Overflow!") << '\n';
  } else if (n < 8) {
    std::cout << "Underflow!" << '\n';
  } else if (n > 13) {
    std::cout << "Overflow!" << '\n';
  } else {
    std::cout << fact(n) << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int test_case = 0;
  while (std::cin >> test_case) {
    solve(test_case);
  }

  return 0;
}
