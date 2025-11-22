#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SHAPE_NUMBER_SIZE 5

bool isShapedNumber(int n) {
  int i = SHAPE_NUMBER_SIZE - 1;
  int d[SHAPE_NUMBER_SIZE] = {};

  // Get the digits
  while (n > 0 && i >= 0) {
    d[i] = n % 10;
    n /= 10;
    --i;
  }

  for (i = 0; i < SHAPE_NUMBER_SIZE - 1; ++i) {
    if ((i % 2 == 0 && d[i] > d[i + 1]) || (i % 2 != 0 && d[i] < d[i + 1])) {
      return false;
    }

    for (int j = 0; j < SHAPE_NUMBER_SIZE; ++j) {
      if (i != j && d[i] == d[j]) {
        return false;
      }
    }
  }

  return true;
}

int mShapedSum(int start, int end) {
  int sum = 0;

  for (int i = start; i <= end; ++i) {
    if (isShapedNumber(i)) {
      sum += i;
    }
  }

  return sum;
}

int main() {
  int start = 0, end = 0;

  scanf("%d %d", &start, &end);
  int sum = mShapedSum(start, end);
  printf("%d\n", sum);

  return 0;
}
