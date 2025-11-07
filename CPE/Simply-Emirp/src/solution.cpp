#include "solution.h"
#include "constant.h"
#include <cmath>
#include <string>
#include <vector>

// Implement problem-specific methods here

std::string Solution::classify_prime(int n)
// Decide whether a number N is Non-prime, Prime or Emirp.
{
  auto reverse = [](int n) -> int {
    std::string tmp = std::to_string(n);
    for (size_t i = 0; i < tmp.size() / 2; ++i) {
      std::swap(tmp[i], tmp[tmp.size() - i - 1]);
    }

    return std::stoi(tmp);
  };

  update_prime_list(n);

  if (is_prime(n)) {
    if (n > EMIRP_LOW_BOUND) {
      int n_reverse = reverse(n);
      return (n_reverse != n && is_prime(n_reverse)) ? "emirp" : "prime";
    }
    return "prime";
  }

  return "not prime";
}

// TODO(Neil): Fix misc-no-recursion issue with is_prime method
bool Solution::is_prime(int n) {
  // Any composite number must have at least one prime factor that is less
  // than or equal to its square root
  if (n < 2) {
    return false;
  }
  int left_sqrt_n = static_cast<int>(sqrt(n));
  update_prime_list(n);

  for (const auto &p : primes) {
    if (p > left_sqrt_n) {
      break;
    }

    // Check whether any of these primes divide n
    if (n % p == 0) {
      return false;
    }
  }

  return true;
};

void Solution::update_prime_list(int n)
// Update the prime list if sqrt(n) > largest prime obtained so far
{
  int left_sqrt_n = static_cast<int>(sqrt(n));
  int start_index = (primes.empty())                ? 2
                    : (primes.back() < left_sqrt_n) ? primes.back() + 1
                                                    : -1;
  if (start_index > 1) {
    // Fill in the missing primes
    for (int i = start_index; i <= left_sqrt_n; ++i) {
      if (is_prime(i)) {
        primes.push_back(i);
      }
    }
  }
};
