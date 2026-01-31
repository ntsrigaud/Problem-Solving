#include <iostream>
#include <stdexcept>
#include <string>

// Write `int factorial(int n)` that computes n!

// Max value before overflow for this implementation
constexpr int MAX_INT_VALUE = 12;

int factorial(int n) {
  if (n < 0) {
    throw std::invalid_argument("factorial is undefined for negative values.");
  }

  if (n > MAX_INT_VALUE) {
    throw std::overflow_error("Please enter a value less or equal to " +
                              std::to_string(MAX_INT_VALUE));
  }

  if (n == 0 || n == 1) {
    return 1;
  }

  int result = 1;

  for (int i = 2; i <= n; ++i) {
    result *= i;
  }

  return result;
}

int main() {
  try {
    int n = 0;

    std::cout << "Please enter a number between 0 and " << MAX_INT_VALUE
              << ": ";
    if (!(std::cin >> n)) {
      throw std::invalid_argument("Please enter a valid numeric value.");
    }

    int result = factorial(n);
    std::cout << "Factorial(" << n << ") = " << result << '\n';
  } catch (const std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << '\n';
  } catch (const std::overflow_error &e) {
    std::cerr << "Overflow error: " << e.what() << '\n';
  } catch (...) {
    std::cerr << "An unexpected error has occurred.\n";
  }

  return 0;
}
