#include <template.h>
#ifdef TEMPLATE_PAIR
#error "Template Pair is already under definition; Depending on the definition of the same Template with different arguments is an anti-pattern. Please reconsider your architectural choices."
#else
#ifndef F
#error "Template argument F not defined"
#endif
#ifndef S
#error "Template argument S not defined"
#endif
#define TEMPLATE_PAIR E_CONCAT3(Pair, F, S)

typedef struct {
  F first;
  S second;
} TEMPLATE_PAIR;

#undef TEMPLATE_PAIR
#endif
