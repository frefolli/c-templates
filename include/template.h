#ifndef C_TEMPLATES_H
#define C_TEMPLATES_H
#define CONCAT_2(A, B) A ## B
#define CONCAT_3(A, B, C) A ## B ## C
#define Fn(ID, type, name) type CONCAT_2(ID,  __ ## name)
#define IFn(ID, type, name) static inline type CONCAT_2(ID,  __ ## name)
#define Method(ID, name) CONCAT_2(ID, __ ## name)

#define E_CONCAT2_I(a, b) a ## _ ## b
#define E_CONCAT2(...) E_CONCAT2_I(__VA_ARGS__)
#define E_CONCAT3_I(a, b, c) a ## _ ## b ## _ ## c
#define E_CONCAT3(...) E_CONCAT3_I(__VA_ARGS__)
#endif//C_TEMPLATES_H
