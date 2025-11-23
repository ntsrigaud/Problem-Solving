#include <stdio.h>

#define MAX_VISITORS 100

int main() {
  int n_visitors = 0, i = 0;
  int choices[MAX_VISITORS] = {};
  int souvenir_code = 0;

  scanf("%d", &n_visitors);
  for (i = 0; i < n_visitors; ++i) {
    scanf("%d", &choices[i]);
  }
  scanf("%d", &souvenir_code);

  printf("Reversed List:");
  for (i = n_visitors - 1; i >= 0; --i) {
    printf(" %d", choices[i]);
  }
  printf("\n");

  int count = 0;
  for (int i = 0; i < n_visitors; ++i) {
    count += (choices[i] == souvenir_code);
  }
  printf("Search Count: %d\n", count);

  return 0;
}
