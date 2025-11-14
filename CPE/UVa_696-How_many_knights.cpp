#include <iostream>
#include <vector>

/*
 * UVA: How Many Knights
 * Link: https://onlinejudge.org/external/6/696.pdf
 *
 * Backtracking Procedure
 * ----------------------
 *  - Normalize the column index at the start of the recursion
 *    - If it is past end, advance the row
 *  - If we reach beyond the last row, return 0
 *  - Search for the next square using local loop variables
 *  - Try placing a knight, and compare with skipping the cell
 * */

#define LOG(x) std::cout << "Log: " << x << '\n'

constexpr int KNIGHT_RANGE = 2;
constexpr char KNIGHT = 'N';
constexpr char EMPTY = ' ';

struct Coord {
  int row;
  int col;
};

struct Dim : Coord {
  Dim() : Coord{0, 0} {};
  Dim(int m, int n) : Coord{m, n} {};
  Dim(const Dim &d) : Coord{d.row, d.col} {};
};

class ChessBoard {
private:
  std::vector<std::vector<char>> board;
  Dim dim;

public:
  [[nodiscard]] Dim get_dim() const { return dim; }

  explicit ChessBoard(const Dim &d) : dim(d) {
    board.resize(dim.row, std::vector<char>(dim.col, EMPTY));
  };

  [[nodiscard]] bool isUnderAttack(const Coord &coord) const {
    auto in_row = [&](int r) -> bool { return r >= 0 && r < dim.row; };
    auto in_col = [&](int c) -> bool { return c >= 0 && c < dim.col; };

    // 2 rows UP, 1 column RIGHT and 1 column LEFT
    if (in_row(coord.row - KNIGHT_RANGE)) {
      int r = coord.row - KNIGHT_RANGE;

      if (in_col(coord.col - 1) && board.at(r).at(coord.col - 1) == KNIGHT) {
        return true;
      }

      if (in_col(coord.col + 1) && board.at(r).at(coord.col + 1) == KNIGHT) {
        return true;
      }
    }

    // 2 rows DOWN, 1 column RIGHT and 1 column LEFT
    if (in_row(coord.row + KNIGHT_RANGE)) {
      int r = coord.row + KNIGHT_RANGE;

      if (in_col(coord.col - 1) && board.at(r).at(coord.col - 1) == KNIGHT) {
        return true;
      }

      if (in_col(coord.col + 1) && board.at(r).at(coord.col + 1) == KNIGHT) {
        return true;
      }
    }

    // 2 cols LEFT, 1 row UP and 1 row DOWN
    if (in_col(coord.col - KNIGHT_RANGE)) {
      int c = coord.col - KNIGHT_RANGE;

      if (in_row(coord.row - 1) && board.at(coord.row - 1).at(c) == KNIGHT) {
        return true;
      }

      if (in_row(coord.row + 1) && board.at(coord.row + 1).at(c) == KNIGHT) {
        return true;
      }
    }

    // 2 cols RIGHT, 1 row UP and 1 row DOWN
    if (in_col(coord.col + KNIGHT_RANGE)) {
      int c = coord.col + KNIGHT_RANGE;

      if (in_row(coord.row - 1) && board.at(coord.row - 1).at(c) == KNIGHT) {
        return true;
      }

      if (in_row(coord.row + 1) && board.at(coord.row + 1).at(c) == KNIGHT) {
        return true;
      }
    }

    return false;
  }

  void printBoard() {
    for (int i = 0; i < dim.row; ++i) {
      for (int j = 0; j < dim.col; ++j) {
        std::cout << (board.at(i).at(j) == KNIGHT ? 'N' : ' ') << "|";
      }
      std::cout << '\n';
    }
  }

  int addKnights(Coord c) {
    // Normalize coordinate (so col can overflow and move to next row)
    if (c.col >= dim.col) {
      c.col = 0;
      c.row++;
    }

    if (c.row >= dim.row) {
      return 0;
    }

    // Find next safe cell starting from c
    for (int r = c.row; r < dim.row; ++r) {
      for (int col = (r == c.row ? c.col : 0); col < dim.col; ++col) {
        if (board[r][col] != KNIGHT && !isUnderAttack({r, col})) {
          // try placing a knight here
          board[r][col] = KNIGHT;
          // next coordinate is same row, next column
          Coord next{r, col + 1};
          int with = 1 + addKnights(next);
          // undo
          board[r][col] = EMPTY;
          // skip this cell
          int without = addKnights(next);

          return std::max(with, without);
        }
      }
    }

    // no safe cell found
    return 0;
  }
};

int main() {
  Dim b_dim;
  Coord c{0, 0};

  while (std::cin >> b_dim.row >> b_dim.col && b_dim.row != 0 &&
         b_dim.col != 0) {
    ChessBoard board(b_dim);
    int n_knights = board.addKnights(c);

    std::cout << n_knights << " knights may be placed on a " << b_dim.row
              << " row " << b_dim.col << " column board.\n";
  }

  return 0;
}
