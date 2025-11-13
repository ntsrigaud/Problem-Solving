#include <array>
#include <iostream>

/*
 * UVA: How Many Knights
 * Link: https://onlinejudge.org/external/6/696.pdf
 *
 * Revision history:
 * Originally written by Neil Taison Rigaud, November 2025
 * */

#define LOG(x) std::cout << "Log: " << x << '\n'

constexpr int MAX_SIZE = 500;
constexpr int KNIGHT_RANGE = 2;
constexpr char KNIGHT = 'N';

using ChessBoard = std::array<std::array<char, MAX_SIZE>, MAX_SIZE>;

struct Coord {
  int row;
  int col;
};

struct Dim : Coord {};

bool isUnderAttack(ChessBoard &board, Coord &coord, Dim d) {
  // 2 rows UP, 1 column RIGHT and 1 column LEFT
  if (coord.row - KNIGHT_RANGE >= 0) {
    if (coord.col - 1 >= 0 &&
        board.at(coord.row - KNIGHT_RANGE).at(coord.col - 1) == KNIGHT) {
      return true;
    }

    if (coord.col + 1 < d.col && coord.col + 1 < MAX_SIZE &&
        board.at(coord.row - KNIGHT_RANGE).at(coord.col + 1) == KNIGHT) {
      return true;
    }
  }

  // 2 rows DOWN, 1 column RIGHT and 1 column LEFT
  if (coord.row + KNIGHT_RANGE < d.row && coord.row + KNIGHT_RANGE < MAX_SIZE) {
    if (coord.col - 1 >= 0 &&
        board.at(coord.row + KNIGHT_RANGE).at(coord.col - 1) == KNIGHT) {
      return true;
    }

    if (coord.col + 1 < d.col && coord.col + 1 < MAX_SIZE &&
        board.at(coord.row + KNIGHT_RANGE).at(coord.col + 1) == KNIGHT) {
      return true;
    }
  }

  // 2 cols LEFT, 1 row UP and 1 row DOWN
  if (coord.col - KNIGHT_RANGE >= 0) {
    if (coord.row - 1 >= 0 &&
        board.at(coord.row - 1).at(coord.col - KNIGHT_RANGE) == KNIGHT) {
      return true;
    }

    if (coord.row + 1 < MAX_SIZE &&
        board.at(coord.row + 1).at(coord.col - KNIGHT_RANGE) == KNIGHT) {
      return true;
    }
  }

  // 2 cols RIGHT, 1 row UP and 1 row DOWN
  if (coord.col + KNIGHT_RANGE < MAX_SIZE) {
    if (coord.row - 1 >= 0 &&
        board.at(coord.row - 1).at(coord.col + KNIGHT_RANGE) == KNIGHT) {
      return true;
    }

    if (coord.row + 1 < MAX_SIZE &&
        board.at(coord.row + 1).at(coord.col + KNIGHT_RANGE) == KNIGHT) {
      return true;
    }
  }

  return false;
}

int addKnights(std::array<std::array<char, MAX_SIZE>, MAX_SIZE> &board,
               Dim &d) {
  board[0][0] = KNIGHT;

  int n_knights = 0;
  Coord c{0, 0};
  for (; c.row < d.row; ++c.row) {
    for (c.col = 0; c.col < d.col; ++c.col) {
      if (board.at(c.row).at(c.col) != KNIGHT && !isUnderAttack(board, c, d)) {
        board.at(c.row).at(c.col) = KNIGHT;
        ++n_knights;
      }
    }
  }

  return n_knights + 1; // The first knight at (0, 0)
}

void printBoard(ChessBoard &b, Dim &dim);

int main() {
  Dim b_dim;
  int n_knights = 0;

  while (std::cin >> b_dim.row >> b_dim.col && b_dim.row != 0 &&
         b_dim.col != 0) {
    ChessBoard board{{}};
    n_knights = addKnights(board, b_dim);

    std::cout << n_knights << " may be placed on a " << b_dim.row << " row "
              << b_dim.col << " column board.\n";
  }

  return 0;
}

void printBoard(ChessBoard &b, Dim &dim) {
  for (int i = 0; i < dim.row; ++i) {
    for (int j = 0; j < dim.col; ++j) {
      std::cout << (b.at(i).at(j) == KNIGHT ? 'N' : ' ') << "|";
    }
    std::cout << '\n';
  }
}
