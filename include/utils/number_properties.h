#ifndef NUMBER_PROPERTIES_H
#define NUMBER_PROPERTIES_H

#ifdef __cplusplus
extern "C" {
#endif

	#include "../mathlibc.h"

	extern API u32	MATHCALL num_of_decimal_places(dbl num);
	extern API u32	MATHCALL num_of_digits(u32 num);
	extern API u32	MATHCALL sum_of_digits(u32 num);
	extern API u32	MATHCALL sum_of_squares_of_digits(u32 num);

#ifdef __cplusplus
}
#endif
#endif // NUMBER_PROPERTIES_H