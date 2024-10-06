#include <assert.h>
#include "point.h"

#define K int
#define V Point
#include <c-templates/map.h>
#undef V
#undef K

int main() {
  const uint64_t AMOUNT = 20;
  Map_int_Point map;
  Method(Map_int_Point, init)(&map);
  assert(Map_int_Point__size(&map) == 0);

  for (uint64_t i = 0; i < AMOUNT; ++i) {
    Point item = {.x = i, .y = i + 1, .z = i + 2};
    Method(Map_int_Point, put)(&map, i, item);
  }

  for (uint64_t i = 0; i < AMOUNT; ++i) {
    Point item = Method(Map_int_Point, get)(&map, i);
    assert(item.x == (int64_t)i);
    assert(item.y == (int64_t)i + 1);
    assert(item.z == (int64_t)i + 2);
  }
  assert(Method(Map_int_Point, size)(&map) == AMOUNT);

  Point patch = {.x = -1, .y = -2, .z = -3};
  Method(Map_int_Point, put)(&map, 17, patch);
  assert(Method(Map_int_Point, size)(&map) == AMOUNT);

  Point patched_item = Method(Map_int_Point, get)(&map, 17);
  assert(patched_item.x == -1);
  assert(patched_item.y == -2);
  assert(patched_item.z == -3);

  Method(Map_int_Point, clean)(&map);
  assert(map.data.length == 0);
  assert(map.data.size == 0);
  assert(map.data.data == NULL);
}
