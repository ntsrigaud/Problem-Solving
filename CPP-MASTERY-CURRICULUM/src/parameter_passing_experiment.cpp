#include <iostream>

// Parameter passing experiment

void func1(int p) { std::cout << "By value passing: " << &p << '\n'; };

void func2(int &p) { std::cout << "By reference passing: " << &p << '\n'; };

void func3(const int &p) {
  std::cout << "By const reference passing: " << &p << '\n';
};

int main() {
  int value = 4;

  func1(value);
  func2(value);
  func3(value);

  return 0;
}
