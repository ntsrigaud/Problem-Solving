#include <iostream>
#include <string>

// Read two integers and swap their values. Print before and after.

// Q.A: Why do you need a temporary variable?
// -> To buffer the data in one of the variable used to store the integers while
// swapping them.

constexpr char ENDLINE = '\n';

extern void print_values(int &in1, int &in2, const std::string &desc) {
  if (!desc.empty()) {
    std::cout << desc << ENDLINE;
  }

  std::cout << "In1: " << in1 << " | In2: " << in2 << ENDLINE;
}

extern void swap_values(int &in1, int &in2) {
  // Could be done with addition and without using tmp variable, but what would
  // be the benefit ?
  int tmp = in1;
  in1 = in2;
  in2 = tmp;
};

int main(int argc, char *argv[]) {
  int in1 = 0;
  int in2 = 0;

  std::cout << "Enter two integers: ";
  std::cin >> in1 >> in2;

  print_values(in1, in2, "BEFORE: ");
  swap_values(in1, in2);
  print_values(in1, in2, "AFTER: ");

  return 0;
}
