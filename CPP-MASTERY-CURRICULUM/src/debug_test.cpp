#include <iostream>
#include <string>
#include <vector>

// Test program to verify debugging setup
int factorial(int n) {
    // Set breakpoint here (line 7)
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void demonstrateVariables() {
    // Set breakpoint here (line 15)
    int integer = 42;
    double floatingPoint = 3.14159;
    char character = 'A';
    bool boolean = true;
    std::string text = "Hello, Debugger!";
    
    // Set breakpoint here (line 22) to inspect all variables
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Set breakpoint here (line 25) to step through loop
    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
    }
}

int main() {
    std::cout << "=== C++ Debugging Test Program ===\n\n";
    
    // Test 1: Simple variables
    std::cout << "Test 1: Variable Inspection\n";
    int x = 10;
    int y = 20;
    int sum = x + y;  // Set breakpoint here (line 38)
    std::cout << "Sum: " << sum << "\n\n";
    
    // Test 2: Function calls and stack frames
    std::cout << "Test 2: Function Call Stack\n";
    int result = factorial(5);  // Set breakpoint here (line 43)
    std::cout << "5! = " << result << "\n\n";
    
    // Test 3: Complex data structures
    std::cout << "Test 3: Complex Variables\n";
    demonstrateVariables();  // Set breakpoint here (line 48)
    
    // Test 4: Conditional debugging
    std::cout << "\nTest 4: Conditional Logic\n";
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 == 0) {
            std::cout << i << " is even\n";  // Set breakpoint here (line 54)
        } else {
            std::cout << i << " is odd\n";
        }
    }
    
    std::cout << "\n=== All tests complete ===\n";
    return 0;
}
