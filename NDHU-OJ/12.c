#include <stdio.h>
#include <stdlib.h>

// Question 12: Amis Weaving Totem: The Diamond

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return 0;
  if (n <= 0 || (n % 2) == 0)
    return 0;

  int center = n / 2;
  for (int i = 0; i < n; ++i) {
    int d = abs(center - i); // distance from center row
    int spaces = d;
    int stars = n - 2 * d;

    for (int s = 0; s < spaces; ++s)
      putchar(' ');
    for (int s = 0; s < stars; ++s)
      putchar('*');
    putchar('\n');
  }

  return 0;
}
