#ifndef SOLUTION_H
#define SOLUTION_H

/*
 *
 * Revision history:
 * Revised by Neil Taison Rigaud, January 2026
 *
 * */

class Solution {
public:
  Solution() = default;
  ~Solution() = default;

  // Add problem-specific methods here
  int sum(int arr[], int size) const;
  double average(int arr[], int size) const;
};

#endif // !SOLUTION_H
