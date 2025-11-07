#ifndef SOLUTION_H
#define SOLUTION_H

/*
 * An integer greater than 1 is called a prime number if its only positive
 * divisors (factors) are 1 and itself.
 *
 * An Emirp (Prime spelt backwards) is a Prime that gives you a different Prime
 * when its digits are reversed.
 *
 * Example
 * ------
 *  17 -> Emirp as well as 71
 *
 *  Goal
 *  ----
 *  Decide whether a number N is a Non-prime or Prime or Emirp. Assume that 1 <
 * N < 1000000
 *
 * Procedure
 * ---------
 *  - Keep track of the list of prime values already computed with previous
 * operations
 *  	- Update it whenever it is missing elements for classifying a new input
 *  - For each testcase:
 *  	- Test if it is a Prime number
 *  	  - If yes, test if it is an Emirp by:
 *  	    - Reversing the number:
 *  	      - Convert the number to a string value
 *  	      - Reverse it from the leftmost character to the middle one by
 * swapping with the righmost corresponding character
 *  	      - Return the converted value to integer
 *  	    - Testing if the reverse is a Prime number
 *  	      - If yes return "emirp"
 *  	      - If not return "prime"
 *  	- If not return "not prime"
 *
 * Revision history:
 * Revised by Neil Taison Rigaud, October 2025
 *
 * */

#include <string>
#include <vector>

class Solution {
  std::vector<int> primes;

public:
  Solution() = default;
  ~Solution() = default;

  // Add problem-specific methods here
  std::string classify_prime(int n);

private:
  bool is_prime(int n);
  void update_prime_list(int n);
};

#endif // !SOLUTION_H
