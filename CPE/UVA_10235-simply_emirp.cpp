#include <cmath>
#include <iostream>
#include <string>
#include <vector>

/*
 * An integer greater than 1 is called a prime number if its only positive
 * divisors (factors) are 1 and itself.
 *
 * An Emirp (Prime spelt backwards) is a Prime that gives you a different Prime
 * when its digits are reversed.
 */

// Since those two methods create a recursive call chain, it is difficult to
// define them as lambda functions. Keep them as free functions that accept the
// prime cache vector by reference.

constexpr char NEWLINE = '\n';
constexpr int EMIRP_LOW_BOUND = 9;

bool is_prime(int n, std::vector<int> &primes);

void update_prime_list(std::vector<int> &primes, int n)
// Update the prime list if sqrt(n) > largest prime obtained so far
{
  int left_sqrt_n = static_cast<int>(sqrt(n));
  int start_index = (primes.empty())                ? 2
                    : (primes.back() < left_sqrt_n) ? primes.back() + 1
                                                    : -1;
  if (start_index > 1) {
    // Fill in the missing primes
    for (int i = start_index; i <= left_sqrt_n; ++i) {
      if (is_prime(i, primes)) {
        primes.push_back(i);
      }
    }
  }
};

bool is_prime(int n, std::vector<int> &primes) {
  // Any composite number must have at least one prime factor that is less
  // than or equal to its square root
  if (n < 2) {
    return false;
  }

  int left_sqrt_n = static_cast<int>(sqrt(n));
  update_prime_list(primes, n);

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

std::string classify_prime(int n)
// Decide whether a number N is Non-prime, Prime or Emirp.
{
  static std::vector<int> primes; // Retain values across function calls

  auto reverse = [](int n) -> int {
    std::string tmp = std::to_string(n);
    for (size_t i = 0; i < tmp.size() / 2; ++i) {
      std::swap(tmp[i], tmp[tmp.size() - i - 1]);
    }

    return std::stoi(tmp);
  };

  update_prime_list(primes, n);

  if (is_prime(n, primes)) {
    // Only consider emirp if n is greater than EMIRP_LOW_BOUND and its
    // reversal is a different prime
    if (n > EMIRP_LOW_BOUND) {
      int n_reverse = reverse(n);
      return (n_reverse != n && is_prime(n_reverse, primes)) ? "emirp"
                                                             : "prime";
    }
    return "prime";
  }

  return "not prime";
}

int main() {
  int testcase = 0;
  std::string classification;

  while (std::cin >> testcase) {
    classification = classify_prime(testcase);
    std::cout << testcase << " is " << classification << "." << NEWLINE;
  }

  return 0;
}
