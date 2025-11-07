#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

/*
 * Prime Gap
 * --------
 *  Write a program to calculate, for a given positive integer k, the length of
 * the prime gap that contains k.
 *
 * Revision history:
 * Revised by Neil Taison Rigaud, October 2025
 * Revised by Neil Taison Rigaud, November 2025 - Passed
 */

constexpr int MIN_PRIME = 2;

static std::vector<int> prime_list;

int prime_gap(int k)
// Return the length of the prime gap containing k
{

  auto is_prime = [&](int n) -> bool
  // Check if a number is a prime
  {
    if (n < MIN_PRIME) {
      return false;
    }

    if (std::find(prime_list.begin(), prime_list.end(), n) !=
        prime_list.end()) {
      return true;
    }

    // Determine if the number is prime iteratively
    for (int i = MIN_PRIME; i <= sqrt(n); ++i) {
      if (n % i == 0) {
        return false;
      }
    }

    prime_list.push_back(n);

    return true;
  };

  if (k < MIN_PRIME || is_prime(k)) {
    return 0;
  }

  // Find the lower and upper bound for the prime gap range
  int low = k, high = k;
  while (!is_prime(--low))
    ;
  while (!is_prime(++high))
    ;

  return high - low;
}

int main() {

  int testcase = 0;
  while (std::cin >> testcase && testcase != 0) {
    std::cout << prime_gap(testcase) << '\n';
  }

  return 0;
}
