#include <stdio.h>
#include <stdlib.h>

#define N_SCORES 3

typedef struct AvgResult {
  int total_score;
  int avg;
  double precise_avg;
} AvgResult;

AvgResult compute_avgs(const int *scores) {
  int i = 0;
  AvgResult res = {0};

  for (i = 0; i < N_SCORES; ++i) {
    res.total_score += scores[i];
  }

  res.avg = res.total_score / N_SCORES;
  res.precise_avg = (double)res.total_score / N_SCORES;

  return res;
}

void print_result(const AvgResult *res) {
  printf("Total score: %d\nInteger average: %d\nPrecise average: %f",
         res->total_score, res->avg, res->precise_avg);
}

int main() {
  int scores[N_SCORES];

  for (int i = 0; i < N_SCORES; ++i) {
    scanf("%d", &scores[i]);
  }

  AvgResult res = compute_avgs(scores);
  print_result(&res);

  return EXIT_SUCCESS;
}
