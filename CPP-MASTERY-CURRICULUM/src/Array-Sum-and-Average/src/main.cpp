#include "solution.h"
#include "constant.h"
#include <iostream>
#include <stdexcept>

int main() {
  try {
    Solution solution;
    int arr[MAX_ARR_SIZE];
    int n = 0;

    // Main program logic here
    std::cout << "Enter a sequence of numbers ending with 0:\n";

    while (n < MAX_ARR_SIZE) {
      if (!(std::cin >> arr[n])) {
        throw std::invalid_argument("Please enter a valid integer.");
      }

      if (arr[n] == 0) {
        break;
      }

      ++n;
    }

    int sum = solution.sum(arr, n);
    int avg = solution.average(arr, n);

    std::cout << "Sum: " << sum << '\n';
    std::cout << "Average: " << avg << '\n';

  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << "\n";
  } catch (...) {
    std::cerr << "An unexpected error has occurred.\n";
  }

  return 0;
}
