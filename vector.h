#include <template.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  T* data;
  size_t size;
  size_t length;
} Template(Vector, T);

// Declare
IFn(Vector, T, void, init)(Template(Vector, T)* vec);
IFn(Vector, T, void, clean)(Template(Vector, T)* vec);
IFn(Vector, T, void, clear)(Template(Vector, T)* vec);
IFn(Vector, T, void, delete)(Template(Vector, T)* vec);
IFn(Vector, T, void, resize)(Template(Vector, T)* vec, size_t count);
IFn(Vector, T, void, push_back)(Template(Vector, T)* vec, T value);
IFn(Vector, T, void, pop_back)(Template(Vector, T)* vec);
IFn(Vector, T, T*,   begin)(Template(Vector, T)* vec);
IFn(Vector, T, T*,   end)(Template(Vector, T)* vec);
IFn(Vector, T, T*,   at)(Template(Vector, T)* vec, size_t idx);
IFn(Vector, T, T,    get)(Template(Vector, T)* vec, size_t idx);
IFn(Vector, T, void, set)(Template(Vector, T)* vec, size_t idx, T value);
IFn(Vector, T, bool, empty)(Template(Vector, T)* vec);

// Define
IFn(Vector, T, void, init)(Template(Vector, T)* vec) {
  vec->size = 1;
  vec->length = 0;
  vec->data = (T*) malloc(sizeof(T) * vec->size);
}

IFn(Vector, T, void, clean)(Template(Vector, T)* vec) {
  if (vec->data != NULL) {
    free(vec->data);
    vec->size = 0;
    vec->length = 0;
  }
}

IFn(Vector, T, void, clear)(Template(Vector, T)* vec) {
  Method(Vector, T, clean)(vec);
  Method(Vector, T, init)(vec);
}

IFn(Vector, T, void, delete)(Template(Vector, T)* vec) {
  if (vec != NULL) {
    Method(Vector, T, clean)(vec);
    free(vec);
  }
}

IFn(Vector, T, void, resize)(Template(Vector, T)* vec, size_t count) {
  size_t new_size = vec->size;
  while (count > new_size) {
    new_size *= 2;
  }
  vec->size = new_size;
  vec->data = (T*) realloc(vec->data, sizeof(T) * vec->size);
}

IFn(Vector, T, void, push_back)(Template(Vector, T)* vec, T value) {
  Method(Vector, T, resize)(vec, vec->length + 1);
  vec->data[vec->length] = value;
  vec->length += 1;
}

IFn(Vector, T, void, pop_back)(Template(Vector, T)* vec) {
  if (vec->length > 0) {
    vec->length -= 1;
  }
}

IFn(Vector, T, T*, begin)(Template(Vector, T)* vec) {
  return vec->data;
}

IFn(Vector, T, T*, end)(Template(Vector, T)* vec) {
  return vec->data + vec->length;
}

IFn(Vector, T, T*, at)(Template(Vector, T)* vec, size_t idx) {
  if (idx < vec->length) {
    return vec->data + idx;
  }
}

IFn(Vector, T, T, get)(Template(Vector, T)* vec, size_t idx) {
  return *Method(Vector, T, at)(vec, idx);
}

IFn(Vector, T, void, set)(Template(Vector, T)* vec, size_t idx, T value) {
  *Method(Vector, T, at)(vec, idx) = value;
}

IFn(Vector, T, bool, empty)(Template(Vector, T)* vec) {
  return vec->length == 0;
}
