#include <iostream>
#include <stdexcept>
#include <string>

// Mini Project: Simple Calculator

constexpr char INVALID_OP = '#';
constexpr char ENDLINE = '\n';

struct OpArgs {
  int n1 = 0;
  char op = INVALID_OP;
  int n2 = 0;
};

// TODO(Neil): Should not use "extern" keywork here since the function is not
// defined in another file, but how can we make it static and silence the
// linter?
extern double calculate(const OpArgs &op);

extern void desc() {
  std::cout << "=========== Basic Math Calculator =========\n";
  std::cout << "Supported Operators: +, -, *, /" << ENDLINE;
  std::cout << "Operation Example: 3 + 5" << ENDLINE;
  std::cout << "===========================================\n";
}

int main() {
  try {
    OpArgs op_args;

    desc();

    std::cout << "Enter a valid operation: ";
    std::cin >> op_args.n1 >> op_args.op >> op_args.n2;

    double result = calculate(op_args);
    std::cout << "Result: " << result << ENDLINE;
  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << ENDLINE;
  } catch (const std::runtime_error &e) {
    std::cerr << "Runtime Error: " << e.what() << ENDLINE;
  } catch (...) {
    std::cerr << "An unexpected error has occurred." << ENDLINE;
  }

  return 0;
}

extern double calculate(const OpArgs &op_args) {
  switch (op_args.op) {
  case '+':
    return op_args.n1 + op_args.n2;
  case '-':
    return op_args.n1 - op_args.n2;
  case '*':
    return op_args.n1 * op_args.n2;
  case '/':
    if (op_args.n2 == 0) {
      throw std::runtime_error("Division by zero");
    }
    return static_cast<double>(op_args.n1) / op_args.n2;
  default:
    throw std::invalid_argument("Invalid operator: " +
                                std::to_string(op_args.op));
  }
}
