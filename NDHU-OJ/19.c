#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 10

bool isDigit(char c) { return c >= '0' && c <= '9'; }

int main() {
  int i = 0;
  char id[MAX_SIZE];

  while ((id[i] = getchar()) != '\n' && id[i] != EOF) {
    if (i >= 9) {
      printf("Invalid\n");
      return 0;
    }
    ++i;
  }

  if (i != 9) {
    printf("Invalid\n");
    return 0;
  }

  id[i] = '\0';

  bool is_valid =
      (id[0] == 'D' && (id[1] == '1' || id[1] == '2' || id[1] == '3') &&
       isDigit(id[2]) && isDigit(id[3]) && (id[4] >= 'A' && id[4] <= 'Z') &&
       (id[5] >= 'A' && id[5] <= 'Z') && isDigit(id[6]) && isDigit(id[7]) &&
       isDigit(id[8]));

  if (is_valid) {
    printf("Valid\n");
  } else {
    printf("Invalid\n");
  }

  return 0;
}
