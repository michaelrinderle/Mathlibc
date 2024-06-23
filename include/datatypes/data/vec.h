#ifndef VEC_H
#define VEC_H
#ifdef __cplusplus
extern "C" {
#endif

#include "../../mathlibc.h"

#define VEC_INITIAL_CAPACITY 10
#define VEC_INCREASE_BY 2

typedef enum {
	VEC_I32_T,
	VEC_I64_T,
	VEC_U32_T,
	VEC_U64_T,
	VEC_F32_T,
	VEC_F64_T
} vec_type;

typedef struct vec_info_t {
	vec_type type;
	u32 capacity;
	u32 size;
} vec_info_t, vec_info;

typedef struct vec_i32_t {
	vec_info vec_info;
	i32* data;
} vec_i32_t, vec_i32;

typedef struct vec_i64_t {
	vec_info vec_info;
	i64* data;
} vec_i64_t, vec_i64;

typedef struct vec_u32_t {
	vec_info vec_info;
	u32* data;
} vec_u32_t, vec_u32;

typedef struct vec_u64_t {
	vec_info vec_info;
	u64* data;
} vec_u64_t, vec_u64;

typedef struct vec_f32_t {
	vec_info vec_info;
	f32* data;
} vec_f32_t, vec_f32;

typedef struct vec_f64_t {
	f64* data;
	vec_info vec_info;
} vec_f64_t, vec_f64;

// public vec functions
extern API void*	  MATHCALL vec_init(vec_type vec_type);
extern API bool		  MATHCALL vec_free(void* self);
extern API i32		  MATHCALL vec_capacity(void* self);
extern API bool		  MATHCALL vec_contains(void* self, const void* element);
extern API bool		  MATHCALL vec_clear(void* self);
extern API bool		  MATHCALL vec_extend(void* self, void* vec);
extern API u32		  MATHCALL vec_find_all(void* self, const void* element);
extern API vec_u32_t* MATHCALL vec_index_of(void* self, const void* element);
extern API bool		  MATHCALL vec_insert(void* self, u32 index, const void* element);
extern API bool		  MATHCALL vec_is_empty(void* self);
extern API bool		  MATHCALL vec_is_equal(void* self, void* vec);
extern API bool	      MATHCALL vec_push_back(void* self, const void* element);
extern API bool	      MATHCALL vec_remove(void* self, u32 index);
extern API bool		  MATHCALL vec_reverse(void* self);
extern API bool       MATHCALL vec_set(void* self, u32 index, const void* element);
extern API bool		  MATHCALL vec_shrink(void* self);
extern API i32        MATHCALL vec_size(void* self);
extern API bool		  MATHCALL vec_sort(void* self);

// Macros for public functions

// unified vec_get macro
#define vec_get(vec, index) \
	((vec)->vec_info.type == VEC_I32_T ? _vec_get_i32((vec_i32_t*)(vec), (index)) : \
     (vec)->vec_info.type == VEC_I64_T ? _vec_get_i64((vec_i64_t*)(vec), (index)) : \
     (vec)->vec_info.type == VEC_U32_T ? _vec_get_u32((vec_u32_t*)(vec), (index)) : \
     (vec)->vec_info.type == VEC_U64_T ? _vec_get_u64((vec_u64_t*)(vec), (index)) : \
     (vec)->vec_info.type == VEC_F32_T ? _vec_get_f32((vec_f32_t*)(vec), (index)) : \
     (vec)->vec_info.type == VEC_F64_T ? _vec_get_f64((vec_f64_t*)(vec), (index)) : 0)

// unified vec_get macro
#define vec_pop(vec) \
	((vec)->vec_info.type == VEC_I32_T ? _vec_pop_i32((vec_i32_t*)(vec)) : \
     (vec)->vec_info.type == VEC_I64_T ? _vec_pop_i64((vec_i64_t*)(vec)) : \
     (vec)->vec_info.type == VEC_U32_T ? _vec_pop_u32((vec_u32_t*)(vec)) : \
     (vec)->vec_info.type == VEC_U64_T ? _vec_pop_u64((vec_u64_t*)(vec)) : \
     (vec)->vec_info.type == VEC_F32_T ? _vec_pop_f32((vec_f32_t*)(vec)) : \
     (vec)->vec_info.type == VEC_F64_T ? _vec_pop_f64((vec_f64_t*)(vec)) : 0)

// unified vec_slice macros
#define vec_slice(vec, start, end) \
	((vec)->vec_info.type == VEC_I32_T ? _vec_slice_i32((vec_i32_t*)(vec), (start), (end)) : \
     (vec)->vec_info.type == VEC_I64_T ? _vec_slice_i64((vec_i64_t*)(vec), (start), (end)) : \
     (vec)->vec_info.type == VEC_U32_T ? _vec_slice_u32((vec_u32_t*)(vec), (start), (end)) : \
     (vec)->vec_info.type == VEC_U64_T ? _vec_slice_u64((vec_u64_t*)(vec), (start), (end)) : \
     (vec)->vec_info.type == VEC_F32_T ? _vec_slice_f32((vec_f32_t*)(vec), (start), (end)) : \
     (vec)->vec_info.type == VEC_F64_T ? _vec_slice_f64((vec_f64_t*)(vec), (start), (end)) : 0)

// internal vec functions
extern API i32		  MATHCALL _vec_compare_func_i32(const void* a, const void* b);
extern API i32		  MATHCALL _vec_compare_func_i64(const void* a, const void* b);
extern API i32		  MATHCALL _vec_compare_func_u32(const void* a, const void* b);
extern API i32		  MATHCALL _vec_compare_func_u64(const void* a, const void* b);
extern API i32		  MATHCALL _vec_compare_func_f32(const void* a, const void* b);
extern API i32		  MATHCALL _vec_compare_func_f64(const void* a, const void* b);
extern API void*	  MATHCALL _vec_get_data_ptr(void* self);
extern API u64		  MATHCALL _vec_get_element_size(void* self);
extern API i32		  MATHCALL _vec_get_i32(vec_i32_t* self, u32 index);
extern API i64		  MATHCALL _vec_get_i64(vec_i64_t* self, u32 index);
extern API u32		  MATHCALL _vec_get_u32(vec_u32_t* self, u32 index);
extern API u64		  MATHCALL _vec_get_u64(vec_u64_t* self, u32 index);
extern API f32		  MATHCALL _vec_get_f32(vec_f32_t* self, u32 index);
extern API f64		  MATHCALL _vec_get_f64(vec_f64_t* self, u32 index);
extern API i32		  MATHCALL _vec_pop_i32(vec_i32_t* self);
extern API i64		  MATHCALL _vec_pop_i64(vec_i64_t* self);
extern API u32		  MATHCALL _vec_pop_u32(vec_u32_t* self);
extern API u64		  MATHCALL _vec_pop_u64(vec_u64_t* self);
extern API f32		  MATHCALL _vec_pop_f32(vec_f32_t* self);
extern API f64		  MATHCALL _vec_pop_f64(vec_f64_t* self);
extern API vec_i32_t* MATHCALL _vec_slice_i32(vec_i32_t* self, u32 start, u32 end);
extern API vec_i64_t* MATHCALL _vec_slice_i64(vec_i64_t* self, u32 start, u32 end);
extern API vec_u32_t* MATHCALL _vec_slice_u32(vec_u32_t* self, u32 start, u32 end);
extern API vec_u64_t* MATHCALL _vec_slice_u64(vec_u64_t* self, u32 start, u32 end);
extern API vec_f32_t* MATHCALL _vec_slice_f32(vec_f32_t* self, u32 start, u32 end);
extern API vec_f64_t* MATHCALL _vec_slice_f64(vec_f64_t* self, u32 start, u32 end);

#ifdef __cplusplus
}
#endif
#endif // VEC_H