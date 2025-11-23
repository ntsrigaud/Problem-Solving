#include <stdio.h>

#define MAX_LEN 1000
#define NOT_FOUND -1

int main() {
  char needle[MAX_LEN];
  char haystack[MAX_LEN];
  int c;
  int i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i < MAX_LEN - 1)
      haystack[i++] = c;
  };
  haystack[i] = '\0';
  int hs_len = i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (i < MAX_LEN - 1)
      needle[i++] = c;
  };
  needle[i] = '\0';
  int needle_len = i;

  if (needle_len == 0) {
    printf("%d\n", 0);
    return 0;
  }

  if (needle_len > hs_len) {
    printf("%d\n", NOT_FOUND);
    return 0;
  }

  for (i = 0; i <= hs_len - needle_len; ++i) {
    int j = 0;
    for (j = 0; j < needle_len; ++j) {
      if (haystack[i + j] != needle[j])
        break;
    }

    if (j == needle_len) {
      printf("%d\n", i);
      return 0;
    }
  }

  printf("%d\n", NOT_FOUND);

  return 0;
}
