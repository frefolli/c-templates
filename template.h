#ifndef C_TEMPLATE_H
#define C_TEMPLATE_H
#define CONCAT_2(A, B) A ## B
#define CONCAT_3(A, B, C) A ## B ## C
#define Template(ID, A) CONCAT_2(ID ## _, A)
#define Fn(ID, A, type, name) type CONCAT_3(ID ## _,A,  __ ## name)
#define IFn(ID, A, type, name) static inline type CONCAT_3(ID ## _,A,  __ ## name)
#define Method(ID, A, name) CONCAT_3(ID ## _, A, __ ## name)
#endif//C_TEMPLATE_H
