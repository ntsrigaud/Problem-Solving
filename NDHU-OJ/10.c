#include <stdio.h>
#include <stdlib.h>

/* Question 10: Hualien Mochi Quality Inspection
 *
 * Write a program to:
 *  - verify the weight of boxes of mochi
 *  - determine how many boxes in a batch meets the quality standard
 *
 * Constraints:
 * -----------
 * - 250 <= standard_box_weight <= 270
 */

static const int MIN_WEIGHT = 250;
static const int MAX_WEIGHT = 270;

int main() {

  int mochi_boxes = 0;
  int box_weight = 0;
  int total_valid_boxes = 0;
  scanf("%d", &mochi_boxes);

  for (int i = 0; i < mochi_boxes; ++i) {
    scanf("%d", &box_weight);
    total_valid_boxes += (box_weight >= MIN_WEIGHT && box_weight <= MAX_WEIGHT);
  }

  printf("Total Qualified Boxes: %d\n", total_valid_boxes);

  return EXIT_SUCCESS;
}
