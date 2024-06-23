#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../mathlibc.h"

extern u64 MATHCALL binomial_coefficient(u32 n, u32 k);
extern u64 MATHCALL factorial(u32 num);

#ifdef __cplusplus
}
#endif
#endif // COMBINATORICS_H