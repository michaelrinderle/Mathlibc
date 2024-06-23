#ifndef LIST_H
#define LIST_H
#ifdef __cplusplus
extern "C" {
#endif

#include "../../mathlibc.h"

typedef enum {
	LIST_I32_T,
	LIST_I64_T,
	LIST_U32_T,
	LIST_U64_T,
	LIST_F32_T,
	LIST_F64_T
} list_type;

typedef struct list_info_t {
	list_type type;
	u32 size;
} list_info_t, list_info;

typedef struct list_i32_node_t {
	i32 data;
	struct list_i32_node_t* prev;
	struct list_i32_node_t* next;
} list_i32_node_t, list_i32_node;

typedef struct list_i64_node_t {
	i64 data;
	struct list_i64_node_t* prev;
	struct list_i64_node_t* next;
} list_i64_node_t, list_i64_node;

typedef struct list_u32_node_t {
	u32 data;
	struct list_u32_node_t* prev;
	struct list_u32_node_t* next;
} list_u32_node_t, list_u32_node;

typedef struct list_u64_node_t {
	u64 data;
	struct list_u64_node_t* prev;
	struct list_u64_node_t* next;
} list_u64_node_t, list_u64_node;

typedef struct list_f32_node_t {
	f32 data;
	struct list_f32_node_t* prev;
	struct list_f32_node_t* next;
} list_f32_node_t, list_f32_node;

typedef struct list_f64_node_t {
	f64 data;
	struct list_f64_node_t* prev;
	struct list_f64_node_t* next;
} list_f64_node_t, list_f64_node_t;

typedef struct list_i32_t {
	list_info_t list_info;
	list_i32_node_t* first;
	list_i32_node_t* last;
} list_i32_t, list_i32;

typedef struct list_i64_t {
	list_info_t list_info;
	list_i64_node_t* first;
	list_i64_node_t* last;
} list_i64_t, list_i64;

typedef struct list_u32_t {
	list_info_t list_info;
	list_u32_node_t* first;
	list_u32_node_t* last;
} list_u32_t, list_u32;

typedef struct list_u64_t {
	list_info_t list_info;
	list_u64_node_t* first;
	list_u64_node_t* last;
} list_u64_t, list_u64;

typedef struct list_f32_t {
	list_info_t list_info;
	list_f32_node_t* first;
	list_f32_node_t* last;
} list_f32_t, list_f32;

typedef struct list_f64_t {
	list_info_t list_info;
	list_f64_node_t* first;
	list_f64_node_t* last;
} list_f64_t, list_f64;

// public list functions

extern API void*			MATHCALL list_init(list_type list_type);
extern API bool				MATHCALL list_free(void* self);
extern API bool				MATHCALL list_contains(void* self, const void* element);
extern API bool				MATHCALL list_clear(void* self);
extern API u32				MATHCALL list_find_all(void* self, const void* element);
extern API bool				MATHCALL list_insert(void* self, u32 index, const void* element);
extern API bool				MATHCALL list_is_empty(void* self);
extern API bool				MATHCALL list_is_equal(void* self, void* list);
extern API bool				MATHCALL list_remove(void* self, u32 index);
extern API bool				MATHCALL list_reverse(void* self);
extern API bool				MATHCALL list_set(void* self, u32 index, const void* element);
extern API u32				MATHCALL list_size(void* self);
extern API bool				MATHCALL list_sort(void* self);

// macros for public functions

#define list_append(list, element) \
	((list)->list_info.type == LIST_I32_T ? _list_append_i32((list_i32_t*)(list), (element)) : \
     (list)->list_info.type == LIST_I64_T ? _list_append_i32((list_i64_t*)(list), (element)) : \
     (list)->list_info.type == LIST_U32_T ? _list_append_u32((list_u32_t*)(list), (element)) : \
     (list)->list_info.type == LIST_U64_T ? _list_append_u64((list_u64_t*)(list), (element)) : \
     (list)->list_info.type == LIST_F32_T ? _list_append_f32((list_f32_t*)(list), (element)) : \
     (list)->list_info.type == LIST_F64_T ? _list_append_f64((list_f64_t*)(list), (element)) : 0)

#define list_first(list) \
	((list)->list_info.type == LIST_I32_T ? _list_first_i32((list_i32_t*)(list)) : \
     (list)->list_info.type == LIST_I64_T ? _list_first_i64((list_i64_t*)(list)) : \
     (list)->list_info.type == LIST_U32_T ? _list_first_u32((list_u32_t*)(list)) : \
     (list)->list_info.type == LIST_U64_T ? _list_first_u64((list_u64_t*)(list)) : \
     (list)->list_info.type == LIST_F32_T ? _list_first_f32((list_f32_t*)(list)) : \
     (list)->list_info.type == LIST_F64_T ? _list_first_f64((list_f64_t*)(list)) : 0)

#define list_get(list, index) \
	((list)->list_info.type == LIST_I32_T ? _list_get_i32((list_i32_t*)(list), (index)) : \
     (list)->list_info.type == LIST_I64_T ? _list_get_i64((list_i64_t*)(list), (index)) : \
     (list)->list_info.type == LIST_U32_T ? _list_get_u32((list_u32_t*)(list), (index)) : \
     (list)->list_info.type == LIST_U64_T ? _list_get_u64((list_u64_t*)(list), (index)) : \
     (list)->list_info.type == LIST_F32_T ? _list_get_f32((list_f32_t*)(list), (index)) : \
     (list)->list_info.type == LIST_F64_T ? _list_get_f64((list_f64_t*)(list), (index)) : 0)

#define list_last(list) \
	((list)->list_info.type == LIST_I32_T ? _list_last_i32((list_i32_t*)(list)) : \
     (list)->list_info.type == LIST_I64_T ? _list_last_i64((list_i64_t*)(list)) : \
     (list)->list_info.type == LIST_U32_T ? _list_last_u32((list_u32_t*)(list)) : \
     (list)->list_info.type == LIST_U64_T ? _list_last_u64((list_u64_t*)(list)) : \
     (list)->list_info.type == LIST_F32_T ? _list_last_f32((list_f32_t*)(list)) : \
     (list)->list_info.type == LIST_F64_T ? _list_last_f64((list_f64_t*)(list)) : 0)

// internal list function
extern API list_i32_node_t* MATHCALL _list_append_i32(list_i32_t* self, i32 element);
extern API list_i64_node_t* MATHCALL _list_append_i64(list_i64_t* self, i64 element);
extern API list_u32_node_t* MATHCALL _list_append_u32(list_u32_t* self, u32 element);
extern API list_u64_node_t* MATHCALL _list_append_u64(list_u64_t* self, u64 element);
extern API list_f32_node_t* MATHCALL _list_append_f32(list_f32_t* self, f32 element);
extern API list_f64_node_t* MATHCALL _list_append_f64(list_f64_t* self, f64 element);
extern API i32				MATHCALL _list_first_i32(list_i32_t* self);
extern API i64				MATHCALL _list_first_i64(list_i64_t* self);
extern API u32				MATHCALL _list_first_u32(list_u32_t* self);
extern API u64				MATHCALL _list_first_u64(list_u64_t* self);
extern API f32				MATHCALL _list_first_f32(list_f32_t* self);
extern API f64				MATHCALL _list_first_f64(list_f64_t* self);
extern API i32				MATHCALL _list_get_i32(list_i32_t* self, i32 index);
extern API i64				MATHCALL _list_get_i64(list_i64_t* self, i32 index);
extern API u32				MATHCALL _list_get_u32(list_u32_t* self, i32 index);
extern API u64				MATHCALL _list_get_u64(list_u64_t* self, i32 index);
extern API f32				MATHCALL _list_get_f32(list_f32_t* self, i32 index);
extern API f64				MATHCALL _list_get_f64(list_f64_t* self, i32 index);
extern API i32				MATHCALL _list_last_i32(list_i32_t* self);
extern API i64				MATHCALL _list_last_i64(list_i64_t* self);
extern API u32				MATHCALL _list_last_u32(list_u32_t* self);
extern API u64				MATHCALL _list_last_u64(list_u64_t* self);
extern API f32				MATHCALL _list_last_f32(list_f32_t* self);
extern API f64				MATHCALL _list_last_f64(list_f64_t* self);
extern API void*			MATHCALL _list_node_init(list_type type, void* data);

#ifdef __cplusplus
}
#endif
#endif // LIST_H