# C++ Mastery Training Program

## A 12-Week Journey from Fundamentals to Modern C++ Proficiency

**Target Audience:** Motivated beginners with basic computer literacy  
**Time Commitment:** 10-15 hours/week  
**Philosophy:** Understanding over memorization, correctness over cleverness, judgment over syntax

---

## Program Structure Overview

This program is divided into three phases:

- **Foundation (Weeks 1-4):** Programming fundamentals, C++ basics, and mental models
- **Core Mastery (Weeks 5-8):** Memory management, OOP, and STL containers
- **Advanced Application (Weeks 9-12):** Modern C++ idioms, algorithmic thinking, and real-world patterns

Each week builds directly on previous weeks. Do not skip ahead.

---

# PHASE 1: FOUNDATION (Weeks 1-4)

## Week 1: Programming Fundamentals and Mental Models

### Learning Objectives

- Understand what a program is: a sequence of instructions transforming input to output
- Develop a mental model of variables as named storage locations
- Understand types as contracts that define what operations are valid
- Learn how to read error messages and use them for debugging
- Recognize that programming is about expressing ideas precisely

### Core Concepts

#### 1.1 The Compilation Model

```cpp
// Source code (.cpp) → Compiler → Executable program
// Errors happen at compile-time (before running) or run-time (during execution)
// Understanding this distinction is critical
```

**Why it matters:** You cannot "try" invalid C++ code to see what happens. The compiler enforces rules. Learn to use it as a tool.

#### 1.2 Variables and Types

```cpp
#include <iostream>

int main() {
    // A variable is a named location in memory with a type
    int age = 25;           // integer: whole numbers
    double price = 19.99;   // floating-point: decimal numbers
    char grade = 'A';       // single character
    bool isPassed = true;   // true or false

    // Types tell the compiler:
    // 1. How much memory to allocate
    // 2. What operations are valid
    // 3. How to interpret the bits in memory

    std::cout << "Age: " << age << "\n";
    return 0;
}
```

**Key insight:** Types are not just labels—they define behavior and safety.

#### 1.3 Input and Output

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    std::cout << "Enter your name: ";
    std::cin >> name;  // Reads until whitespace

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old.\n";
    return 0;
}
```

**Common mistake:** Forgetting that `>>` stops at whitespace. For full lines, use `std::getline(std::cin, name)`.

#### 1.4 Basic Arithmetic and Expressions

```cpp
int main() {
    int a = 10;
    int b = 3;

    int sum = a + b;        // 13
    int diff = a - b;       // 7
    int prod = a * b;       // 30
    int quot = a / b;       // 3 (integer division!)
    int rem = a % b;        // 1 (modulo/remainder)

    double preciseQuot = static_cast<double>(a) / b;  // 3.33333...

    // Integer division truncates! This is not a bug, it's the specification.
    return 0;
}
```

**Critical concept:** Integer division behavior is defined by the language. Always verify your types match your intent.

### Exercises

1. **Temperature Converter**  
   Write a program that converts Celsius to Fahrenheit. Formula: F = C × 9/5 + 32  
   Question: Why do you need to be careful about integer vs. floating-point division?

2. **Area Calculator**  
   Read width and height, compute area of a rectangle. Then extend to compute perimeter.  
   Question: What happens if the user enters negative numbers? Should your program handle this?

3. **Variable Swap**  
   Read two integers and swap their values. Print before and after.  
   Question: Why do you need a temporary variable?

### Mini-Project: Simple Calculator

Create a program that:

- Reads two numbers and an operator (+, -, \*, /)
- Performs the operation and prints the result
- Handles division by zero gracefully (print an error message)
- Demonstrates understanding of types, input/output, and control flow

---

## Week 2: Control Flow and Decision Making

### Learning Objectives

- Understand conditional execution: making decisions in code
- Master boolean logic and how to combine conditions
- Learn loop constructs and when to use each
- Recognize the difference between iteration patterns
- Avoid infinite loops and off-by-one errors

### Core Concepts

#### 2.1 Conditional Statements

```cpp
#include <iostream>

int main() {
    int score;
    std::cout << "Enter your score: ";
    std::cin >> score;

    // if-else chain: mutually exclusive conditions
    if (score >= 90) {
        std::cout << "Grade: A\n";
    } else if (score >= 80) {
        std::cout << "Grade: B\n";
    } else if (score >= 70) {
        std::cout << "Grade: C\n";
    } else if (score >= 60) {
        std::cout << "Grade: D\n";
    } else {
        std::cout << "Grade: F\n";
    }

    // Conditions are checked in order. First match wins.
    return 0;
}
```

**Design principle:** Order your conditions from most specific to most general.

#### 2.2 Boolean Logic

```cpp
#include <iostream>

int main() {
    int age;
    bool hasLicense;

    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Have driver's license? (1/0): ";
    std::cin >> hasLicense;

    // Logical operators: && (AND), || (OR), ! (NOT)
    if (age >= 18 && hasLicense) {
        std::cout << "You can drive.\n";
    } else if (age >= 18 && !hasLicense) {
        std::cout << "You need a license.\n";
    } else {
        std::cout << "You're too young to drive.\n";
    }

    // Short-circuit evaluation: && stops at first false, || stops at first true
    return 0;
}
```

**Critical concept:** `&&` and `||` short-circuit. Use this for safety: `if (ptr != nullptr && ptr->data > 0)`

#### 2.3 Loops: While and For

```cpp
#include <iostream>

int main() {
    // WHILE: use when you don't know iteration count in advance
    int sum = 0;
    int num;
    std::cout << "Enter numbers (0 to stop):\n";
    while (std::cin >> num && num != 0) {
        sum += num;
    }
    std::cout << "Sum: " << sum << "\n";

    // FOR: use when you know iteration count or have clear iteration steps
    std::cout << "Counting to 10:\n";
    for (int i = 1; i <= 10; ++i) {  // Note: ++i, not i++, as a good habit
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
```

**When to use which:**

- `for`: Definite iteration (counting, processing a range)
- `while`: Indefinite iteration (event-driven, sentinel-based)
- `do-while`: Rarely used; when loop body must execute at least once

#### 2.4 Break and Continue

```cpp
#include <iostream>

int main() {
    // BREAK: exit loop immediately
    for (int i = 1; i <= 100; ++i) {
        if (i * i > 50) {
            std::cout << "First number whose square exceeds 50: " << i << "\n";
            break;  // Exit the loop
        }
    }

    // CONTINUE: skip to next iteration
    std::cout << "Even numbers from 1 to 10: ";
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 != 0) {
            continue;  // Skip odd numbers
        }
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
```

**Design principle:** Use `break` and `continue` sparingly. They can make control flow harder to follow.

### Common Mistakes

1. **Off-by-one errors:**

   ```cpp
   // Wrong: misses last element
   for (int i = 0; i < 10; ++i) { /* processes 0-9 */ }

   // Consider: what range do you actually need?
   ```

2. **Infinite loops:**

   ```cpp
   // Wrong: condition never becomes false
   int x = 10;
   while (x > 0) {
       std::cout << x << "\n";
       // Forgot to modify x!
   }
   ```

3. **Misusing equality for floating-point:**

   ```cpp
   // Dangerous:
   double x = 0.0;
   while (x != 1.0) {
       x += 0.1;  // May never exactly equal 1.0 due to precision
   }

   // Better: use a range or tolerance
   ```

### Exercises

1. **Prime Checker**  
   Read an integer and determine if it's prime.  
   Question: What's the minimum number of checks needed?

2. **Multiplication Table**  
   Print a multiplication table from 1×1 to 10×10 using nested loops.  
   Question: How do you format the output neatly?

3. **Number Guessing Game**  
   Pick a secret number (1-100). Let user guess. Respond with "higher" or "lower".  
   Question: How do you ensure valid input?

4. **Pattern Printer**  
   Print this pattern:
   ```
   *
   **
   ***
   ****
   *****
   ```
   Question: How do nested loops help here?

### Mini-Project: Simple Statistics Calculator

Create a program that:

- Reads a sequence of numbers (stop on 0)
- Computes: count, sum, average, minimum, maximum
- Handles edge cases (no numbers entered, all same number)
- Demonstrates mastery of loops and conditional logic

---

## Week 3: Functions and Code Organization

### Learning Objectives

- Understand functions as named, reusable blocks of logic
- Learn parameter passing: value vs. reference
- Master the concept of scope and lifetime
- Recognize when to create a function vs. inline code
- Understand the compilation model: declarations vs. definitions

### Core Concepts

#### 3.1 Basic Function Syntax

```cpp
#include <iostream>

// Function declaration (prototype): tells compiler the signature
int add(int a, int b);
void greet(std::string name);

int main() {
    int result = add(5, 3);
    std::cout << "Sum: " << result << "\n";

    greet("Alice");

    return 0;
}

// Function definition: provides implementation
int add(int a, int b) {
    return a + b;
}

void greet(std::string name) {
    std::cout << "Hello, " << name << "!\n";
    // void means "no return value"
}
```

**Key insight:** Separate declaration from definition allows organizing code into headers and source files.

#### 3.2 Pass by Value vs. Pass by Reference

```cpp
#include <iostream>

// Pass by value: function gets a copy
void incrementValue(int x) {
    x = x + 1;  // Modifies local copy only
}

// Pass by reference: function gets access to original
void incrementReference(int& x) {
    x = x + 1;  // Modifies the original variable
}

// Pass by const reference: efficient read-only access
void printMessage(const std::string& msg) {
    std::cout << msg << "\n";
    // Cannot modify msg; const protects it
}

int main() {
    int num = 10;

    incrementValue(num);
    std::cout << "After value: " << num << "\n";  // Still 10

    incrementReference(num);
    std::cout << "After reference: " << num << "\n";  // Now 11

    printMessage("Using const reference avoids copying");

    return 0;
}
```

**When to use what:**

- **Pass by value:** Small types (int, char, bool), when you need a local copy
- **Pass by reference:** When you need to modify the original
- **Pass by const reference:** Large types (strings, containers) for read-only access—avoids copying

#### 3.3 Function Overloading

```cpp
#include <iostream>

// Same name, different parameters
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);  // Compose functions
}

int main() {
    std::cout << max(5, 10) << "\n";           // Calls int version
    std::cout << max(3.14, 2.71) << "\n";      // Calls double version
    std::cout << max(1, 5, 3) << "\n";         // Calls three-parameter version

    return 0;
}
```

**Design principle:** Overloading should represent the same conceptual operation with different types, not unrelated behaviors.

#### 3.4 Scope and Lifetime

```cpp
#include <iostream>

int globalVar = 100;  // Global scope: visible everywhere

void exampleFunction() {
    int localVar = 50;  // Local scope: visible only in this function
    std::cout << "Global: " << globalVar << "\n";
    std::cout << "Local: " << localVar << "\n";
}

int main() {
    std::cout << "Global in main: " << globalVar << "\n";
    // std::cout << localVar << "\n";  // ERROR: localVar not visible here

    exampleFunction();

    {
        int blockVar = 25;  // Block scope
        std::cout << "Block: " << blockVar << "\n";
    }
    // std::cout << blockVar << "\n";  // ERROR: blockVar out of scope

    return 0;
}
```

**Critical concept:**

- **Scope:** Where a name is visible
- **Lifetime:** When a variable exists in memory
- Variables created on the stack are destroyed when their scope ends

#### 3.5 Early Returns and Guard Clauses

```cpp
#include <iostream>

// Poor: nested if-else pyramid
int computeValueBad(int x) {
    if (x > 0) {
        if (x < 100) {
            return x * 2;
        } else {
            return 100;
        }
    } else {
        return 0;
    }
}

// Better: early returns for error/edge cases
int computeValueGood(int x) {
    if (x <= 0) return 0;      // Guard clause
    if (x >= 100) return 100;  // Guard clause
    return x * 2;              // Normal case at end
}
```

**Design principle:** Handle edge cases early, then focus on the main logic. Reduces nesting.

### Common Mistakes

1. **Returning reference to local variable:**

   ```cpp
   // DANGER: undefined behavior!
   int& badFunction() {
       int x = 10;
       return x;  // x is destroyed when function returns!
   }
   ```

2. **Modifying pass-by-value when you meant pass-by-reference:**

   ```cpp
   void swap(int a, int b) {  // Wrong! These are copies
       int temp = a;
       a = b;
       b = temp;
   }

   void swapCorrect(int& a, int& b) {  // Correct
       int temp = a;
       a = b;
       b = temp;
   }
   ```

3. **Overusing global variables:**
   - Makes code harder to test and reason about
   - Prefer passing data through parameters

### Exercises

1. **Factorial Function**  
   Write `int factorial(int n)` that computes n!  
   Question: What should happen for negative inputs? For n=0?

2. **Is Palindrome**  
   Write `bool isPalindrome(const std::string& str)` that checks if a string reads the same forwards and backwards.  
   Question: How do you handle case sensitivity and spaces?

3. **Array Sum and Average**  
   Write two functions: `int sum(int arr[], int size)` and `double average(int arr[], int size)`  
   Question: Why do you need to pass size separately?

4. **Parameter Passing Experiment**  
   Create functions to demonstrate value, reference, and const reference passing. Print addresses using `&variable` to observe.

### Mini-Project: Text Analysis Tool

Create a program with functions that:

- Count words in a string
- Count vowels and consonants
- Convert to uppercase/lowercase
- Check if a string is a valid identifier (letters, digits, underscore; must start with letter)
- Demonstrate proper function decomposition and const-correctness

---

## Week 4: Arrays, Strings, and Basic Algorithms

### Learning Objectives

- Understand arrays as contiguous memory blocks
- Learn array indexing and bounds checking (or lack thereof)
- Master C++ strings vs. C-style strings
- Implement fundamental algorithms: search, sort, reverse
- Recognize when arrays are insufficient (foreshadowing vectors)

### Core Concepts

#### 4.1 Arrays: Fixed-Size Collections

```cpp
#include <iostream>

int main() {
    // Array: fixed-size, contiguous memory
    int numbers[5] = {10, 20, 30, 40, 50};

    // Access by index (0-based)
    std::cout << "First element: " << numbers[0] << "\n";
    std::cout << "Last element: " << numbers[4] << "\n";

    // Iterate through array
    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    // DANGER: No bounds checking!
    // numbers[10] = 999;  // Undefined behavior—may crash or corrupt memory

    return 0;
}
```

**Critical limitation:** Arrays don't know their own size. You must track it separately.

#### 4.2 Passing Arrays to Functions

```cpp
#include <iostream>

// Arrays decay to pointers when passed to functions
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= 2;  // Modifies original array
    }
}

int main() {
    int data[5] = {1, 2, 3, 4, 5};

    printArray(data, 5);
    modifyArray(data, 5);
    printArray(data, 5);  // Now doubled

    return 0;
}
```

**Key insight:** Array parameters are actually pointers. Functions always modify the original.

#### 4.3 C++ Strings (std::string)

```cpp
#include <iostream>
#include <string>

int main() {
    std::string greeting = "Hello";
    std::string name = "World";

    // Concatenation
    std::string message = greeting + ", " + name + "!";
    std::cout << message << "\n";

    // Length
    std::cout << "Length: " << message.length() << "\n";

    // Access individual characters
    std::cout << "First char: " << message[0] << "\n";

    // Substring
    std::string sub = message.substr(0, 5);  // "Hello"
    std::cout << "Substring: " << sub << "\n";

    // Find
    size_t pos = message.find("World");
    if (pos != std::string::npos) {
        std::cout << "Found 'World' at position " << pos << "\n";
    }

    return 0;
}
```

**Why use std::string:**

- Manages memory automatically
- Knows its own size
- Supports convenient operations
- Safer than C-style strings (char arrays)

#### 4.4 Fundamental Algorithms

##### Linear Search

```cpp
#include <iostream>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  // Found at index i
        }
    }
    return -1;  // Not found
}

int main() {
    int data[] = {10, 23, 45, 12, 78, 34};
    int size = 6;

    int index = linearSearch(data, size, 45);
    if (index != -1) {
        std::cout << "Found at index " << index << "\n";
    } else {
        std::cout << "Not found\n";
    }

    return 0;
}
```

##### Binary Search (Requires Sorted Array)

```cpp
#include <iostream>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int data[] = {10, 20, 30, 40, 50, 60, 70};  // MUST be sorted
    int size = 7;

    int index = binarySearch(data, size, 40);
    std::cout << "Found at index: " << index << "\n";

    return 0;
}
```

**Key insight:** Binary search is O(log n) vs. linear's O(n), but requires sorted data. Trade-offs matter.

##### Selection Sort

```cpp
#include <iostream>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        // Find minimum element in unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap minimum with first unsorted element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int size = 5;

    selectionSort(data, size);

    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
```

**Pedagogical note:** You'll soon learn that `std::sort()` is better in practice. But understanding the algorithm builds intuition.

### Common Mistakes

1. **Off-by-one errors in loops:**

   ```cpp
   int arr[5];
   for (int i = 0; i <= 5; ++i) {  // Wrong! Accesses arr[5]
       arr[i] = 0;
   }
   ```

2. **Confusing array size with last index:**
   - Array of size 5 has valid indices 0-4
   - Last index = size - 1

3. **Returning local array from function:**
   ```cpp
   int* badFunction() {
       int arr[10];
       return arr;  // DANGER: arr is destroyed when function returns
   }
   ```

### Exercises

1. **Reverse Array**  
   Write `void reverse(int arr[], int size)` that reverses array in-place.  
   Question: How do you avoid swapping elements twice?

2. **Find Maximum**  
   Write `int findMax(int arr[], int size)` that returns the largest element.  
   Question: What should happen for empty arrays?

3. **Count Occurrences**  
   Write `int count(int arr[], int size, int value)` that counts how many times `value` appears.

4. **String Reversal**  
   Write `std::string reverseString(const std::string& str)`.  
   Question: How is this different from reversing an array?

5. **Anagram Checker**  
   Write `bool areAnagrams(const std::string& s1, const std::string& s2)` that checks if two strings are anagrams.  
   Hint: Sort both and compare, or count character frequencies.

### Mini-Project: Student Grade Manager

Create a program that:

- Stores up to 50 student scores in an array
- Implements functions to:
  - Add a score
  - Calculate average
  - Find highest and lowest scores
  - Count students above average
  - Sort scores and display
- Demonstrates array manipulation and algorithm implementation
- Highlights the limitations of fixed-size arrays (motivates vectors)

**Reflection question:** What happens when you need to store more than 50 scores? This limitation leads us to dynamic memory and containers.

---

# PHASE 2: CORE MASTERY (Weeks 5-8)

## Week 5: Dynamic Memory and RAII

### Learning Objectives

- Understand stack vs. heap memory
- Learn manual dynamic allocation with new/delete
- Recognize memory leaks and dangling pointers
- Master RAII: Resource Acquisition Is Initialization
- Understand why modern C++ avoids raw new/delete

### Core Concepts

#### 5.1 Stack vs. Heap

```cpp
#include <iostream>

int main() {
    // STACK: Automatic storage, fixed size, fast
    int stackVar = 42;  // Created on stack
    int stackArray[100];  // Fixed size, known at compile time

    // HEAP: Dynamic storage, flexible size, slower
    int* heapVar = new int(42);  // Allocated on heap
    int* heapArray = new int[100];  // Size can be variable

    std::cout << "Stack variable: " << stackVar << "\n";
    std::cout << "Heap variable: " << *heapVar << "\n";

    // MUST manually free heap memory
    delete heapVar;
    delete[] heapArray;  // Note: delete[] for arrays

    return 0;
    // stackVar and stackArray automatically destroyed here
}
```

**When to use heap:**

- Need size determined at runtime
- Data must outlive current scope
- Object too large for stack (typically >1MB)

**Critical rule:** Every `new` must have exactly one corresponding `delete`. Every `new[]` must have exactly one `delete[]`.

#### 5.2 Memory Leaks and Dangling Pointers

```cpp
#include <iostream>

void memoryLeak() {
    int* ptr = new int(100);
    // Forgot to delete ptr—memory leaked!
}

void danglingPointer() {
    int* ptr = new int(50);
    delete ptr;
    // ptr still contains the address, but memory is freed
    // *ptr = 10;  // DANGER: undefined behavior!

    ptr = nullptr;  // Good practice: nullify after delete
}

int main() {
    memoryLeak();
    danglingPointer();

    return 0;
}
```

**Common issues:**

- **Memory leak:** Allocate but never free → program uses more memory over time
- **Dangling pointer:** Use pointer after freeing → undefined behavior, crashes
- **Double delete:** Delete same memory twice → undefined behavior

#### 5.3 RAII: The C++ Way

```cpp
#include <iostream>
#include <vector>

// Poor approach: manual memory management
void poorApproach() {
    int* data = new int[100];

    // Complex logic here...
    // If exception thrown or early return, memory leaked!

    delete[] data;
}

// RAII approach: object lifetime manages resources
void goodApproach() {
    std::vector<int> data(100);  // Allocates memory

    // Complex logic here...
    // Even if exception thrown, vector destructor automatically frees memory

}  // data destroyed, memory freed automatically

int main() {
    goodApproach();
    return 0;
}
```

**RAII Principle:**

- Acquire resource in constructor
- Release resource in destructor
- Leverage automatic object lifetime management

**Why this matters:** In modern C++, you rarely use raw `new`/`delete`. RAII containers and smart pointers handle memory for you.

#### 5.4 Vectors: The Safe Alternative to Arrays

```cpp
#include <iostream>
#include <vector>

int main() {
    // Vector: dynamic array with automatic memory management
    std::vector<int> numbers;  // Empty vector

    // Add elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements
    std::cout << "First: " << numbers[0] << "\n";
    std::cout << "Size: " << numbers.size() << "\n";

    // Safe access with bounds checking
    std::cout << "At index 1: " << numbers.at(1) << "\n";
    // numbers.at(100);  // Throws exception if out of bounds

    // Iterate
    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    // Range-based for loop (C++11)
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
    // Vector automatically frees its memory
}
```

**Why vectors are better than arrays:**

- Know their own size
- Grow dynamically
- Manage memory automatically
- Provide bounds-checked access with `.at()`
- Can be returned from functions safely

#### 5.5 Vector Operations

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Add elements
    v.push_back(6);           // Add to end

    // Remove elements
    v.pop_back();             // Remove last element

    // Insert at position
    v.insert(v.begin() + 2, 99);  // Insert 99 at index 2

    // Remove at position
    v.erase(v.begin() + 3);   // Remove element at index 3

    // Clear all elements
    v.clear();

    // Check if empty
    if (v.empty()) {
        std::cout << "Vector is empty\n";
    }

    // Reserve capacity (optimization)
    v.reserve(100);  // Pre-allocate memory for 100 elements

    return 0;
}
```

**Performance considerations:**

- `push_back()` is amortized O(1)—occasionally resizes, but efficient overall
- `insert()` and `erase()` in middle are O(n)—avoid in tight loops
- Reserve capacity if you know approximate size

### Common Mistakes

1. **Using vector after it's been moved:**

   ```cpp
   std::vector<int> v1 = {1, 2, 3};
   std::vector<int> v2 = std::move(v1);
   // v1 is now in "moved-from" state—don't use it!
   ```

2. **Iterating with index but using size() in condition:**

   ```cpp
   std::vector<int> v = {1, 2, 3};
   for (int i = 0; i < v.size(); ++i) {  // Careful: size() is unsigned
       if (i == -1) { /* ... */ }  // Always false! Comparing signed and unsigned
   }
   ```

3. **Returning reference to local vector:**
   ```cpp
   std::vector<int>& badFunction() {
       std::vector<int> v = {1, 2, 3};
       return v;  // DANGER: v is destroyed after return
   }
   ```

### Exercises

1. **Dynamic Array Class**  
   Create a simple class that wraps a dynamic array (using new[]) with proper destructor.  
   Question: What happens if you forget the destructor?

2. **Vector Statistics**  
   Write functions that operate on `std::vector<int>`: sum, mean, median, mode.  
   Question: How do you handle an empty vector?

3. **Remove Duplicates**  
   Write `std::vector<int> removeDuplicates(const std::vector<int>& v)` that returns a vector with no duplicates.  
   Hint: Use a second vector or sort first.

4. **Memory Leak Detector Experiment**  
   Create intentional memory leaks and use a tool (Valgrind on Linux, Instruments on macOS) to detect them.

### Mini-Project: Dynamic Text Buffer

Create a class `TextBuffer` that:

- Stores lines of text using `std::vector<std::string>`
- Supports operations: add line, remove line, insert line, search
- Implements RAII properly (no manual memory management)
- Provides save-to-file and load-from-file functionality
- Demonstrates understanding of dynamic memory and RAII principles

---

## Week 6: Object-Oriented Programming Fundamentals

### Learning Objectives

- Understand classes as user-defined types
- Learn encapsulation: public vs. private
- Master constructors, destructors, and the Rule of Three
- Recognize when OOP is appropriate (and when it's not)
- Understand member functions vs. free functions

### Core Concepts

#### 6.1 Classes: Encapsulating Data and Behavior

```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    // Private data: implementation details hidden
    std::string ownerName;
    double balance;

public:
    // Constructor: initializes object
    BankAccount(const std::string& name, double initialBalance)
        : ownerName(name), balance(initialBalance) {
        // Member initializer list preferred over assignment
    }

    // Public interface: operations clients can perform
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cout << "Invalid deposit amount\n";
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {  // const: doesn't modify object
        return balance;
    }

    void printInfo() const {
        std::cout << "Owner: " << ownerName << ", Balance: $" << balance << "\n";
    }
};

int main() {
    BankAccount account("Alice", 1000.0);

    account.deposit(500);
    account.withdraw(200);
    account.printInfo();

    // account.balance = 9999;  // ERROR: balance is private

    return 0;
}
```

**Key principles:**

- **Encapsulation:** Hide implementation details, expose only necessary interface
- **Invariants:** Class maintains valid state (e.g., balance is always correct)
- **Const-correctness:** Mark read-only methods as `const`

#### 6.2 Constructors and Initialization

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Default constructor
    Person() : name("Unknown"), age(0) {
        std::cout << "Default constructor\n";
    }

    // Parameterized constructor
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Parameterized constructor\n";
    }

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor\n";
    }

    void print() const {
        std::cout << name << ", " << age << " years old\n";
    }
};

int main() {
    Person p1;                      // Default constructor
    Person p2("Bob", 25);           // Parameterized constructor
    Person p3 = p2;                 // Copy constructor
    Person p4(p2);                  // Copy constructor (explicit)

    p2.print();
    p3.print();

    return 0;
}
```

**Constructor guidelines:**

- Use member initializer lists (more efficient)
- Initialize all members
- Consider providing multiple constructors for convenience
- Default constructor is only generated if you don't define any constructor

#### 6.3 Destructors and Resource Management

```cpp
#include <iostream>

class FileHandle {
private:
    std::string filename;
    bool isOpen;

public:
    FileHandle(const std::string& name) : filename(name), isOpen(false) {
        std::cout << "Opening file: " << filename << "\n";
        isOpen = true;
    }

    ~FileHandle() {  // Destructor: called when object is destroyed
        if (isOpen) {
            std::cout << "Closing file: " << filename << "\n";
            isOpen = false;
        }
    }

    void write(const std::string& data) {
        if (isOpen) {
            std::cout << "Writing to " << filename << ": " << data << "\n";
        }
    }
};

int main() {
    {
        FileHandle file("data.txt");
        file.write("Hello, World!");
    }  // Destructor called here—file automatically closed

    std::cout << "File is now closed\n";

    return 0;
}
```

**Destructor principles:**

- Clean up resources (memory, files, connections)
- Called automatically when object goes out of scope
- Never throws exceptions
- Virtual if class is meant to be inherited (more on this later)

#### 6.4 The Rule of Three (C++03)

```cpp
#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:
    // Constructor
    MyString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {  // Self-assignment check
            delete[] data;  // Free old memory

            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    void print() const {
        std::cout << data << "\n";
    }
};

int main() {
    MyString s1("Hello");
    MyString s2 = s1;        // Copy constructor
    MyString s3("World");
    s3 = s1;                 // Copy assignment

    s1.print();
    s2.print();
    s3.print();

    return 0;
}
```

**Rule of Three:** If you define one of (destructor, copy constructor, copy assignment), you probably need all three.

**Why:** Classes managing resources need to handle copying and destruction properly.

**Modern alternative:** Use smart pointers or standard containers—avoid manual memory management.

#### 6.5 Const-Correctness

```cpp
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    int pages;

public:
    Book(const std::string& t, int p) : title(t), pages(p) {}

    // Const member function: promises not to modify object
    std::string getTitle() const {
        return title;
    }

    int getPages() const {
        return pages;
    }

    // Non-const member function: may modify object
    void setPages(int p) {
        pages = p;
    }

    void print() const {
        std::cout << title << " (" << pages << " pages)\n";
    }
};

void displayBook(const Book& book) {
    // Only const member functions can be called on const reference
    std::cout << book.getTitle() << "\n";
    book.print();

    // book.setPages(100);  // ERROR: setPages() is non-const
}

int main() {
    Book myBook("C++ Primer", 850);
    displayBook(myBook);

    return 0;
}
```

**Const-correctness guidelines:**

- Mark member functions `const` if they don't modify the object
- Use `const` references for parameters when you don't need to modify
- Enables passing objects to functions that expect const references

### Common Mistakes

1. **Forgetting to initialize members:**

   ```cpp
   class BadClass {
       int value;  // Not initialized!
   public:
       BadClass() {}  // value has garbage
   };
   ```

2. **Shallow copy with pointers:**

   ```cpp
   class BadCopy {
       int* data;
   public:
       BadCopy(const BadCopy& other) {
           data = other.data;  // Both objects share same pointer!
       }
   };
   ```

3. **Returning reference to local variable:**
   ```cpp
   class Bad {
   public:
       const std::string& getName() const {
           std::string name = "temp";
           return name;  // DANGER: name destroyed after return
       }
   };
   ```

### Exercises

1. **Rectangle Class**  
   Create a `Rectangle` class with width and height. Include methods for area, perimeter, and scaling.  
   Question: Should width and height be modifiable after construction?

2. **Vector2D Class**  
   Create a class for 2D vectors with operations: addition, subtraction, dot product, magnitude.  
   Question: Should these be member functions or free functions?

3. **Stack Implementation**  
   Implement a `Stack` class using `std::vector<int>` internally. Provide push, pop, top, isEmpty.  
   Question: How do you handle popping from an empty stack?

4. **Date Class**  
   Create a `Date` class that validates dates and provides comparison operators.  
   Question: How do you ensure invalid dates can't be constructed?

### Mini-Project: Library Management System

Create classes for:

- `Book`: title, author, ISBN, availability status
- `Member`: name, ID, list of borrowed books
- `Library`: collection of books, list of members

Implement operations:

- Add/remove books and members
- Borrow/return books (with validation)
- Search books by title or author
- Display member borrowing history

Demonstrate:

- Proper encapsulation
- Const-correctness
- RAII principles
- Relationships between classes

---

## Week 7: STL Containers Deep Dive

### Learning Objectives

- Master fundamental STL containers: vector, deque, list
- Understand associative containers: set, map, multiset, multimap
- Learn unordered containers: unordered_set, unordered_map
- Choose appropriate containers based on requirements
- Understand iterator concepts and categories

### Core Concepts

#### 7.1 Container Selection Guide

**Decision tree:**

1. Need key-value pairs? → map or unordered_map
2. Need ordered elements? → set, map (ordered), or vector (with sort)
3. Need fast lookup? → unordered_set, unordered_map
4. Need frequent insertion/deletion at ends? → deque or vector
5. Need frequent insertion/deletion in middle? → list
6. Default choice: vector

#### 7.2 Vector (Dynamic Array)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9};

    // Access
    std::cout << "First: " << v.front() << "\n";
    std::cout << "Last: " << v.back() << "\n";

    // Modify
    v.push_back(7);
    v.pop_back();

    // Sort
    std::sort(v.begin(), v.end());

    // Search
    auto it = std::find(v.begin(), v.end(), 8);
    if (it != v.end()) {
        std::cout << "Found 8 at index " << (it - v.begin()) << "\n";
    }

    // Iterate
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
```

**When to use vector:**

- Random access needed (O(1))
- Memory locality important (cache-friendly)
- Size known approximately
- Infrequent insertions/deletions in middle

**Complexity:**

- Access: O(1)
- Insert/delete at end: O(1) amortized
- Insert/delete in middle: O(n)

#### 7.3 Set (Ordered Unique Elements)

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> numbers = {5, 2, 8, 2, 1, 9, 5};  // Duplicates ignored

    // Automatically sorted: 1, 2, 5, 8, 9
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Insert
    numbers.insert(3);
    numbers.insert(2);  // Ignored (already exists)

    // Search (O(log n))
    if (numbers.count(5) > 0) {
        std::cout << "5 is in the set\n";
    }

    // Remove
    numbers.erase(8);

    // Find (returns iterator)
    auto it = numbers.find(9);
    if (it != numbers.end()) {
        std::cout << "Found: " << *it << "\n";
    }

    return 0;
}
```

**When to use set:**

- Need unique elements
- Need elements in sorted order
- Frequent membership tests

**Complexity:**

- Insert/delete/search: O(log n)

#### 7.4 Map (Key-Value Pairs, Ordered)

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages;

    // Insert
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 35;

    // Access (creates entry if doesn't exist!)
    std::cout << "Alice's age: " << ages["Alice"] << "\n";

    // Safe access (doesn't create entry)
    auto it = ages.find("David");
    if (it != ages.end()) {
        std::cout << "David's age: " << it->second << "\n";
    } else {
        std::cout << "David not found\n";
    }

    // Iterate (sorted by key)
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    // Check existence
    if (ages.count("Bob") > 0) {
        std::cout << "Bob exists\n";
    }

    return 0;
}
```

**Critical warning:** `map[key]` creates an entry if key doesn't exist. Use `.find()` or `.count()` to check first.

**When to use map:**

- Key-value associations
- Keys need to be sorted
- Moderate number of elements (<10,000 typically)

**Complexity:**

- Insert/delete/search: O(log n)

#### 7.5 Unordered Map (Hash Table)

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> wordCount;

    std::string text[] = {"apple", "banana", "apple", "cherry", "banana", "apple"};

    // Count word frequencies
    for (const auto& word : text) {
        wordCount[word]++;  // Default-initializes to 0 if not exists
    }

    // Display results (unordered)
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
```

**When to use unordered_map:**

- Don't need sorted keys
- Need fastest possible lookup (O(1) average)
- Large datasets

**Trade-off:** Faster than map on average, but worst-case O(n) if hash collisions occur.

#### 7.6 Container Comparison Example

```cpp
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

// Problem: Remove duplicates from a collection

// Approach 1: Using set
std::vector<int> removeDuplicatesSet(const std::vector<int>& v) {
    std::set<int> uniqueElements(v.begin(), v.end());
    return std::vector<int>(uniqueElements.begin(), uniqueElements.end());
    // Result is sorted
}

// Approach 2: Using unordered_set
std::vector<int> removeDuplicatesUnordered(const std::vector<int>& v) {
    std::unordered_set<int> uniqueElements(v.begin(), v.end());
    return std::vector<int>(uniqueElements.begin(), uniqueElements.end());
    // Result is unordered, but faster
}

// Approach 3: Sort and unique
std::vector<int> removeDuplicatesSort(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
    return v;
    // Result is sorted, modifies in-place
}

int main() {
    std::vector<int> data = {5, 2, 8, 2, 1, 9, 5, 1};

    auto result1 = removeDuplicatesSet(data);
    auto result2 = removeDuplicatesUnordered(data);
    auto result3 = removeDuplicatesSort(data);

    // Compare approaches based on requirements:
    // - Need sorted result? Use set or sort+unique
    // - Don't care about order? Use unordered_set (fastest)
    // - In-place modification OK? Use sort+unique (memory efficient)

    return 0;
}
```

**Design lesson:** There's no single "best" solution. Choose based on requirements.

#### 7.7 Iterators: The Bridge Between Containers and Algorithms

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Iterators generalize access to container elements
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";  // Dereference iterator
    }
    std::cout << "\n";

    // Algorithms work with iterators, not containers directly
    auto it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        std::cout << "Found: " << *it << "\n";
    }

    // Same algorithm works with different containers
    std::list<int> lst = {1, 2, 3, 4, 5};
    auto it2 = std::find(lst.begin(), lst.end(), 3);
    if (it2 != lst.end()) {
        std::cout << "Found in list: " << *it2 << "\n";
    }

    return 0;
}
```

**Key insight:** Iterators decouple algorithms from containers. Write algorithms once, work with any container.

### Common Mistakes

1. **Invalidating iterators:**

   ```cpp
   std::vector<int> v = {1, 2, 3, 4, 5};
   for (auto it = v.begin(); it != v.end(); ++it) {
       if (*it == 3) {
           v.erase(it);  // Invalidates iterator!
           // it++; would be undefined behavior
       }
   }
   ```

2. **Accidentally creating map entries:**

   ```cpp
   std::map<std::string, int> m;
   if (m["key"] == 0) {  // Creates entry if doesn't exist!
       // ...
   }
   ```

3. **Assuming map iteration order matches insertion:**
   - `std::map`: always sorted by key
   - `std::unordered_map`: arbitrary order
   - Neither preserves insertion order

### Exercises

1. **Word Frequency Counter**  
   Read text and count word frequencies using `unordered_map`.  
   Question: How do you handle case sensitivity?

2. **Unique Elements**  
   Compare performance of set vs. unordered_set for large datasets.  
   Question: When does ordering overhead matter?

3. **Phone Book**  
   Implement a phone book using `map<string, string>`.  
   Operations: add, lookup, remove, display all.

4. **Set Operations**  
   Implement union, intersection, difference for `std::set<int>`.  
   Hint: Use `std::set_union`, `std::set_intersection`, etc.

5. **Top K Elements**  
   Find the K most frequent elements in a vector.  
   Hint: Use `unordered_map` for counting, then sort.

### Mini-Project: Contact Management System

Create a contact manager that:

- Stores contacts with name, phone, email, address
- Uses `std::map<std::string, Contact>` for storage (keyed by name)
- Supports: add, remove, search, update, list all (sorted)
- Implements search by phone or email (use additional indexes)
- Demonstrates choosing appropriate containers for different access patterns

**Bonus:** Compare performance with `unordered_map` as underlying storage.

---

## Week 8: STL Algorithms and Functional Programming

### Learning Objectives

- Master common STL algorithms: find, sort, transform, accumulate
- Understand algorithm categories and requirements
- Learn lambda expressions and functional programming in C++
- Prefer algorithms over manual loops
- Recognize when custom algorithms are needed

### Core Concepts

#### 8.1 Non-Modifying Algorithms

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Find
    auto it = std::find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        std::cout << "Found: " << *it << "\n";
    }

    // Find with predicate
    auto it2 = std::find_if(v.begin(), v.end(), [](int x) { return x > 7; });
    if (it2 != v.end()) {
        std::cout << "First element > 7: " << *it2 << "\n";
    }

    // Count
    int evenCount = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Even numbers: " << evenCount << "\n";

    // All, any, none
    bool allPositive = std::all_of(v.begin(), v.end(), [](int x) { return x > 0; });
    bool anyLarge = std::any_of(v.begin(), v.end(), [](int x) { return x > 100; });
    bool noneNegative = std::none_of(v.begin(), v.end(), [](int x) { return x < 0; });

    std::cout << "All positive: " << allPositive << "\n";
    std::cout << "Any > 100: " << anyLarge << "\n";
    std::cout << "None negative: " << noneNegative << "\n";

    return 0;
}
```

**Key insight:** Algorithms + predicates (lambdas) express intent more clearly than manual loops.

#### 8.2 Lambda Expressions

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9, 3};

    // Basic lambda: [captures](parameters) { body }
    auto isEven = [](int x) { return x % 2 == 0; };

    // Lambda with capture
    int threshold = 5;
    auto isAboveThreshold = [threshold](int x) { return x > threshold; };

    // Lambda with mutable capture
    int count = 0;
    auto counter = [count](int x) mutable { return ++count; };

    // Use lambdas with algorithms
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });  // Descending

    std::cout << "Sorted descending: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // Count elements above threshold
    int aboveCount = std::count_if(v.begin(), v.end(), isAboveThreshold);
    std::cout << "Count > " << threshold << ": " << aboveCount << "\n";

    return 0;
}
```

**Lambda captures:**

- `[]`: Capture nothing
- `[x]`: Capture `x` by value
- `[&x]`: Capture `x` by reference
- `[=]`: Capture all by value
- `[&]`: Capture all by reference
- `[=, &x]`: Capture all by value except `x` by reference

**Design principle:** Prefer explicit captures over `[=]` or `[&]` for clarity.

#### 8.3 Modifying Algorithms

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result(v.size());

    // Transform: apply function to each element
    std::transform(v.begin(), v.end(), result.begin(), [](int x) { return x * x; });

    std::cout << "Squared: ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";

    // Replace
    std::replace(v.begin(), v.end(), 3, 99);

    // Remove (doesn't actually delete—returns new end iterator)
    auto newEnd = std::remove(v.begin(), v.end(), 99);
    v.erase(newEnd, v.end());  // Actually remove from container

    // Fill
    std::fill(v.begin(), v.end(), 0);

    // Generate
    int n = 0;
    std::generate(v.begin(), v.end(), [&n]() { return ++n; });

    std::cout << "Generated: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
```

**Critical understanding:** `std::remove` doesn't change container size. Use erase-remove idiom: `v.erase(std::remove(...), v.end())`.

#### 8.4 Sorting and Partitioning

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // Sort ascending
    std::sort(v.begin(), v.end());

    // Sort descending
    std::sort(v.begin(), v.end(), std::greater<int>());

    // Sort with custom comparator
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    // Partial sort: get smallest 3 elements in sorted order
    std::partial_sort(v.begin(), v.begin() + 3, v.end());

    // Nth element: partition around nth element
    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    std::cout << "Median: " << v[v.size() / 2] << "\n";

    // Partition: separate elements based on predicate
    auto it = std::partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Evens then odds:\n";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
```

**Performance notes:**

- `std::sort`: O(n log n) average, best general-purpose sort
- `std::partial_sort`: O(n log k) where k is number of elements to sort
- `std::nth_element`: O(n) average, useful for medians/percentiles

#### 8.5 Numeric Algorithms

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Accumulate (sum)
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Sum: " << sum << "\n";

    // Accumulate with custom operation (product)
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << "\n";

    // Partial sum (cumulative sum)
    std::vector<int> cumSum(v.size());
    std::partial_sum(v.begin(), v.end(), cumSum.begin());

    std::cout << "Cumulative sum: ";
    for (int x : cumSum) std::cout << x << " ";
    std::cout << "\n";

    // Inner product (dot product)
    std::vector<int> v2 = {2, 2, 2, 2, 2};
    int dotProduct = std::inner_product(v.begin(), v.end(), v2.begin(), 0);
    std::cout << "Dot product: " << dotProduct << "\n";

    // Min and max element
    auto minIt = std::min_element(v.begin(), v.end());
    auto maxIt = std::max_element(v.begin(), v.end());
    std::cout << "Min: " << *minIt << ", Max: " << *maxIt << "\n";

    return 0;
}
```

#### 8.6 Algorithm Composition

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Problem: Sum of squares of even numbers
int sumOfSquaresOfEvens(const std::vector<int>& v) {
    std::vector<int> evens;

    // Filter evens
    std::copy_if(v.begin(), v.end(), std::back_inserter(evens),
                 [](int x) { return x % 2 == 0; });

    // Square them
    std::transform(evens.begin(), evens.end(), evens.begin(),
                   [](int x) { return x * x; });

    // Sum
    return std::accumulate(evens.begin(), evens.end(), 0);
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int result = sumOfSquaresOfEvens(numbers);
    std::cout << "Sum of squares of evens: " << result << "\n";  // 2^2 + 4^2 + 6^2 + 8^2 + 10^2 = 220

    return 0;
}
```

**Design principle:** Compose simple algorithms rather than writing complex loops. More readable and testable.

### When NOT to Use Algorithms

```cpp
// Sometimes a loop is clearer:

// Algorithm approach: complex
std::for_each(v.begin(), v.end(), [&](int x) {
    if (x > threshold) {
        process(x);
        updateState();
    }
});

// Loop approach: clearer intent
for (int x : v) {
    if (x > threshold) {
        process(x);
        updateState();
    }
}
```

**Guideline:** Use algorithms when they clarify intent. Use loops when control flow is complex.

### Common Mistakes

1. **Forgetting erase after remove:**

   ```cpp
   std::remove(v.begin(), v.end(), 5);  // Doesn't change size!
   // Must: v.erase(std::remove(...), v.end());
   ```

2. **Modifying container while iterating:**

   ```cpp
   for (auto it = v.begin(); it != v.end(); ++it) {
       v.push_back(*it);  // DANGER: invalidates iterators
   }
   ```

3. **Using wrong algorithm for unsorted data:**
   ```cpp
   std::binary_search(v.begin(), v.end(), 5);  // Only works if v is sorted!
   ```

### Exercises

1. **Filter and Transform**  
   From a vector of integers, get squares of all odd numbers greater than 5.  
   Use `copy_if`, `transform`, and lambdas.

2. **String Processing**  
   Read lines of text, convert to lowercase, remove duplicates, sort alphabetically.  
   Use appropriate algorithms.

3. **Statistical Functions**  
   Implement mean, median, mode, standard deviation using STL algorithms.

4. **Algorithm Benchmark**  
   Compare performance: manual loop vs. std::find vs. binary_search on sorted data.

5. **Custom Algorithm**  
   Implement `my_unique` that removes consecutive duplicates (like `std::unique`).  
   Signature: `template<typename Iter> Iter my_unique(Iter first, Iter last)`

### Mini-Project: Data Analysis Pipeline

Create a data processing pipeline that:

- Reads numerical data from file (using `std::istream_iterator`)
- Filters outliers (values beyond 2 standard deviations)
- Transforms data (normalize to 0-1 range)
- Computes statistics (min, max, mean, median, std dev)
- Groups data into bins (histogram)
- All operations use STL algorithms, not manual loops

Demonstrate:

- Algorithm composition
- Lambda expressions with captures
- Functional programming style
- Performance and clarity benefits of algorithms

---

# PHASE 3: ADVANCED APPLICATION (Weeks 9-12)

## Week 9: Modern C++ Features (C++11/14/17)

### Learning Objectives

- Master smart pointers: unique_ptr, shared_ptr, weak_ptr
- Understand move semantics and perfect forwarding
- Learn range-based for loops and structured bindings
- Master std::optional and std::variant for safer code
- Recognize when and how to use modern features

### Core Concepts

#### 9.1 Smart Pointers: Automatic Memory Management

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Resource {
public:
    Resource(int id) : id_(id) {
        std::cout << "Resource " << id_ << " created\n";
    }

    ~Resource() {
        std::cout << "Resource " << id_ << " destroyed\n";
    }

    void use() const {
        std::cout << "Using resource " << id_ << "\n";
    }

private:
    int id_;
};

int main() {
    // unique_ptr: Exclusive ownership
    {
        std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>(1);
        ptr1->use();

        // std::unique_ptr<Resource> ptr2 = ptr1;  // ERROR: can't copy
        std::unique_ptr<Resource> ptr2 = std::move(ptr1);  // Transfer ownership

        if (!ptr1) {
            std::cout << "ptr1 is now null\n";
        }

        ptr2->use();
    }  // ptr2 automatically deleted

    // shared_ptr: Shared ownership (reference counting)
    {
        std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(2);
        std::cout << "Reference count: " << ptr1.use_count() << "\n";

        {
            std::shared_ptr<Resource> ptr2 = ptr1;  // Can copy
            std::cout << "Reference count: " << ptr1.use_count() << "\n";

            ptr1->use();
            ptr2->use();
        }  // ptr2 goes out of scope, count decreases

        std::cout << "Reference count: " << ptr1.use_count() << "\n";
    }  // Last reference goes away, resource deleted

    return 0;
}
```

**When to use which:**

- **unique_ptr:** Default choice for ownership—lightweight, no overhead
- **shared_ptr:** When multiple owners need access—has reference counting overhead
- **weak_ptr:** Break circular references with shared_ptr
- **Raw pointer:** Non-owning reference (observer), or legacy interfaces

**Critical rule:** Never use `new` and `delete` directly in modern C++. Use smart pointers.

#### 9.2 Move Semantics

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class BigData {
private:
    std::vector<int> data;
    std::string name;

public:
    // Constructor
    BigData(const std::string& n, size_t size) : name(n), data(size, 0) {
        std::cout << "Constructing " << name << "\n";
    }

    // Copy constructor (expensive for large data)
    BigData(const BigData& other) : name(other.name), data(other.data) {
        std::cout << "Copying " << name << "\n";
    }

    // Move constructor (cheap—just steal resources)
    BigData(BigData&& other) noexcept
        : name(std::move(other.name)), data(std::move(other.data)) {
        std::cout << "Moving " << name << "\n";
    }

    // Copy assignment
    BigData& operator=(const BigData& other) {
        if (this != &other) {
            name = other.name;
            data = other.data;
            std::cout << "Copy-assigning " << name << "\n";
        }
        return *this;
    }

    // Move assignment
    BigData& operator=(BigData&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            data = std::move(other.data);
            std::cout << "Move-assigning " << name << "\n";
        }
        return *this;
    }
};

int main() {
    BigData obj1("obj1", 1000000);

    // Move constructor
    BigData obj2 = std::move(obj1);
    // obj1 is now in valid but unspecified state—don't use it!

    // Move assignment
    BigData obj3("obj3", 1000000);
    obj3 = std::move(obj2);

    return 0;
}
```

**Key insights:**

- **Move semantics:** Transfer ownership of resources instead of copying
- **Performance:** Moves are typically O(1), copies are O(n)
- **When moves happen:** Returning local objects, pushing into containers, explicit `std::move`

**Rule of Five:** If you define any of (destructor, copy constructor, copy assignment, move constructor, move assignment), consider defining all five.

#### 9.3 Optional: Representing Optional Values

```cpp
#include <iostream>
#include <optional>
#include <string>

// Before optional: use special value or bool parameter
int findValueOld(const std::vector<int>& v, int target, bool& found) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == target) {
            found = true;
            return i;
        }
    }
    found = false;
    return -1;  // Magic value—what if -1 is valid?
}

// With optional: clear semantics
std::optional<size_t> findValue(const std::vector<int>& v, int target) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == target) {
            return i;  // Implicitly constructs optional
        }
    }
    return std::nullopt;  // Explicit "no value"
}

int main() {
    std::vector<int> data = {10, 20, 30, 40, 50};

    auto result = findValue(data, 30);

    if (result) {  // or result.has_value()
        std::cout << "Found at index: " << *result << "\n";
    } else {
        std::cout << "Not found\n";
    }

    // With value_or: provide default
    size_t index = findValue(data, 99).value_or(0);

    return 0;
}
```

**When to use optional:**

- Function might not have a result
- Clearer than magic values (-1, nullptr, empty string)
- Better than exceptions for expected failures

#### 9.4 Variant: Type-Safe Union

```cpp
#include <iostream>
#include <variant>
#include <string>

// Before variant: unions are unsafe
union UnsafeData {
    int i;
    double d;
    // Can't have string—no destructor support
};

// With variant: type-safe
using SafeData = std::variant<int, double, std::string>;

void processData(const SafeData& data) {
    // Visit with lambda
    std::visit([](const auto& value) {
        std::cout << "Value: " << value << "\n";
    }, data);

    // Check and access specific type
    if (std::holds_alternative<int>(data)) {
        int value = std::get<int>(data);
        std::cout << "It's an int: " << value << "\n";
    }

    // Try to get (throws if wrong type)
    try {
        std::string s = std::get<std::string>(data);
        std::cout << "String: " << s << "\n";
    } catch (const std::bad_variant_access&) {
        std::cout << "Not a string\n";
    }
}

int main() {
    SafeData data1 = 42;
    SafeData data2 = 3.14;
    SafeData data3 = std::string("Hello");

    processData(data1);
    processData(data2);
    processData(data3);

    return 0;
}
```

**When to use variant:**

- Variable can be one of several types
- More type-safe than void\* or inheritance
- Pattern matching with std::visit

#### 9.5 Structured Bindings (C++17)

```cpp
#include <iostream>
#include <map>
#include <tuple>

std::tuple<int, double, std::string> getData() {
    return {42, 3.14, "Hello"};
}

int main() {
    // Structured bindings for tuples
    auto [id, value, name] = getData();
    std::cout << id << ", " << value << ", " << name << "\n";

    // Structured bindings for maps
    std::map<std::string, int> ages = {{"Alice", 30}, {"Bob", 25}};

    for (const auto& [name, age] : ages) {
        std::cout << name << " is " << age << " years old\n";
    }

    // Structured bindings for arrays
    int arr[] = {1, 2, 3};
    auto [a, b, c] = arr;

    return 0;
}
```

**Benefit:** Clearer code when dealing with pairs, tuples, and structured data.

#### 9.6 Range-Based For Loops

```cpp
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Read-only
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // Modify elements
    for (auto& elem : v) {
        elem *= 2;
    }

    // Copy (avoid unless needed)
    for (auto elem : v) {
        elem *= 2;  // Modifies copy, not original
    }

    // With maps
    std::map<std::string, int> m = {{"a", 1}, {"b", 2}};
    for (const auto& [key, value] : m) {
        std::cout << key << ": " << value << "\n";
    }

    return 0;
}
```

**Guidelines:**

- `const auto&`: Read-only, avoid copies (most common)
- `auto&`: Modify elements
- `auto`: Copy (rare—only when you need independent copy)

### Common Mistakes

1. **Using unique_ptr after move:**

   ```cpp
   auto ptr1 = std::make_unique<int>(42);
   auto ptr2 = std::move(ptr1);
   *ptr1 = 10;  // DANGER: ptr1 is null!
   ```

2. **Circular references with shared_ptr:**

   ```cpp
   struct Node {
       std::shared_ptr<Node> next;
   };
   // Creates cycle—memory leaked! Use weak_ptr for back-references.
   ```

3. **Forgetting to check optional:**
   ```cpp
   std::optional<int> opt;
   int value = *opt;  // DANGER: undefined if empty!
   ```

### Exercises

1. **Smart Pointer Comparison**  
   Implement a linked list with unique_ptr and shared_ptr. Compare implementation complexity.

2. **Move Semantics Benchmark**  
   Compare performance of copying vs. moving large vectors.

3. **Optional Error Handling**  
   Rewrite functions that return error codes to return `std::optional`.

4. **Variant State Machine**  
   Implement a simple state machine using `std::variant` for states.

### Mini-Project: Resource Manager

Create a resource management system that:

- Uses `unique_ptr` for owned resources
- Uses `shared_ptr` for resources shared across modules
- Returns `optional<Resource>` for lookup operations
- Uses `variant` for different resource types (Texture, Sound, Model)
- Demonstrates modern C++ memory safety

---

## Week 10: Error Handling and Defensive Programming

### Learning Objectives

- Master exception handling: when and how to use exceptions
- Understand RAII and exception safety
- Learn defensive programming techniques
- Recognize error handling patterns and trade-offs
- Write robust code that handles edge cases

### Core Concepts

#### 10.1 Exceptions: When and How

```cpp
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

class Account {
private:
    double balance;

public:
    Account(double initial) : balance(initial) {
        if (initial < 0) {
            throw std::invalid_argument("Initial balance cannot be negative");
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds");
        }
        balance -= amount;
    }

    double getBalance() const { return balance; }
};

int main() {
    try {
        Account account(1000);
        account.withdraw(500);
        std::cout << "Balance: " << account.getBalance() << "\n";

        account.withdraw(600);  // Will throw

    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
```

**When to use exceptions:**

- Exceptional conditions (not normal control flow)
- Constructor failures (can't return error code)
- Deep call stacks (avoid error code propagation)

**When NOT to use exceptions:**

- Performance-critical code
- Expected failures (use optional, error codes)
- Simple validation (return bool)

#### 10.2 Exception Safety Guarantees

```cpp
#include <iostream>
#include <vector>
#include <memory>

class SafeContainer {
private:
    std::vector<int> data;

public:
    // Strong exception safety: either succeeds or leaves state unchanged
    void addElement(int value) {
        // If push_back throws, container is unchanged
        data.push_back(value);
    }

    // Basic exception safety: invariants maintained, but state may change
    void addElements(const std::vector<int>& values) {
        for (int v : values) {
            data.push_back(v);  // If throws, some elements added
        }
    }

    // No-throw guarantee: never throws
    size_t size() const noexcept {
        return data.size();
    }
};
```

**Exception safety levels:**

1. **No-throw (noexcept):** Never throws, strongest guarantee
2. **Strong:** Operation succeeds completely or has no effect (transactional)
3. **Basic:** Invariants maintained, no resource leaks, but state may change
4. **No guarantee:** Anything can happen (avoid!)

**RAII ensures exception safety:** Resources cleaned up even if exception thrown.

#### 10.3 Custom Exceptions

```cpp
#include <iostream>
#include <exception>
#include <string>

class FileException : public std::runtime_error {
private:
    std::string filename_;

public:
    FileException(const std::string& filename, const std::string& message)
        : std::runtime_error(message), filename_(filename) {}

    const std::string& getFilename() const { return filename_; }
};

class FileReader {
public:
    void readFile(const std::string& filename) {
        // Simulate file operation
        if (filename.empty()) {
            throw FileException(filename, "Filename is empty");
        }

        // More file operations...
        throw FileException(filename, "File not found");
    }
};

int main() {
    FileReader reader;

    try {
        reader.readFile("data.txt");
    } catch (const FileException& e) {
        std::cerr << "File error: " << e.what() << "\n";
        std::cerr << "Filename: " << e.getFilename() << "\n";
    }

    return 0;
}
```

**Guidelines for custom exceptions:**

- Inherit from `std::exception` or derived class
- Store contextual information
- Implement `what()` for error message

#### 10.4 Defensive Programming: Input Validation

```cpp
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

class DateValidator {
public:
    static bool isValidDate(int day, int month, int year) {
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > daysInMonth(month, year)) return false;
        return true;
    }

private:
    static int daysInMonth(int month, int year) {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        return 31;
    }

    static bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (!DateValidator::isValidDate(d, m, y)) {
            throw std::invalid_argument("Invalid date");
        }
    }

    // Precondition: object must be in valid state
    void print() const {
        std::cout << day << "/" << month << "/" << year << "\n";
    }
};

int main() {
    try {
        Date validDate(15, 6, 2023);
        validDate.print();

        Date invalidDate(31, 2, 2023);  // Throws
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
```

**Defensive programming principles:**

- Validate all inputs
- Check preconditions
- Maintain class invariants
- Handle all error cases
- Fail fast and clearly

#### 10.5 Assertions for Debugging

```cpp
#include <iostream>
#include <cassert>

int divide(int a, int b) {
    assert(b != 0 && "Divisor cannot be zero");  // Debug check
    return a / b;
}

class Array {
private:
    int* data;
    size_t size;

public:
    Array(size_t s) : size(s) {
        assert(s > 0 && "Size must be positive");
        data = new int[size];
    }

    ~Array() {
        delete[] data;
    }

    int& operator[](size_t index) {
        assert(index < size && "Index out of bounds");  // Debug check
        return data[index];
    }
};
```

**Assertions vs. Exceptions:**

- **Assertions:** Check program logic, disabled in release builds
- **Exceptions:** Handle runtime errors, always active

**Use assertions for:** Invariants that should never be violated (programmer errors)
**Use exceptions for:** Errors that can occur at runtime (user input, file errors)

#### 10.6 Error Handling Patterns

```cpp
#include <iostream>
#include <optional>
#include <variant>
#include <string>

// Pattern 1: Optional (for expected failures)
std::optional<int> parseInt(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (...) {
        return std::nullopt;
    }
}

// Pattern 2: Variant (result or error)
std::variant<int, std::string> divide(int a, int b) {
    if (b == 0) {
        return std::string("Division by zero");
    }
    return a / b;
}

// Pattern 3: Error codes (C-style, legacy)
enum class ErrorCode {
    Success,
    InvalidInput,
    OutOfRange
};

ErrorCode getValue(int index, int* out) {
    if (index < 0) return ErrorCode::InvalidInput;
    if (index > 100) return ErrorCode::OutOfRange;
    *out = index * 2;
    return ErrorCode::Success;
}

int main() {
    // Pattern 1
    if (auto value = parseInt("123")) {
        std::cout << "Parsed: " << *value << "\n";
    } else {
        std::cout << "Parse failed\n";
    }

    // Pattern 2
    auto result = divide(10, 2);
    if (std::holds_alternative<int>(result)) {
        std::cout << "Result: " << std::get<int>(result) << "\n";
    } else {
        std::cout << "Error: " << std::get<std::string>(result) << "\n";
    }

    // Pattern 3
    int value;
    ErrorCode err = getValue(5, &value);
    if (err == ErrorCode::Success) {
        std::cout << "Value: " << value << "\n";
    }

    return 0;
}
```

### Exercises

1. **Safe Division Calculator**  
   Create a calculator that handles division by zero using different error strategies.

2. **String to Number Conversion**  
   Implement robust conversion functions using optional and exceptions.

3. **Configuration File Parser**  
   Read configuration file with error handling for missing files, invalid format, etc.

4. **Exception Safety Testing**  
   Create a class that manages resources and verify exception safety with deliberate throws.

### Mini-Project: Robust File Processor

Create a file processing system that:

- Reads files with comprehensive error handling
- Validates file format and content
- Uses RAII for file handles
- Provides detailed error messages
- Demonstrates all three exception safety levels
- Uses multiple error handling patterns appropriately

---

## Week 11: Templates and Generic Programming (Introduction)

### Learning Objectives

- Understand templates as compile-time code generation
- Learn function templates for generic algorithms
- Master class templates for generic containers
- Recognize template limitations and trade-offs
- Write type-safe, reusable code

### Core Concepts

#### 11.1 Function Templates

```cpp
#include <iostream>
#include <string>

// Generic max function
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple type parameters
template<typename T, typename U>
void print Pair(T first, U second) {
    std::cout << "(" << first << ", " << second << ")\n";
}

int main() {
    std::cout << max(5, 10) << "\n";           // int version
    std::cout << max(3.14, 2.71) << "\n";      // double version
    std::cout << max('a', 'z') << "\n";        // char version

    printPair(42, "hello");                    // int, const char*
    printPair(3.14, true);                     // double, bool

    return 0;
}
```

**How templates work:**

- Compiler generates separate function for each used type
- Type deduction from arguments (usually)
- Compile-time errors if type doesn't support operations

#### 11.2 Generic Algorithms with Templates

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <string>

// Generic find function
template<typename Iterator, typename T>
Iterator find(Iterator begin, Iterator end, const T& value) {
    for (auto it = begin; it != end; ++it) {
        if (*it == value) {
            return it;
        }
    }
    return end;
}

// Generic print function
template<typename Container>
void printContainer(const Container& c) {
    for (const auto& elem : c) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::list<std::string> lst = {"apple", "banana", "cherry"};

    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        std::cout << "Found: " << *it << "\n";
    }

    printContainer(v);
    printContainer(lst);

    return 0;
}
```

**Key insight:** Templates enable writing algorithms once that work with any compatible type.

#### 11.3 Class Templates

```cpp
#include <iostream>
#include <stdexcept>

template<typename T, size_t Size>
class Array {
private:
    T data[Size];

public:
    T& operator[](size_t index) {
        if (index >= Size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= Size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    constexpr size_t size() const { return Size; }

    T* begin() { return data; }
    T* end() { return data + Size; }
};

int main() {
    Array<int, 5> intArray;
    Array<double, 10> doubleArray;
    Array<std::string, 3> stringArray;

    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
    }

    for (int val : intArray) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
```

**Benefits:**

- Type-safe containers
- No runtime overhead (like macros, but safer)
- Compile-time size checking

#### 11.4 Template Specialization

```cpp
#include <iostream>
#include <cstring>

// Generic comparison
template<typename T>
bool areEqual(T a, T b) {
    return a == b;
}

// Specialization for C-strings
template<>
bool areEqual<const char*>(const char* a, const char* b) {
    return std::strcmp(a, b) == 0;
}

int main() {
    std::cout << areEqual(5, 5) << "\n";              // Generic version
    std::cout << areEqual("hello", "hello") << "\n";  // Specialized version

    return 0;
}
```

**Use cases:** Optimize for specific types or handle special cases.

#### 11.5 Template Constraints (Concepts - C++20 Preview)

```cpp
#include <iostream>
#include <type_traits>

// C++20 concept (if available)
// template<typename T>
// concept Numeric = std::is_arithmetic_v<T>;

// C++17 approach with enable_if
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(5, 10) << "\n";        // OK: int is numeric
    std::cout << add(3.14, 2.71) << "\n";   // OK: double is numeric

    // std::cout << add("a", "b") << "\n";  // ERROR: string not numeric

    return 0;
}
```

**Modern C++:** Concepts (C++20) make template requirements explicit and improve error messages.

### Common Mistakes

1. **Template code must be in headers:**

   ```cpp
   // file.h
   template<typename T>
   T max(T a, T b);  // Declaration only doesn't work!

   // Must include definition in header
   template<typename T>
   T max(T a, T b) { return (a > b) ? a : b; }
   ```

2. **Assuming type capabilities:**

   ```cpp
   template<typename T>
   void sort(T* arr, int size) {
       // Assumes T has operator<
       // Will fail at compile-time if T doesn't
   }
   ```

3. **Template bloat:**
   - Compiler generates code for each type used
   - Can increase binary size significantly

### Exercises

1. **Generic Swap**  
   Implement `template<typename T> void swap(T& a, T& b)`.

2. **Generic Container**  
   Implement a simple `Stack<T>` template class.

3. **Generic Algorithm**  
   Implement `template<typename Iter, typename Pred> Iter find_if(Iter begin, Iter end, Pred predicate)`.

4. **Template Specialization**  
   Create a generic `toString` function with specializations for different types.

### Mini-Project: Generic Data Structure Library

Create a small library with:

- `Array<T, Size>`: Fixed-size array
- `DynamicArray<T>`: Resizable array (like vector)
- `LinkedList<T>`: Singly-linked list
- Generic algorithms: find, sort, reverse, transform

Demonstrate:

- Function and class templates
- Iterator patterns
- Generic algorithm design
- Template specialization where beneficial

---

## Week 12: Best Practices, Performance, and Real-World Projects

### Learning Objectives

- Master code organization and project structure
- Understand compilation and linking
- Learn performance optimization principles
- Master debugging techniques and tools
- Complete an integrated real-world project

### Core Concepts

#### 12.1 Code Organization and Build Systems

```
project/
├── include/
│   ├── mylib/
│   │   ├── core.hpp
│   │   └── utils.hpp
├── src/
│   ├── core.cpp
│   └── utils.cpp
├── tests/
│   └── test_core.cpp
├── CMakeLists.txt
└── README.md
```

**Header (.hpp) vs Implementation (.cpp):**

```cpp
// core.hpp
#ifndef CORE_HPP
#define CORE_HPP

class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
};

#endif
```

```cpp
// core.cpp
#include "core.hpp"

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}
```

**Compilation process:**

1. Preprocessor: Handle #include, #define
2. Compiler: source → object files (.o)
3. Linker: object files → executable

#### 12.2 Performance Considerations

**When to optimize:**

1. After correctness is verified
2. After profiling identifies bottlenecks
3. When measurements show actual problem

**Common optimizations:**

```cpp
#include <iostream>
#include <vector>
#include <chrono>

// Inefficient: copies vector
void processVector(std::vector<int> v) {
    for (int& val : v) {
        val *= 2;
    }
}

// Efficient: reference avoids copy
void processVectorRef(std::vector<int>& v) {
    for (int& val : v) {
        val *= 2;
    }
}

// Measurement
void benchmark() {
    std::vector<int> data(1000000, 1);

    auto start = std::chrono::high_resolution_clock::now();
    processVectorRef(data);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time: " << duration.count() << "ms\n";
}
```

**Performance principles:**

- Measure, don't guess
- Avoid premature optimization
- Choose right data structure (O(n) vs O(log n) vs O(1))
- Minimize allocations in hot paths
- Use references to avoid copies
- Reserve capacity for containers when size known
- Profile to find actual bottlenecks

#### 12.3 Debugging Strategies

**Debugging tools:**

- GDB (Linux): `gdb ./program`
- LLDB (macOS): `lldb ./program`
- Visual Studio Debugger (Windows)
- VS Code debugger (all platforms)

**Debugging techniques:**

```cpp
// 1. Print statements (simple but effective)
void debugFunction(int x) {
    std::cout << "DEBUG: x = " << x << "\n";
    // More code...
}

// 2. Assertions for invariants
void processArray(int* arr, size_t size) {
    assert(arr != nullptr);
    assert(size > 0);
    // Process...
}

// 3. Logging levels
enum class LogLevel { DEBUG, INFO, WARNING, ERROR };

void log(LogLevel level, const std::string& message) {
    if (level >= LogLevel::INFO) {  // Filter by level
        std::cout << "[LOG] " << message << "\n";
    }
}
```

**Debugging process:**

1. Reproduce the bug consistently
2. Isolate the problem (binary search through code)
3. Form hypothesis about cause
4. Test hypothesis (breakpoints, prints, assertions)
5. Fix and verify
6. Add test to prevent regression

#### 12.4 Code Quality Checklist

**Readability:**

- Meaningful variable and function names
- Consistent formatting (use clang-format)
- Clear comments explaining why, not what
- Functions do one thing well
- Limited nesting depth (<3-4 levels)

**Correctness:**

- Handle all error cases
- Check boundary conditions
- No memory leaks (use RAII, smart pointers)
- Proper const-correctness
- Thread-safety if applicable

**Maintainability:**

- DRY: Don't Repeat Yourself
- SOLID principles (especially Single Responsibility)
- Encapsulation: hide implementation details
- Testable: functions with clear inputs/outputs

#### 12.5 Common Design Patterns

```cpp
// Singleton Pattern
class Database {
private:
    Database() {}  // Private constructor
    static Database* instance;

public:
    static Database* getInstance() {
        if (!instance) {
            instance = new Database();
        }
        return instance;
    }

    void query(const std::string& sql) {
        // Execute query
    }
};
Database* Database::instance = nullptr;

// Factory Pattern
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing circle\n"; }
};

class Square : public Shape {
public:
    void draw() override { std::cout << "Drawing square\n"; }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "circle") return std::make_unique<Circle>();
        if (type == "square") return std::make_unique<Square>();
        return nullptr;
    }
};

// RAII Resource Management
class FileHandle {
private:
    FILE* file;

public:
    FileHandle(const char* filename, const char* mode) {
        file = fopen(filename, mode);
        if (!file) throw std::runtime_error("Failed to open file");
    }

    ~FileHandle() {
        if (file) fclose(file);
    }

    // Prevent copying
    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    // Allow moving
    FileHandle(FileHandle&& other) noexcept : file(other.file) {
        other.file = nullptr;
    }

    FILE* get() { return file; }
};
```

### Final Capstone Project: Task Management System

**Requirements:**
Create a command-line task management application with:

**Core Features:**

1. Add tasks with: title, description, due date, priority, tags
2. List tasks with filtering (by status, priority, tag, date range)
3. Mark tasks complete/incomplete
4. Edit task details
5. Delete tasks
6. Search tasks by keyword
7. Save/load from file (persistence)
8. Statistics: total tasks, completion rate, overdue tasks

**Technical Requirements:**

- Use STL containers (vector, map, set, etc.) appropriately
- Implement RAII for file handling
- Use smart pointers for task objects
- Error handling with exceptions and optional
- Modern C++ features (lambdas, range-based for, structured bindings)
- Proper const-correctness
- Template function for generic filtering
- Unit tests for core functionality

**Architecture:**

```cpp
// Suggested structure
class Task {
    // Task data and methods
};

class TaskManager {
private:
    std::vector<std::unique_ptr<Task>> tasks;
    std::map<std::string, std::set<size_t>> tagIndex;  // Tag → task indices

public:
    void addTask(/* params */);
    std::vector<Task*> findTasks(/* filter criteria */);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    // More methods...
};

class CLI {
    // Command-line interface
public:
    void run();
private:
    void displayMenu();
    void handleCommand(const std::string& cmd);
};

int main() {
    CLI cli;
    cli.run();
    return 0;
}
```

**Evaluation Criteria:**

- Correctness: Does it work as specified?
- Code quality: Readable, maintainable, well-organized?
- Modern C++ usage: Appropriate use of STL, smart pointers, etc.?
- Error handling: Robust against invalid input?
- Performance: Efficient data structures chosen?
- Documentation: Clear comments and usage instructions?

**Extensions (Optional):**

- Recurring tasks
- Task dependencies
- Export to CSV/JSON
- Priorities with automatic sorting
- Reminders/notifications
- Multi-user support

---

## Curriculum Summary and Next Steps

### What You've Learned

**Weeks 1-4 (Foundation):**

- Programming fundamentals and mental models
- C++ syntax, types, control flow
- Functions and code organization
- Arrays, strings, basic algorithms

**Weeks 5-8 (Core Mastery):**

- Dynamic memory and RAII
- Object-oriented programming
- STL containers and their trade-offs
- STL algorithms and functional programming

**Weeks 9-12 (Advanced):**

- Modern C++ features (smart pointers, move semantics, optional, variant)
- Error handling and defensive programming
- Templates and generic programming
- Best practices, performance, debugging

### Beyond This Curriculum

**Next Topics to Explore:**

1. **Advanced Templates:**
   - Variadic templates
   - Template metaprogramming
   - Concepts (C++20)

2. **Concurrency:**
   - Threads and mutexes
   - std::async and futures
   - Lock-free programming

3. **Advanced STL:**
   - Custom allocators
   - Iterator adaptors
   - Ranges library (C++20)

4. **Build Systems:**
   - CMake mastery
   - Package managers (vcpkg, conan)

5. **Testing:**
   - Unit testing (Google Test, Catch2)
   - Integration testing
   - Test-driven development

6. **Specialized Domains:**
   - Network programming (Boost.Asio)
   - Graphics (OpenGL, Vulkan)
   - Game development
   - Embedded systems

### Recommended Resources

**Books:**

- _C++ Primer_ (5th Edition) by Lippman, Lajoie, Moo
- _Effective Modern C++_ by Scott Meyers
- _C++ Concurrency in Action_ by Anthony Williams
- _The C++ Programming Language_ (4th Edition) by Bjarne Stroustrup

**Online:**

- cppreference.com (comprehensive reference)
- CppCon talks on YouTube
- isocpp.org (C++ standards committee)

**Practice:**

- LeetCode, HackerRank, Codeforces (algorithms)
- Project Euler (mathematical problems)
- Open source contributions

---

## Final Notes

**Remember:**

- Understanding > memorization
- Correctness > performance (initially)
- Clarity > cleverness
- Practice consistently
- Read others' code
- Question everything: "Why this way?"

**You're now equipped to:**

- Write clean, idiomatic C++ code
- Choose appropriate STL tools
- Reason about performance and trade-offs
- Debug systematically
- Design maintainable software

**Keep learning, keep coding, and most importantly: keep asking "why?"**

Good luck on your C++ mastery journey! 🚀
