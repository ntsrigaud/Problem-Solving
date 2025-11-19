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
    /*
     * For a 2-row board, knights can be placed in a pattern where every group of 4 columns
     * can accommodate 4 knights without attacking each other (by placing them in alternating squares).
     * For the remaining columns:
     *   - If 1 column remains, place 2 knights.
     *   - If 2 or 3 columns remain, place 4 knights.
     * This formula calculates the total number of knights that can be placed safely.
     */
    return ((m / 4) * 4) + (m % 4 == 1 ? 2 : (m % 4 >= 2) ? 4 : 0);
  }

  // Place knights on alternating squares (chessboard pattern); this formula computes
  // the ceiling of half the total squares, which is the maximum number of knights
  // that can be placed without attacking each other.
  return (n * m + 1) / 2;
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
