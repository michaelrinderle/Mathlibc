#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../mathlibc.h"
#include <datatypes/data/vec.h>

extern API u32		MATHCALL greatest_common_divisor(u32 num1, u32 num2);
extern API u64		MATHCALL least_common_multiple(u32 num1, u32 num2);
extern API u32		MATHCALL num_of_divisors(u32 num);
extern API u64		MATHCALL modular_exponentiation(i64 base, u32 exponent, u32 modulus);
extern API vec_u64*	MATHCALL prime_factors(u32 num);
extern API u64		MATHCALL sum_of_divisors(u32 num);
extern API u64		MATHCALL sum_of_proper_divisors(u32 num);
extern API u64		MATHCALL sum_of_squares(u32 num);

#ifdef __cplusplus
}
#endif
#endif // NUMBER_THEORY_H