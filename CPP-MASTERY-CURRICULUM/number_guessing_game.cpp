#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

// Number guessing game:
// Pick a secret number (1-100). Let user guess. Respond with "higher" or
// "lower".

constexpr int MAX_GUESS = 100;

int main() {
  srand(time(nullptr));
  int secret_number = rand() % (MAX_GUESS + 1);

  auto desc = [](int max_guess) -> void {
    std::cout << "=========== Number Guessing Game ===========\n";
    std::cout << "Rules:\n";
    std::cout
        << "1- After the game starts, enter a number between the range (1 - "
        << max_guess << "):\n";
    std::cout << "2- You play until a valid guess is entered.\n";
    std::cout << "============================================\n";
  };

  auto guess_number = [&]() -> void {
    int input = 0;
    int count = 0;

    while (true) {
      std::cout << "Enter your guess: ";

      try {
        if (!(std::cin >> input)) {
          throw std::invalid_argument(
              "Invalid input. Please enter a numeric value.");
        }

        if (input <= 0 || input > MAX_GUESS) {
          throw std::invalid_argument("Invalid input. Please enter a value "
                                      "within the described range.");
        }

      } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << '\n';
        std::cin.clear();
        std::cin.ignore();
        continue;

      } catch (...) {
        std::cerr << "An unexpected error has occurred.\n";

        std::cin.clear();
        std::cin.ignore();
        continue;
      }

      ++count;

      if (input == secret_number) {
        std::cout << "Congratulations! You got it after " << count << " attempt"
                  << (count > 1 ? "s" : "") << ".\n";
        return;
      }

      std::cout << (input > secret_number ? "Lower" : "Higher") << '\n';
    }
  };

  desc(MAX_GUESS);
  guess_number();

  return 0;
}
