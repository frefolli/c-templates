#include <stdio.h>
#include "point.h"

#define T Point
#include <c-templates/vector.h>
#undef T

int main() {
  const uint64_t AMOUNT = 20;

  Template(Vector, Point) vec;
  Method(Vector, Point, init)(&vec);
  for (uint64_t i = 0; i < AMOUNT; ++i) {
    Point point = {.x = i, .y = 2*i, .z = 3*i};
    Method(Vector, Point, push_back)(&vec, point);
  }
  for (uint64_t i = 0; i < vec.length; ++i) {
    Point* point = Method(Vector, Point, at)(&vec, i);
    printf("(%ld, %ld, %ld)\n", point->x, point->y, point->z);
  }
  Method(Vector, Point, clean)(&vec);
}
