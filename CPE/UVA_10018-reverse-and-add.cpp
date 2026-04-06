#include <iostream>

constexpr int MAX_ITERATIONS = 1000;

// UVa 10018 - Reverse and add

long long reverse_number(long long n);

void solve() {
  int n;
  int iterations = 0;

  std::cin >> n;

  // Execute at least once
  do {
    long long reversed_n = reverse_number(n);
    n += reversed_n;
    ++iterations;
  } while (n != reverse_number(n));

  // We stop when the number equals its reverse -> Palindrome
  std::cout << iterations << " " << n << '\n';
}

int main() {
  int testcases = 0;

  std::cin >> testcases;

  for (int i = 0; i < testcases; ++i) {
    solve();
  }
}

long long reverse_number(long long n) {
  long long res = 0;

  while (n > 0) {
    long long mod = (n % 10);
    res = res * 10 + mod;
    n /= 10;
  }

  return res;
}
