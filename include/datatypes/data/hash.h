#ifndef HASH_H
#define HASH_H
#ifdef __cplusplus
extern "C" {
#endif

#include "../../mathlibc.h"

#define INITIAL_HASH_TABLE_SIZE 10
#define MAX_HASH_NAME 256
#define MAX_HASH_TABLE_SIZE 10000

typedef enum {
	HASH_I32_T,
	HASH_I64_T,
	HASH_U32_T,
	HASH_U64_T,
	HASH_F32_T,
	HASH_F64_T
} hash_type;

typedef struct hash_info_t {
	hash_type type;
	u32 table_size;
	u32 size;
} hash_info_t, hash_info;

typedef struct hashkv_i32_t {
	char key[MAX_HASH_NAME];
	i32 data;
} hashkv_i32_t, hashkv_i32;

typedef struct hashkv_i64_t {
	char key[MAX_HASH_NAME];
	i64 data;
} hashkv_i64_t, hashkv_i64;

typedef struct hashkv_u32_t {
	char key[MAX_HASH_NAME];
	u32 data;
} hashkv_u32_t, hashkv_u32;

typedef struct hashkv_u64_t {
	char key[MAX_HASH_NAME];
	u64 data;
} hashkv_u64_t, hashkv_u64;

typedef struct hashkv_f32_t {
	char key[MAX_HASH_NAME];
	f32 data;
} hashkv_f32_t, hashkv_f32;

typedef struct hashkv_f64_t {
	char key[MAX_HASH_NAME];
	f64 data;
} hashkv_f64_t, hashkv_f64;

typedef struct hash_i32_t {
	hash_info_t hash_info;
	hashkv_i32_t* table;
} hash_i32_t, hash_i32;

typedef struct hash_i64_t {
	hash_info_t hash_info;
	hashkv_i64_t* table;
} hash_i64_t, hash_i64;

typedef struct hash_u32_t {
	hash_info_t hash_info;
	hashkv_u32_t* table;
} hash_u32_t, hash_u32;

typedef struct hash_u64_t {
	hash_info_t hash_info;
	hashkv_u64_t* table;
} hash_u64_t, hash_u64;

typedef struct hash_f32_t {
	hash_info_t hash_info;
	hashkv_i32_t* table;
} hash_f32_t, hash_f32;

typedef struct hash_f64_t {
	hash_info_t hash_info;
	hashkv_i64_t* table;
} hash_f64_t, hash_f64;

// public hash functions

extern API void* MATHCALL hash_init(hash_type type);
extern API bool  MATHCALL hash_free(void* self);
extern API bool  MATHCALL hash_append(void* self, char* key, void* data);
extern API bool  MATHCALL hash_clear(void* self);
extern API bool  MATHCALL hash_contains(void* self, char* key);
extern API bool  MATHCALL hash_remove(void* self, char* key);
extern API bool  MATHCALL hash_replace(void* self, char* key, void* data);
extern API u32   MATHCALL hash_size(void* self);

// macros for public functions

// unified hash_get macro
#define hash_get(hash, key) \
	((hash)->hash_info.type == HASH_I32_T ? _hash_get_i32((hash_i32_t*)(hash), (key)) : \
     (hash)->hash_info.type == HASH_I64_T ? _hash_get_i64((hash_i64_t*)(hash), (key)) : \
     (hash)->hash_info.type == HASH_U32_T ? _hash_get_u32((hash_u32_t*)(hash), (key)) : \
     (hash)->hash_info.type == HASH_U64_T ? _hash_get_u64((hash_u64_t*)(hash), (key)) : \
     (hash)->hash_info.type == HASH_F32_T ? _hash_get_f32((hash_f32_t*)(hash), (key)) : \
     (hash)->hash_info.type == HASH_F64_T ? _hash_get_f64((hash_f64_t*)(hash), (key)) : 0)

// internal hash functions
extern API u32	 MATHCALL _hash_key(char* key);
extern API i32   MATHCALL _hash_get_i32(void* self, char* key);
extern API i64   MATHCALL _hash_get_i64(void* self, char* key);
extern API u32   MATHCALL _hash_get_u32(void* self, char* key);
extern API u64   MATHCALL _hash_get_u64(void* self, char* key);
extern API f32   MATHCALL _hash_get_f32(void* self, char* key);
extern API f64   MATHCALL _hash_get_f64(void* self, char* key);
extern API f32   MATHCALL _hash_load_factor(void* self);
extern API bool  MATHCALL _hash_resize(void* self);

#ifdef __cplusplus
}
#endif
#endif // HASH_H