#ifndef STR_H
#define STR_H
#ifdef __cplusplus
extern "C" {
#endif

#include "../../mathlibc.h"

typedef struct str_t {
	unsigned int size;
	unsigned int length;
	char buffer[];
} str_t, str;

extern API str_t*	MATHCALL str_init(char* str);
extern API bool		MATHCALL str_free(str_t* self);
extern API bool		MATHCALL str_concatenate(str_t* self, char* cat_str);
extern API bool		MATHCALL str_compare(str_t* self, str_t* str);
extern API str_t*	MATHCALL str_copy(str_t* self);
extern API bool		MATHCALL str_insert(str_t** self, uint pos, char* insert_str);
extern API bool		MATHCALL str_is_null(str_t* self);
extern API bool		MATHCALL str_is_number(str_t* self);
extern API bool		MATHCALL str_is_sub_char(str_t* self, char c);
extern API char*	MATHCALL str_replace(str_t** self, const char* target, const char* replace);
extern API char**	MATHCALL str_tokenize(str_t* self, char delim);
extern API char*	MATHCALL str_trim(str_t** self);

#ifdef __cplusplus
}
#endif
#endif // STR_H