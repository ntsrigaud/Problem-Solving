#include <iostream>
#include <cstdint>

constexpr int MAX_ITERATIONS = 1000;

// UVa 10018 - Reverse and add

uint32_t reverse_number(uint32_t n) {
  uint32_t res = 0;

  // As long as n is positive, we extract digits
  while (n > 0) {
    res = res * 10 + (n % 10);
    n /= 10;
  }

  return res;
}

void solve() {
  // 1. Initialize to 0 to prevent garbage memory issues
  uint32_t n = 0;

  // 2. Failsafe: Only proceed if we successfully read an integer
  if (!(std::cin >> n)) return;

  int iterations = 0;

  // Execute at least once
  do {
    uint32_t reversed_n = reverse_number(n);

    // At iteration 17 for input 739, this addition will exceed 4,294,967,295 (UINT_MAX)
    // Because it is uint32_t, it will wrap around, matching the judge's behavior.
    n += reversed_n;
    ++iterations;

    // 3. Emergency brake: Prevent infinite loop from Lychrel numbers of overflow.
    if (iterations >= MAX_ITERATIONS) break;

  } while (n != reverse_number(n));

  // We stop when the number equals its reverse -> Palindrome
  std::cout << iterations << " " << n << '\n';
}

int main() {
  // Fast I/O: Crucial for avoiding TLE in competitive programming
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int testcases = 0;

  // Read the number of testcases, and ensure it actually succeeded.
  if (std::cin >> testcases && testcases > 0) {
    while (testcases--) {
      solve();
    }
  }

  return 0;
}

