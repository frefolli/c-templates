#include <assert.h>
#include "point.h"

#define T Point
#include <c-templates/vector.h>
#undef T

int main() {
  const uint64_t AMOUNT = 20;

  Vector_Point vec;
  Method(Vector_Point, init)(&vec);
  assert(Vector_Point__size(&vec) == 0);

  for (uint64_t i = 0; i < AMOUNT; ++i) {
    Point point = {.x = i, .y = 2*i, .z = 3*i};
    Method(Vector_Point, push_back)(&vec, point);
  }
  assert(Vector_Point__size(&vec) == AMOUNT);

  for (uint64_t i = 0; i < vec.length; ++i) {
    Point* point = Method(Vector_Point, at)(&vec, i);
    assert(point->x == (int64_t)i);
    assert(point->y == 2*(int64_t)i);
    assert(point->z == 3*(int64_t)i);
  }

  Method(Vector_Point, clean)(&vec);
  assert(vec.length == 0);
  assert(vec.size == 0);
  assert(vec.data == NULL);
}
