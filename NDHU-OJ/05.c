#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Question 05: Point and Rectangle Relationship

typedef enum POINT_LOCATION { INSIDE, BORDER, OUTSIDE } POINT_LOCATION;

typedef struct Point {
  int x;
  int y;
} Point;

typedef struct Rectangle {
  Point bottom_left;
  Point top_right;
} Rectangle;

void take_inputs(Rectangle *rec, Point *p) {
  scanf("%d", &(rec->bottom_left).x);
  scanf("%d", &(rec->bottom_left).y);

  scanf("%d", &(rec->top_right).x);
  scanf("%d", &(rec->top_right).y);

  scanf("%d", &(p->x));
  scanf("%d", &(p->y));
}

POINT_LOCATION is_inside_rectangle(const Rectangle *rec, const Point *p)
// Determine if the given point is locate inside the rectangle
{
  if (p->x > rec->bottom_left.x && p->x < rec->top_right.x &&
      p->y > rec->bottom_left.y && p->y < rec->top_right.y) {
    return INSIDE;
  } else if ((p->x == rec->bottom_left.x && p->y >= rec->bottom_left.y &&
              p->y <= rec->top_right.y) ||
             (p->x == rec->top_right.x && p->y >= rec->bottom_left.y &&
              p->y <= rec->top_right.y) ||
             (p->y == rec->bottom_left.y && p->x >= rec->bottom_left.x &&
              p->x <= rec->top_right.x) ||
             (p->y == rec->top_right.y && p->x >= rec->bottom_left.x &&
              p->x <= rec->top_right.x)) {
    return BORDER;
  } else {
    return OUTSIDE;
  }
}

int main() {
  Rectangle rec;
  Point p;

  take_inputs(&rec, &p);

  switch (is_inside_rectangle(&rec, &p)) {
  case INSIDE:
    printf("Inside\n");
    break;
  case BORDER:
    printf("On the border\n");
    break;
  default:
    printf("Outside\n");
    break;
  }

  return EXIT_SUCCESS;
}
