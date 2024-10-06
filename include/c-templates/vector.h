#include <template.h>
#ifdef TEMPLATE_VECTOR
#error "Template Vector is already under definition; Depending on the definition of the same Template with different arguments is an anti-pattern. Please reconsider your architectural choices."
#else
#ifndef T
#error "Template argument T not defined"
#endif
#define TEMPLATE_VECTOR E_CONCAT2(Vector, T)

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  T* data;
  size_t size;
  size_t length;
} TEMPLATE_VECTOR;

// Declare
IFn(TEMPLATE_VECTOR, void, init)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, void, clean)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, void, clear)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, void, delete)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, void, resize)(TEMPLATE_VECTOR* vec, size_t count);
IFn(TEMPLATE_VECTOR, void, push_back)(TEMPLATE_VECTOR* vec, T value);
IFn(TEMPLATE_VECTOR, void, pop_back)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, T*,   begin)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, T*,   end)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, T*,   at)(TEMPLATE_VECTOR* vec, size_t idx);
IFn(TEMPLATE_VECTOR, T,    get)(TEMPLATE_VECTOR* vec, size_t idx);
IFn(TEMPLATE_VECTOR, void, set)(TEMPLATE_VECTOR* vec, size_t idx, T value);
IFn(TEMPLATE_VECTOR, bool, empty)(TEMPLATE_VECTOR* vec);
IFn(TEMPLATE_VECTOR, size_t, size)(TEMPLATE_VECTOR* vec);

// Define
IFn(TEMPLATE_VECTOR, void, init)(TEMPLATE_VECTOR* vec) {
  vec->size = 1;
  vec->length = 0;
  vec->data = (T*) malloc(sizeof(T) * vec->size);
}

IFn(TEMPLATE_VECTOR, void, clean)(TEMPLATE_VECTOR* vec) {
  if (vec->data != NULL) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->length = 0;
  }
}

IFn(TEMPLATE_VECTOR, void, clear)(TEMPLATE_VECTOR* vec) {
  Method(TEMPLATE_VECTOR, clean)(vec);
  Method(TEMPLATE_VECTOR, init)(vec);
}

IFn(TEMPLATE_VECTOR, void, delete)(TEMPLATE_VECTOR* vec) {
  if (vec != NULL) {
    Method(TEMPLATE_VECTOR, clean)(vec);
    free(vec);
  }
}

IFn(TEMPLATE_VECTOR, void, resize)(TEMPLATE_VECTOR* vec, size_t count) {
  size_t new_size = vec->size;
  while (count > new_size) {
    new_size *= 2;
  }
  vec->size = new_size;
  vec->data = (T*) realloc(vec->data, sizeof(T) * vec->size);
}

IFn(TEMPLATE_VECTOR, void, push_back)(TEMPLATE_VECTOR* vec, T value) {
  Method(TEMPLATE_VECTOR, resize)(vec, vec->length + 1);
  vec->data[vec->length] = value;
  vec->length += 1;
}

IFn(TEMPLATE_VECTOR, void, pop_back)(TEMPLATE_VECTOR* vec) {
  if (vec->length > 0) {
    vec->length -= 1;
  }
}

IFn(TEMPLATE_VECTOR, T*, begin)(TEMPLATE_VECTOR* vec) {
  return vec->data;
}

IFn(TEMPLATE_VECTOR, T*, end)(TEMPLATE_VECTOR* vec) {
  return vec->data + vec->length;
}

IFn(TEMPLATE_VECTOR, T*, at)(TEMPLATE_VECTOR* vec, size_t idx) {
  if (idx < vec->length) {
    return vec->data + idx;
  }
  return NULL;
}

IFn(TEMPLATE_VECTOR, T, get)(TEMPLATE_VECTOR* vec, size_t idx) {
  return *Method(TEMPLATE_VECTOR, at)(vec, idx);
}

IFn(TEMPLATE_VECTOR, void, set)(TEMPLATE_VECTOR* vec, size_t idx, T value) {
  *Method(TEMPLATE_VECTOR, at)(vec, idx) = value;
}

IFn(TEMPLATE_VECTOR, bool, empty)(TEMPLATE_VECTOR* vec) {
  return vec->length == 0;
}

IFn(TEMPLATE_VECTOR, size_t, size)(TEMPLATE_VECTOR* vec) {
  return vec->length;
}

#undef TEMPLATE_VECTOR
#endif
