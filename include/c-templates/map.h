#include <template.h>
#ifdef TEMPLATE_MAP
#error "Template Map is already under definition; Depending on the definition of the same Template with different arguments is an anti-pattern. Please reconsider your architectural choices."
#else
#ifndef K
#error "Template argument K not defined"
#endif
#ifndef V
#error "Template argument V not defined"
#endif
#ifndef K_Equals
#define K_Equals(Ka, Kb) Ka == Kb
#endif
#ifndef K_Compare
#define K_Compare(Ka, Kb) Ka < Kb
#endif
#define TEMPLATE_MAP E_CONCAT3(Map, K, V)

#define F K
#define S V
#include <c-templates/pair.h>
#undef S
#undef F
#define MAP_FIELD E_CONCAT3(Pair, K, V)

#define T MAP_FIELD
#include <c-templates/vector.h>
#undef T
#define MAP_FIELD_VECTOR E_CONCAT2(Vector, MAP_FIELD)

typedef struct {
  MAP_FIELD_VECTOR data;
} TEMPLATE_MAP;

// Declare functions
IFn(TEMPLATE_MAP, void, init)(TEMPLATE_MAP* map);
IFn(TEMPLATE_MAP, void, clean)(TEMPLATE_MAP* map);
IFn(TEMPLATE_MAP, void, clear)(TEMPLATE_MAP* map);
IFn(TEMPLATE_MAP, TEMPLATE_MAP*, new)();
IFn(TEMPLATE_MAP, void, delete)(TEMPLATE_MAP* map);
IFn(TEMPLATE_MAP, bool, empty)(TEMPLATE_MAP* map);
IFn(TEMPLATE_MAP, size_t, size)(TEMPLATE_MAP* map);

IFn(TEMPLATE_MAP, void, put)(TEMPLATE_MAP* map, K key, V value);
IFn(TEMPLATE_MAP, V, get)(TEMPLATE_MAP* map, const K key);
IFn(TEMPLATE_MAP, MAP_FIELD*, find)(TEMPLATE_MAP* map, const K key);
IFn(TEMPLATE_MAP, bool, contains)(TEMPLATE_MAP* map, const K key);
IFn(TEMPLATE_MAP, MAP_FIELD*, begin)(TEMPLATE_MAP* map);
IFn(TEMPLATE_MAP, MAP_FIELD*, end)(TEMPLATE_MAP* map);

// Define functions
IFn(TEMPLATE_MAP, void, init)(TEMPLATE_MAP* map) {
  Method(MAP_FIELD_VECTOR, init)(&map->data);
}

IFn(TEMPLATE_MAP, void, clean)(TEMPLATE_MAP* map) {
  Method(MAP_FIELD_VECTOR, clean)(&map->data);
}

IFn(TEMPLATE_MAP, void, clear)(TEMPLATE_MAP* map) {
  Method(MAP_FIELD_VECTOR, clear)(&map->data);
}

IFn(TEMPLATE_MAP, TEMPLATE_MAP*, new)() {
  TEMPLATE_MAP* map = (TEMPLATE_MAP*) malloc(sizeof(TEMPLATE_MAP));
  Method(TEMPLATE_MAP, init)(map);
  return map;
}

IFn(TEMPLATE_MAP, void, delete)(TEMPLATE_MAP* map) {
  if (map != NULL) {
    Method(TEMPLATE_MAP, clean)(map);
    free(map);
  }
}

IFn(TEMPLATE_MAP, bool, empty)(TEMPLATE_MAP* map) {
  return Method(MAP_FIELD_VECTOR, empty)(&map->data);
}

IFn(TEMPLATE_MAP, size_t, size)(TEMPLATE_MAP* map) {
  return Method(MAP_FIELD_VECTOR, size)(&map->data);
}

IFn(TEMPLATE_MAP, void, put)(TEMPLATE_MAP* map, K key, V value) {
  MAP_FIELD* field = Method(TEMPLATE_MAP, find)(map, key);
  if (field != Method(TEMPLATE_MAP, end)(map)) {
    field->second = value;
  } else {
    MAP_FIELD item = {.first = key, .second = value};
    Method(MAP_FIELD_VECTOR, push_back)(&map->data, item);
  }
}

IFn(TEMPLATE_MAP, V, get)(TEMPLATE_MAP* map, const K key) {
  MAP_FIELD* field = Method(TEMPLATE_MAP, find)(map, key);
  if (field != Method(TEMPLATE_MAP, end)(map)) {
    return field->second;
  }
  V default_value = {0};
  return default_value;
}

IFn(TEMPLATE_MAP, MAP_FIELD*, find)(TEMPLATE_MAP* map, const K key) {
  MAP_FIELD* begin = Method(MAP_FIELD_VECTOR, begin)(&map->data);
  MAP_FIELD* end = Method(MAP_FIELD_VECTOR, end)(&map->data);
  MAP_FIELD* it = begin;
  while (it < end) {
    if (K_Equals(it->first, key))
      return it;
    ++it;
  }
  return end;
}

IFn(TEMPLATE_MAP, bool, contains)(TEMPLATE_MAP* map, const K key) {
  return Method(TEMPLATE_MAP, find)(map, key) != Method(TEMPLATE_MAP, end)(map);
}

IFn(TEMPLATE_MAP, MAP_FIELD*, begin)(TEMPLATE_MAP* map) {
  return Method(MAP_FIELD_VECTOR, begin)(&map->data);
}

IFn(TEMPLATE_MAP, MAP_FIELD*, end)(TEMPLATE_MAP* map) {
  return Method(MAP_FIELD_VECTOR, end)(&map->data);
}

#undef TEMPLATE_MAP
#endif
