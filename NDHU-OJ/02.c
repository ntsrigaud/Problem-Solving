#include <stdio.h>
#include <stdlib.h>

const int MINUTES_TO_SECONDS = 60;
const int HOUR_TO_SECONDS = 3600;

typedef struct HMS {
  int hour;
  int minutes;
  int seconds;
} HMS;

HMS convert(const int seconds) {
  HMS result;

  result.hour = seconds / (HOUR_TO_SECONDS);
  int seconds_left = seconds % (HOUR_TO_SECONDS);
  result.minutes = seconds_left / MINUTES_TO_SECONDS;
  result.seconds = seconds_left % MINUTES_TO_SECONDS;

  return result;
}

void display_result(const int seconds, const HMS *conversion_result) {
  printf("%d seconds is equal to %d hours, %d minutes, and %d seconds.",
         seconds, conversion_result->hour, conversion_result->minutes,
         conversion_result->seconds);
}

int main() {
  int seconds;
  scanf("%d", &seconds);

  if (seconds < 0) {
    printf("Error: negative seconds value.");
    return EXIT_FAILURE;
  }

  HMS res = convert(seconds);
  display_result(seconds, &res);

  return EXIT_SUCCESS;
}
