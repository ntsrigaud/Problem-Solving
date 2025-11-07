#ifndef SOLUTION_H
#define SOLUTION_H

/*
 * Nice Licence Plates
 *
 * A licence plate is of format ABC-0123 is nice if the absolute difference
 * between the value of the first part and the value of the second part is at
 * most 100.
 *
 * The value of the first part is calculated as the value of base-26 number.
 *
 * Procedure
 * ---------
 *  - Compute the value of the first part
 *    - Each number value is obtained by computing the difference to 'A'
 *    - Start computing the sum of each number value from the right.
 *  - Compute the absolute difference to the value of the second part
 *  - Use the result obtained to return whether the plate number is nice or not.
 *
 * Revision history:
 * Revised by Neil Taison Rigaud, August 2025
 *
 * */

#include <string>

class Solution {
public:
  Solution() = default;
  ~Solution() = default;

  // Add problem-specific methods here
  std::string nice_licence_plate(const std::string &) const;
};

#endif // !SOLUTION_H
