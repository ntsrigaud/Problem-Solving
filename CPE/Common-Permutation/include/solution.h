#ifndef SOLUTION_H
#define SOLUTION_H

/*
 * Given two strings of lowercase letters, a and b, print the longest string x
 * of lowercase letters such that there is a permutation of x that is the
 * subsequence of a and there is a permutation of x that is the subsequence of
 * b.
 *
 * Input
 * -----
 * Input file contains several lines of input. Consecutive two lines make a set
 * of input. Each string is on a separate line and consists of at most 1000
 * lowercase letters.
 *
 * Output
 * ------
 * For each set of input, output a line containing x. If several x satisfy the
 * criteria above, choose the first one in alphabetical order.
 *
 * a = walking
 * b = down
 * --> nw
 *
 * Procedure
 * ---------
 *  - Map all the characters of the first string using a hash map.
 *  - Parse the second string while recording the characters that are found in
 * the hash map.
 *   - Return the sorted subsequence obtained
 *
 * Revision history:
 * Revised by Neil Taison Rigaud, October 2025
 */

#include <string>
#include <utility>

using StrPair = std::pair<std::string, std::string>;

class Solution {
public:
  Solution() = default;
  ~Solution() = default;

  // Add problem-specific methods here
  std::string common_permutation(const StrPair &) const;
};

#endif // !SOLUTION_H
