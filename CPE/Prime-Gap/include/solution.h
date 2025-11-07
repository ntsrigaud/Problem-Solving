#ifndef SOLUTION_H
#define SOLUTION_H

/*
 * Prime Gap
 * --------
 *  Write a program to calculate, for a given positive integer k, the length of
 * the prime gap that contains k.
 *
 * Procedure
 * ---------
 * - Check if k is a prime
 *    - If yes return 0
 * - Use a list to keep track of the prime numbers computed up until now
 * - Check if the maximum value in the list is greater than k
 *   - If yes, find the closest numbers in the list from k such that: a < k < b
 *      - Return the difference of b - a
 *   - If no, update the list up to the next prime number greater that k
 *      - Keep track of the last prime number (a) that is less than k upon
 * finding b
 *      - When b is found, return b - a
 *
 * Revision history:
 * Revised by Neil Taison Rigaud, October 2025
 * */

#include <vector>

class Solution {
public:
  Solution() = default;
  ~Solution() = default;

  // Add problem-specific methods here
  int prime_gap(int k);

private:
  std::vector<int> prime_list;

  void update_prime_list(int n);
  bool is_prime(int n);
};

#endif // !SOLUTION_H
