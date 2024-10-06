#include <template.h>
#ifndef TEMPLATE_PAIR
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
