#ifndef SOLUTION_H
#define SOLUTION_H

/*
 *
 * Revision history:
 * Revised by Neil Taison Rigaud, August 2025
 *
 * */

#include <iosfwd>

class Solution {
public:
  Solution() = default;
  ~Solution() = default;

  // Run the problem solver which reads from stdin and writes to stdout.
  // Throws std::invalid_argument or std::runtime_error on fatal errors.
  void run();

  // Process the problem using the provided input/output streams. This is the
  // IO-friendly API intended for unit testing (pass std::cin/std::cout in
  // production or stringstreams in tests).
  void process(std::istream &in, std::ostream &out);
};

#endif // !SOLUTION_H
