#include <stdio.h>
#include <stdlib.h>

#define WEEK_DAYS 7.0

int main() {
  int n_visitors = 0;
  int sum = 0;

  for (int i = 0; i < WEEK_DAYS; ++i) {
    scanf("%d", &n_visitors);
    sum += n_visitors;
  }

  double avg = sum / WEEK_DAYS;
  printf("Total Visitors: %d\nAverage Visitors: %.1f\n", sum, avg);

  return 0;
}
