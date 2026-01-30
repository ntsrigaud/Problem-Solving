#include <cmath>
#include <iostream>
#include <stdexcept>

// Read an integer and determine if it's prime.
// Q.A: What's the minimum number of checks needed?
// -> Using the method of Sieve or Eratosthenes, for a positive integer `n` we
// will have to perform `sqrt(n) - 2` checks.

constexpr int MAX_TEST_VALUE = 1000;

int main() {
  try {
    int n = 0;
    if (!(std::cin >> n)) {
      throw std::invalid_argument(
          "Invalid input. Please enter a numeric value.");
    }

    auto is_prime = [](const int n) -> bool {
      if (n < 2) {
        return false;
      }

      // Check up to the square root of n
      for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
          return false;
        }
      }

      return true;
    };

    std::cout << n << " is " << (is_prime(n) ? "" : "not ")
              << "a prime number.\n";

    // TEST PRIME NUMBERS
    // std::cout << "Prime numbers: ";
    // for (int i = 0; i < MAX_TEST_VALUE; ++i) {
    //   if (is_prime(i)) {
    //     std::cout << i << " ";
    //   }
    // }
    // std::cout << '\n';

  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << '\n';
  } catch (...) {
    std::cerr << "An unexpected error has occurred." << '\n';
  }

  return 0;
}
