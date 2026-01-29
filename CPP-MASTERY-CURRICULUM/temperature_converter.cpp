#include <iostream>
#include <stdexcept>
#include <string>

// Write a program that converts Celsius to Fahrenheit.
// Question: Why do you need to be careful about integer vs. floating-point
// division?
//  -> Because integer division truncates by specification.

constexpr double SLOPE = static_cast<double>(9) / 5;
constexpr int INTERCEPT = 32;
constexpr double MIN_CELSIUS_TEMP = -273.15;

double celsius2Fahrenheit(const double celsius) {
  if (celsius < MIN_CELSIUS_TEMP) {
    throw std::invalid_argument("Invalid celsius temperature: " +
                                std::to_string(celsius));
  }

  return (celsius * SLOPE) + INTERCEPT;
}

int main() {
  double celsius = 0;

  try {
    std::cout
        << "============= Celsius to Fahrenheit Converter =============\n";
    std::cout << "Enter a positive Celsius value: ";
    std::cin >> celsius;

    double fahrenheit = celsius2Fahrenheit(celsius);

    std::cout << celsius << " C -> " << fahrenheit << " F\n";
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << "\n";
  } catch (...) {
    std::cerr << "An unexpected error has occured." << "\n";
  }
  return 0;
}
