#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

// Write `bool isPalindrome(const std::string& str)` that checks if a string
// reads the same forwards and backwards.

bool isPalindrome(const std::string &str) {
  if (str.empty()) {
    throw std::invalid_argument("input string must not be empty.");
  }

  // Not the best solution since you will be parsing the same string twice, but
  // for syntax practice it should do.

  auto remove_invalid_chars = [&]() -> std::string {
    std::string res;
    for (const auto &ch : str) {
      if (std::isalnum(ch)) {
        res.push_back(std::tolower(ch));
      }
    }

    return res;
  };

  // Parse from both sides
  std::string modified_str = remove_invalid_chars();
  for (size_t i = 0; i < modified_str.length() / 2; ++i) {
    if (modified_str[i] != modified_str[modified_str.length() - i - 1]) {
      return false;
    }
  }

  return true;
};

int main() {
  try {
    std::string input;
    std::cout << "Enter a text: ";

    std::getline(std::cin, input);

    bool is_palindrome = isPalindrome(input);
    std::cout << input << " is " << (is_palindrome ? "" : "not ")
              << "a palindrome.\n";

  } catch (const std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << '\n';
  } catch (...) {
    std::cerr << "An unexpected error has occurred.\n";
  }

  return 0;
}
