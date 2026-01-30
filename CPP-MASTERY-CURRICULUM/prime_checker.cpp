#include <cmath>
#include <iostream>
#include <stdexcept>

// Read an integer and determine if it's prime.
// Q.A: What's the minimum number of checks needed?
// -> Using trial division up to sqrt(n), for a positive integer `n` we check
//    divisibility by each integer from 2 to floor(sqrt(n)), i.e., about sqrt(n) - 1 checks.

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
      const int limit = static_cast<int>(std::sqrt(n));
      for (int i = 2; i <= limit; ++i) {
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
