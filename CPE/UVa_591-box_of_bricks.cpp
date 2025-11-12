#include <iostream>
#include <vector>

/*
 * UVA: Trees on the level
 * Link: https://onlinejudge.org/external/5/591.pdf
 *
 * Revision history:
 * Originally written by Neil Taison Rigaud, November 2025
 *
 * This program implements the solution to the "UVA: Box of Bricks"
 * problem.
 * */

int main() {
  int n_stacks = 0;
  int s = 0;
  int sum = 0;
  int final_height = 0;
  int i = 0;
  int deviations = 0;
  std::vector<int> stacks;

  while (std::cin >> n_stacks && n_stacks > 0) {
    sum = 0;
    deviations = 0;

    for (i = 0; i < n_stacks; ++i) {
      std::cin >> s;
      sum += s;
      stacks.push_back(s);
    }

    // Find the final height
    final_height = sum / n_stacks;

    // Compute the positive deviations from the final height
    for (const auto &s : stacks) {
      if (s > final_height) {
        deviations += s - final_height;
      }
    }

    std::cout << "Set #1\nThe minimum number of moves is " << deviations
              << ".\n";
  }

  return 0;
}
