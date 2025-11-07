#include "solution.h"
#include "constant.h"
#include <algorithm>
#include <cmath>

// Implement problem-specific methods here
int Solution::prime_gap(int k)
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
};
