#include <stdio.h>

int main() {
  char ch;
  int count = 0;
  int max_count = 0;

  while ((ch = getchar()) != EOF) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
      ++count;
    } else {
      if (count > max_count) {
        max_count = count;
      }
      count = 0;
    }
  }

  if (count > max_count) {
    max_count = count;
  }

  printf("Longest Word Length: %d", max_count);

  return 0;
}
