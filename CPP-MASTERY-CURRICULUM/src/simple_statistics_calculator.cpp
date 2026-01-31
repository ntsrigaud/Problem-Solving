#include <algorithm>
#include <climits>
#include <iostream>
#include <stdexcept>

// Mini-Project: Simple Statistics Calculator

struct StatMetrics {
  int count = 0;
  int sum = 0;
  double avg = 0;
  int min = INT_MAX;
  int max = INT_MIN;

  void print() {
    std::cout << "========== Statistics Results ==========\n";
    std::cout << "Count: " << count << " \n";
    std::cout << "Sum: " << sum << " \n";
    std::cout << "Avg: " << avg << " \n";
    std::cout << "Min: " << min << " \n";
    std::cout << "Max: " << max << " \n";
    std::cout << "========================================\n";
  };
};

int main() {
  StatMetrics stat_metrics;

  auto get_numbers = [&]() -> void {
    int n = 0;
    int prev = 0;
    bool all_the_same = true;

    std::cout << "Enter a sequence of numbers: ";
    while (true) {
      if (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter a valid number.";
      }

      if (n == 0) {
        break;
      }

      ++stat_metrics.count;

      if (stat_metrics.sum != 0 && prev != n) {
        all_the_same = false;
      }

      stat_metrics.sum += n;
      stat_metrics.min = std::min(stat_metrics.min, n);
      stat_metrics.max = std::max(stat_metrics.max, n);
      prev = n;
    }

    if (stat_metrics.count == 0) {
      throw std::invalid_argument("A valid sequence of integers is required.");
    }

    if (all_the_same) {
      throw std::invalid_argument("The input sequence must not be all the same.");
    }

    stat_metrics.avg =
        static_cast<double>(stat_metrics.sum) / stat_metrics.count;
  };

  try {
    get_numbers();
    stat_metrics.print();
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  } catch (...) {
    std::cerr << "An unexpected error has occurred.\n";
  }

  return 0;
}
