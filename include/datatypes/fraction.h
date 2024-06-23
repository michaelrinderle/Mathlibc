#ifndef FRACTION_H
#define FRACTION_H

#ifdef __cplusplus
extern "C" {
#endif

	#include "../mathlibc.h"
	#include "data/str.h"

	typedef struct fraction_t {
		int numerator;
		unsigned int denominator;
	} fraction_t, fraction;

	extern API fraction_t*		MATHCALL fraction_init(int numerator, unsigned int denominator);
	extern API bool				MATHCALL fraction_free(fraction_t* self);
	extern API fraction_t*		MATHCALL fraction_reciprocal(fraction_t* self);
	extern API void				MATHCALL fraction_simplify(fraction_t* self);
	extern API double			MATHCALL fraction_to_decimal(fraction_t* self);
	extern API str_t*			MATHCALL fraction_to_string(fraction_t* self);


#ifdef __cplusplus
}
#endif
#endif // FRACTION_H
