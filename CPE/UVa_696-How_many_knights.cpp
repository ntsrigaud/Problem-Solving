#include <iostream>
#include <vector>

/*
 * UVA: How Many Knights
 * Link: https://onlinejudge.org/external/6/696.pdf
 * Ref.:
 * https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/VI/696%20-%20How%20Many%20Knights.cpp
 * */

int solve(int n, int m) {
  if (m == 0 || n == 0) {
    return 0;
  }
  if (n > m) {
    std::swap(n, m);
  }
  if (n == 1) {
    // A knight can be placed on every square in a 1xM board
    return m;
  }

  if (n == 2) {
    // Repeated pattern
    return ((m / 4) * 4) + (m % 4 == 1 ? 2 : (m % 4 >= 2) ? 4 : 0);
  }

  return (n * m + 1) / 2; // Integer trick
}

int main() {
  int m = 0;
  int n = 0;
  int knights = 0;

  while (std::cin >> m >> n && (m + n) != 0) {
    knights = solve(m, n);
    std::cout << knights << " knights may be placed on a " << m << " row " << n
              << " column board.\n";
  }

  return 0;
}
