#include <array>
#include <iostream>
#include <vector>

/*
 * UVA: Box of Bricks
 * Link: https://onlinejudge.org/external/5/591.pdf
 *
 * Revision history:
 * Originally written by Neil Taison Rigaud, November 2025
 *
 * This program implements the solution to the "UVA: Box of Bricks"
 * problem.
 * */
constexpr int MAX_N = 50;

int main() {
  int n_stacks = 0;
  int sum = 0;
  int final_height = 0;
  int i = 0;
  int deviations = 0;
  int set = 0;
  std::array<int, MAX_N> stacks;

  while (std::cin >> n_stacks && n_stacks > 0) {
    ++set;
    sum = 0;
    deviations = 0;

    for (i = 0; i < n_stacks; ++i) {
      std::cin >> stacks.at(i);
      sum += stacks.at(i);
    }

    // Find the final height
    final_height = sum / n_stacks;

    // Compute the positive deviations from the final height
    for (i = 0; i < n_stacks; ++i) {
      if (stacks.at(i) > final_height) {
        deviations += stacks.at(i) - final_height;
      }
    }

    std::cout << "Set #" << set << '\n';
    std::cout << "The minimum number of moves is " << deviations << ".\n\n";
  }

  return 0;
}
