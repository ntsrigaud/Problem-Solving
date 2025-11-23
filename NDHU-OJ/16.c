#include <stdio.h>

#define MAX_DAYS 100
#define MAX_VISITORS 999999

typedef struct Record {
  int day;
  int visitors;
} Record;

typedef struct Solution {
  Record peak_day;
  Record trough_day;
  int longest_boom;
} Solution;

int main() {
  int n = 0, i = 0, j = 0;
  int cur = 0, prev = 0;
  int inc_count = 0;
  Solution s = {{0, 0}, {0, MAX_VISITORS}, 0};

  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    prev = cur;
    scanf("%d", &cur);

    if (i == 0) {
      inc_count = 1;
    } else {
      if (prev < cur) {
        ++inc_count;
      } else {
        if (inc_count > s.longest_boom) {
          s.longest_boom = inc_count;
        }
        inc_count = 1;
      }
    }

    if (s.peak_day.visitors < cur) {
      s.peak_day.day = i;
      s.peak_day.visitors = cur;
    }

    if (s.trough_day.visitors > cur) {
      s.trough_day.day = i;
      s.trough_day.visitors = cur;
    }
  }

  if (inc_count > s.longest_boom) {
    s.longest_boom = inc_count;
  }

  printf("Peak: Day %d (%d visitors)\n", s.peak_day.day + 1,
         s.peak_day.visitors);
  printf("Trough: Day %d (%d visitors)\n", s.trough_day.day + 1,
         s.trough_day.visitors);
  printf("Longest Boom: %d days\n", s.longest_boom);

  return 0;
}
