#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Question 06: The Secret of a 3-Digit Number

#define MIN_VALUE 100
#define MAX_VALUE 999
#define DECIMAL_DIVISOR 10
#define N_DIGITS 3

typedef enum NUMBER_CATEGORY {
  NARCISSISTIC,
  PALINDROME,
  INCREASING,
  ORDINARY
} NUMBER_CATEGORY;

bool is_valid_number(const int number)
// Validates three digit numbers
{
  return number >= MIN_VALUE && number <= MAX_VALUE;
};

bool is_narcissistic(const int number) {
  if (!is_valid_number(number)) {
    return false;
  }
  // Sum of the cubes of the digits
  int cubic_digits_sum = 0;
  int tmp = number;
  int digit = 0;

  for (int i = 0; i < N_DIGITS; ++i) {
    digit = tmp % DECIMAL_DIVISOR;
    cubic_digits_sum += pow(digit, 3);
    tmp /= DECIMAL_DIVISOR;
  }

  return cubic_digits_sum == number;
}
bool is_palindrome(const int number) {
  if (!is_valid_number(number)) {
    return false;
  }

  // TODO(Neil): Support any number of digits apart from 3 digit numbers

  int tmp = number;
  int last_digit = tmp % DECIMAL_DIVISOR;
  tmp /= DECIMAL_DIVISOR * DECIMAL_DIVISOR;
  int first_digit = tmp % DECIMAL_DIVISOR;

  return first_digit == last_digit;
}

bool is_strictly_increasing(const int number) {
  if (!is_valid_number(number)) {
    return false;
  }

  int tmp = number;
  int lower_digit = tmp % DECIMAL_DIVISOR;
  tmp /= DECIMAL_DIVISOR;

  while (tmp) {
    if (lower_digit <= tmp % DECIMAL_DIVISOR)
      return false;
    lower_digit = tmp % DECIMAL_DIVISOR;
    tmp /= DECIMAL_DIVISOR;
  }

  return true;
}

NUMBER_CATEGORY reveal_secret(const int num) {
  if (is_narcissistic(num)) {
    return NARCISSISTIC;
  } else if (is_palindrome(num)) {
    return PALINDROME;
  } else if (is_strictly_increasing(num)) {
    return INCREASING;
  } else {
    return ORDINARY;
  }
}

void print_result(NUMBER_CATEGORY cat) {
  switch (cat) {
  case NARCISSISTIC:
    printf("Narcissistic Number");
    break;
  case PALINDROME:
    printf("Palindrome");
    break;
  case INCREASING:
    printf("Increasing");
    break;
  default:
    printf("Ordinary");
    break;
  }
}

int main() {
  int number = 0;
  scanf("%d", &number);

  // Check input
  if (!is_valid_number(number)) {
    printf("Invalid three digit number.\n");
    return EXIT_FAILURE;
  }

  print_result(reveal_secret(number));

  return EXIT_SUCCESS;
}
