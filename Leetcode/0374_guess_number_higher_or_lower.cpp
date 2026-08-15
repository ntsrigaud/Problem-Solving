// Leetcode #0374: Guess Number Higher or Lower

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

constexpr int secret_value = 44;

// Just a stub
static int guess(int v) {
  return v == secret_value ? 0 : (v < secret_value) ? -1 : 1;
};

class Solution {
  static constexpr int HIGHER = -1;
  static constexpr int LOWER = 1;
  static constexpr int CORRECT = 0;

public:
  int guessNumber(int n) {
    int guess_direction = 0;
    int guess_value = 0;
    int low = 1;
    int high = n;

    auto binSearch = [&]() -> int { return low + ((high - low) / 2); };

    while (high - low > 1) {
      guess_direction = guess(guess_value);
      switch (guess_direction) {
      case HIGHER:
        high = guess_value;
        guess_value = binSearch();
        break;
      case LOWER:
        low = guess_value;
        guess_value = binSearch();
        break;
      case CORRECT:
        return guess_value;
      default:
        break;
      }
    }

    return guess(low) == CORRECT ? low : high;
  }
};
