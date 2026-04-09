#include <cmath>
#include <iostream>

// UVa11461: Square Numbers

int solve(int a, int b) {
  // Calculate perfect squares UP TO b and STRICTLY BEFORE a
  int high_sq = static_cast<int>(std::sqrt(b));
  int low_sq = static_cast<int>(std::sqrt(a - 1));

  // The difference is the count of squares in the inclusive range [a, b].
  return high_sq - low_sq;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int a = 0, b = 0;

  while (std::cin >> a >> b && a && b) {
    std::cout << solve(a, b) << '\n';
  }

  return 0;
}
