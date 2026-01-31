#include <iostream>
#include <stdexcept>

// Write `int factorial(int n)` that computes n!

// Max value before overflow for this implementation
constexpr int MAX_INT_VALUE = 12;

int factorial(int n) {
  if (n < 0) {
    throw std::invalid_argument("Factorial of negative input.");
  }

  if (n > MAX_INT_VALUE) {
    throw std::runtime_error("Operation overlfow. Please try a smaller value.");
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
  } catch (const std::runtime_error &e) {
    std::cerr << "Runtime error: " << e.what() << '\n';
  } catch (...) {
    std::cerr << "An unexpected error has occurred.\n";
  }

  return 0;
}
