#pragma once
#include <datatypes/data/vec.h>

void*
vec_init(vec_type vec_type)
{
	switch (vec_type)
	{
		case VEC_I32_T: {
			vec_i32_t* vec = (vec_i32_t*)malloc(sizeof(vec_i32_t));
			vec->data = malloc(sizeof(i32) * VEC_INITIAL_CAPACITY);
			vec->vec_info.size = 0;
			vec->vec_info.capacity = VEC_INITIAL_CAPACITY;
			vec->vec_info.type = VEC_I32_T;
			return vec;
		}
		case VEC_I64_T: {
			vec_i64_t* vec = (vec_i64_t*)malloc(sizeof(vec_i64_t));
			vec->data = malloc(sizeof(i64) * VEC_INITIAL_CAPACITY);
			vec->vec_info.size = 0;
			vec->vec_info.capacity = VEC_INITIAL_CAPACITY;
			vec->vec_info.type = VEC_I64_T;
			return vec;
		}
		case VEC_U32_T: {
			vec_u32_t* vec = (vec_u32_t*)malloc(sizeof(vec_u32_t));
			vec->data = malloc(sizeof(u32) * VEC_INITIAL_CAPACITY);
			vec->vec_info.size = 0;
			vec->vec_info.capacity = VEC_INITIAL_CAPACITY;
			vec->vec_info.type = VEC_U32_T;
			return vec;
		}
		case VEC_U64_T: {
			vec_u64_t* vec = (vec_u64_t*)malloc(sizeof(vec_u64_t));
			vec->data = malloc(sizeof(u64) * VEC_INITIAL_CAPACITY);
			vec->vec_info.size = 0;
			vec->vec_info.capacity = VEC_INITIAL_CAPACITY;
			vec->vec_info.type = VEC_U64_T;
			return vec;
		}
		case VEC_F32_T: {
			vec_f32_t* vec = (vec_f32_t*)malloc(sizeof(vec_f32_t));
			vec->data = malloc(sizeof(f32) * VEC_INITIAL_CAPACITY);
			vec->vec_info.size = 0;
			vec->vec_info.capacity = VEC_INITIAL_CAPACITY;
			vec->vec_info.type = VEC_F32_T;
			return vec;
		}
		case VEC_F64_T: {
			vec_f64_t* vec = (vec_f64_t*)malloc(sizeof(vec_f64_t));
			vec->data = malloc(sizeof(f64) * VEC_INITIAL_CAPACITY);
			vec->vec_info.size = 0;
			vec->vec_info.capacity = VEC_INITIAL_CAPACITY;
			vec->vec_info.type = VEC_F64_T;
			return vec;
		}
		default: {
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return NULL;
		}
	}
}

bool
vec_free(void* self)
{
	if (!self) return;

	vec_info_t* vec_info = (vec_info_t*)self;

	switch (vec_info->type)
	{
		case VEC_I32_T: {
			free(((vec_i32_t*)self)->data);
			break;
		}
		case VEC_I64_T: {
			free(((vec_i64_t*)self)->data);
			break;
		}
		case VEC_U32_T: {
			free(((vec_u32_t*)self)->data);
			break;
		}
		case VEC_U64_T: {
			free(((vec_u64_t*)self)->data);
			break;
		}
		case VEC_F32_T: {
			free(((vec_f32_t*)self)->data);
			break;
		}
		case VEC_F64_T: {
			free(((vec_f64_t*)self)->data);
			break;
		}
		default: {
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return NULL;
		}
	}

	free(self);
	self = NULL;
	if (self != NULL)
	{
		fprintf(stderr, "[*] vec_free : error freeing memory\n");
		return false;
	}

	return true;
}

i32
vec_capacity(void* self)
{
	return ((vec_info_t*)self)->capacity;
}

bool
vec_contains(void* self, const void* element)
{
	if (!self || !element) return false;

	vec_info_t* vec_info = (vec_info_t*)self;

	if (vec_info->size == 0) return false;

	size_t element_size = _vec_get_element_size(self);
	char* data_ptr = _vec_get_data_ptr(self);

	if (data_ptr == NULL) return false;

	// loop through each element & compare
	for (uint i = 0; i < vec_info->size; ++i)
	{
		if (memcmp(data_ptr + i * element_size, element, element_size) == 0)
		{
			return true; // element found
		}
	}

	return false;
}

bool
vec_clear(void* self)
{
	if (!self) return false;

	vec_info_t* vec_info = (vec_info_t*)self;

	// clear the size of vector
	vec_info->size = 0;
	vec_info->capacity = 0;

	switch (vec_info->type)
	{
		case VEC_I32_T:
		{
			vec_i32_t* vec = (vec_i32_t*)self;
			if (vec->data)
			{
				free(vec->data);
				vec->data = NULL;
			}
			break;
		}
		case VEC_I64_T:
		{
			vec_i64_t* vec = (vec_i64_t*)self;
			if (vec->data)
			{
				free(vec->data);
				vec->data = NULL;
			}
			break;
		}
		case VEC_U32_T:
		{
			vec_u32_t* vec = (vec_u32_t*)self;
			if (vec->data)
			{
				free(vec->data);
				vec->data = NULL;
			}
			break;
		}
		case VEC_U64_T:
		{
			vec_u64_t* vec = (vec_u64_t*)self;
			if (vec->data)
			{
				free(vec->data);
				vec->data = NULL;
			}
			break;
		}
		case VEC_F32_T:
		{
			vec_f32_t* vec = (vec_f32_t*)self;
			if (vec->data)
			{
				free(vec->data);
				vec->data = NULL;
			}
			break;
		}
		case VEC_F64_T:
		{
			vec_f64_t* vec = (vec_f64_t*)self;
			if (vec->data)
			{
				free(vec->data);
				vec->data = NULL;
			}
			break;
		}
		default:
		{
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return false;
		}
	}

	return true;
}

bool
vec_extend(void* self, void* vec)
{
	if (!self || !vec) return false;

	vec_info_t* self_vec_info = (vec_info_t*)self;
	vec_info_t* vec_info = (vec_info_t*)vec;

	if (self_vec_info->type != vec_info->type) return false;

	size_t element_size = _vec_get_element_size(self);

	for (uint i = 0; i < vec_info->size; ++i)
	{
		void* element = (char*)vec + sizeof(vec_info_t) + i * element_size;
		if (!vec_push_back(self, element)) {
			return false;
		}
	}

	return false;
}

u32
vec_find_all(void* self, const void* element)
{
	if (!self || !element) return 0;

	vec_info_t* vec_info = (vec_info_t*)self;

	if (vec_info->size == 0) return 0;

	size_t element_size = _vec_get_element_size(self);
	char* data_ptr = _vec_get_data_ptr(self);

	if (data_ptr == NULL) return NULL;

	// loop through each element & compare
	u32 count = 0;
	for (uint i = 0; i < vec_info->size; ++i)
	{
		if (memcmp(data_ptr + i * element_size, element, element_size) == 0)
		{
			count++; // element found
		}
	}

	return count;
}

vec_u32_t*
vec_index_of(void* self, const void* element)
{
	if (!self || !element) return NULL;

	vec_info_t* vec_info = (vec_info_t*)self;

	size_t element_size = _vec_get_element_size(self);
	char* data_ptr = _vec_get_data_ptr(self);

	if (data_ptr == NULL) return NULL;

	vec_u32* vec = vec_init(VEC_U32_T);

	// loop through each element & compare
	for (int i = 0; i < vec_info->size; ++i)
	{
		if (memcmp(data_ptr + i * element_size, element, element_size) == 0) {
			vec_push_back(vec, &i); // element found
		}
	}

	return vec;
}

bool
vec_insert(void* self, u32 index, const void* element)
{
	if (!self || !element) return false;

	vec_info_t* vec_info = (vec_info_t*)self;

	if (vec_info->size == 0 || index > vec_info->size) return false; // out of bounds

	char* data_ptr;
	size_t element_size = _vec_get_element_size(self);

	switch (vec_info->type)
	{
		case VEC_I32_T:
		{
			vec_i32_t* vec = (vec_i32_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity *= VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(i32) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			data_ptr = (char*)vec->data;
			break;
		}
		case VEC_I64_T:
		{
			vec_i64_t* vec = (vec_i64_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity *= VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(i64) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			data_ptr = (char*)vec->data;
			break;
		}
		case VEC_U32_T:
		{
			vec_u32_t* vec = (vec_u32_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity *= VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(u32) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			data_ptr = (char*)vec->data;
			break;
		}
		case VEC_U64_T:
		{
			vec_u64_t* vec = (vec_u64_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity *= VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(u64) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			data_ptr = (char*)vec->data;
			break;
		}
		case VEC_F32_T:
		{
			vec_f32_t* vec = (vec_f32_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity *= VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(f32) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			data_ptr = (char*)vec->data;
			break;
		}
		case VEC_F64_T:
		{
			vec_f64_t* vec = (vec_f64_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity *= VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(f64) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			data_ptr = (char*)vec->data;
			break;
		}
		default:
		{
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return false;
		}
	}

	// shift elements to the right to make space for the new element
	if (index < vec_info->size) {
		memmove(data_ptr + (index + 1) * element_size, data_ptr + index * element_size, (vec_info->size - index) * element_size);
	}

	// Insert new element
	memcpy(data_ptr + index * element_size, element, element_size);
	vec_info->size++;

	return true;
}

bool
vec_is_empty(void* self)
{
	return ((vec_info_t*)self)->size == 0;
}

bool
vec_is_equal(void* self, void* vec)
{
	if (!self || !vec) return false;

	vec_info_t* self_vec_info = (vec_info_t*)self;
	vec_info_t* vec_info = (vec_info_t*)vec;

	if (self_vec_info->type != vec_info->type) return false;
	if (self_vec_info->size != vec_info->size) return false;

	char* self_data_ptr = _vec_get_data_ptr(self);
	char* vec_data_ptr = _vec_get_data_ptr(vec);
	size_t element_size = _vec_get_element_size(self);

	return memcmp(self_data_ptr, vec_data_ptr, self_vec_info->size * element_size) == 0;
}

bool
vec_push_back(void* self, const void* element)
{
	if (!self || !element) return false;

	switch (((vec_info_t*)self)->type)
	{
		case VEC_I32_T:
		{
			vec_i32_t* vec = (vec_i32_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity += VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(i32) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			vec->data[vec->vec_info.size++] = *(i32*)element;
			return true;
		}
		case VEC_I64_T:
		{
			vec_i64_t* vec = (vec_i64_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity += VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(i64) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			vec->data[vec->vec_info.size++] = *(i64*)element;
			return true;
		}
		case VEC_U32_T:
		{
			vec_u32_t* vec = (vec_u32_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity += VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(u32) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			vec->data[vec->vec_info.size++] = *(u32*)element;
			return true;
		}
		case VEC_U64_T:
		{
			vec_u64_t* vec = (vec_u64_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity += VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(u64) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			vec->data[vec->vec_info.size++] = *(u64*)element;
			return true;
		}
		case VEC_F32_T:
		{
			vec_f32_t* vec = (vec_f32_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity += VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(f32) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			vec->data[vec->vec_info.size++] = *(f32*)element;
			return true;
		}
		case VEC_F64_T:
		{
			vec_f64_t* vec = (vec_f64_t*)self;
			if (vec->vec_info.size >= vec->vec_info.capacity)
			{
				vec->vec_info.capacity += VEC_INCREASE_BY;
				vec->data = realloc(vec->data, sizeof(f64) * vec->vec_info.capacity);
				if (!vec->data)
				{
					fprintf(stderr, "[*] vec_insert : failed to reallocate memory");
					return false;
				}
			}
			vec->data[vec->vec_info.size++] = *(f64*)element;
			return true;
		}
		default:
		{
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return false;
		}
	}
}

bool
vec_remove(void* self, u32 index)
{
	if (!self || !index) return false;

	vec_info_t* vec_info = (vec_info_t*)self;

	if (vec_info->size == 0 || index > vec_info->size - 1) return false;

	// shift elements or mark deleted as needed
	switch (((vec_info_t*)self)->type)
	{
		case VEC_I32_T:
		{
			if (index < ((vec_i32_t*)self)->vec_info.size)
			{
				for (u32 i = index; i < ((vec_i32_t*)self)->vec_info.size - 1; ++i)
				{
					((vec_i32_t*)self)->data[i] = ((vec_i32_t*)self)->data[i + 1];
				}
				((vec_i64_t*)self)->vec_info.size--;
			}
			break;
		}
		case VEC_I64_T:
		{
			if (index < ((vec_i64_t*)self)->vec_info.size)
			{
				for (u32 i = index; i < ((vec_i64_t*)self)->vec_info.size - 1; ++i)
				{
					((vec_i64_t*)self)->data[i] = ((vec_i64_t*)self)->data[i + 1];
				}
				((vec_i64_t*)self)->vec_info.size--;
			}
			break;
		}
		case VEC_U32_T:
		{
			if (index < ((vec_u32_t*)self)->vec_info.size)
			{
				for (u32 i = index; i < ((vec_u32_t*)self)->vec_info.size - 1; ++i)
				{
					((vec_u32_t*)self)->data[i] = ((vec_u32_t*)self)->data[i + 1];
				}
				((vec_u32_t*)self)->vec_info.size--;
			}
			break;
		}
		case VEC_U64_T:
		{
			if (index < ((vec_u64_t*)self)->vec_info.size)
			{
				for (u32 i = index; i < ((vec_u64_t*)self)->vec_info.size - 1; ++i)
				{
					((vec_u64_t*)self)->data[i] = ((vec_u64_t*)self)->data[i + 1];
				}
				((vec_u64_t*)self)->vec_info.size--;
			}
			break;
		}
		case VEC_F32_T:
		{
			if (index < ((vec_f32_t*)self)->vec_info.size)
			{
				for (u32 i = index; i < ((vec_f32_t*)self)->vec_info.size - 1; ++i)
				{
					((vec_f32_t*)self)->data[i] = ((vec_f32_t*)self)->data[i + 1];
				}
				((vec_f32_t*)self)->vec_info.size--;
			}
			break;
		}
		case VEC_F64_T:
		{
			if (index < ((vec_f64_t*)self)->vec_info.size)
			{
				for (u32 i = index; i < ((vec_f64_t*)self)->vec_info.size - 1; ++i)
				{
					((vec_f64_t*)self)->data[i] = ((vec_f64_t*)self)->data[i + 1];
				}
				((vec_f64_t*)self)->vec_info.size--;
			}
			break;
		}
		default: {
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return false;
		}
	}

	return true;
}

bool
vec_reverse(void* self)
{
	if (!self) return false;

	vec_info_t* vec_info = (vec_info_t*)self;
	size_t element_size = _vec_get_element_size(self);
	size_t element_num = vec_info->size;
	char* data_ptr = _vec_get_data_ptr(self);
	char* start = data_ptr;
	char* end = start + (element_num - 1) * element_size;
	char* temp = (char*)malloc(element_size);

	if (!temp)
	{
		fprintf(stderr, "[*] vec_reverse: failed to allocate memory\n");
		return false;
	}

	while (start < end)
	{
		// swap elements pointed by start & end
		memcpy(temp, start, element_size);
		memcpy(start, end, element_size);
		memcpy(end, temp, element_size);

		// move start and end pointers
		start += element_size;
		end -= element_size;
	}

	// free dynamically allocated memory
	free(temp);

	return true;
}

bool
vec_set(void* self, u32 index, const void* element)
{
	if (!self || !element) return false;

	vec_info_t* vec_info = (vec_info_t*)self;

	if (vec_info->size == 0 || index > vec_info->size - 1) return false;

	size_t element_size = 0;
	void* target_ptr;

	switch (vec_info->type)
	{
		case VEC_I32_T:
		{
			element_size = sizeof(i32);
			target_ptr = (void*)(((vec_i32_t*)self)->data + index);
			break;
		}
		case VEC_I64_T:
		{
			element_size = sizeof(i64);
			target_ptr = (void*)(((vec_i64_t*)self)->data + index);
			break;
		}
		case VEC_U32_T:
		{
			element_size = sizeof(u32);
			target_ptr = (void*)(((vec_u32_t*)self)->data + index);
			break;
		}
		case VEC_U64_T:
		{
			element_size = sizeof(u64);
			target_ptr = (void*)(((vec_u64_t*)self)->data + index);
			break;
		}
		case VEC_F32_T:
		{
			element_size = sizeof(f32);
			target_ptr = (void*)(((vec_f32_t*)self)->data + index);
			break;
		}
		case VEC_F64_T:
		{
			element_size = sizeof(f64);
			target_ptr = (void*)(((vec_f64_t*)self)->data + index);
			break;
		}
		default:
		{
				return false;
		}
	}

	memcpy(target_ptr, element, element_size);

	return true;
}

bool
vec_shrink(void* self)
{
	if (!self) return false;

	vec_info_t* vec_info = (vec_info_t*)self;
	size_t element_size = _vec_get_element_size(self);
	size_t capacity = vec_info->size;

	switch (vec_info->type)
	{
		case VEC_I32_T:
		{
			vec_i32_t* vec = (vec_i32_t*)self;
			i32* new_data = (i32*)realloc(vec->data, capacity * element_size);
			if (!new_data) {
				fprintf(stderr, "[*] vec_shrink: Memory allocation failed\n");
				return false;
			}
			vec->data = new_data;
			break;
		}
		case VEC_I64_T:
		{
			vec_i64_t* vec = (vec_i64_t*)self;
			i64* new_data = (i64*)realloc(vec->data, capacity * element_size);
			if (!new_data) {
				fprintf(stderr, "[*] vec_shrink: Memory allocation failed\n");
				return false;
			}
			vec->data = new_data;
			break;
		}
		case VEC_U32_T:
		{
			vec_u32_t* vec = (vec_u32_t*)self;
			u32* new_data = (u32*)realloc(vec->data, capacity * element_size);
			if (!new_data) {
				fprintf(stderr, "[*] vec_shrink: Memory allocation failed\n");
				return false;
			}
			vec->data = new_data;
			break;
		}
		case VEC_U64_T:
		{
			vec_u64_t* vec = (vec_u64_t*)self;
			u64* new_data = (u64*)realloc(vec->data, capacity * element_size);
			if (!new_data) {
				fprintf(stderr, "[*] vec_shrink: Memory allocation failed\n");
				return false;
			}
			vec->data = new_data;
			break;
		}
		case VEC_F32_T:
		{
			vec_f32_t* vec = (vec_f32_t*)self;
			f32* new_data = (f32*)realloc(vec->data, capacity * element_size);
			if (!new_data) {
				fprintf(stderr, "[*] vec_shrink: Memory allocation failed\n");
				return false;
			}
			vec->data = new_data;
			break;
		}
		case VEC_F64_T:
		{
			vec_f64_t* vec = (vec_f64_t*)self;
			f64* new_data = (f64*)realloc(vec->data, capacity * element_size);
			if (!new_data) {
				fprintf(stderr, "[*] vec_shrink: Memory allocation failed\n");
				return false;
			}
			vec->data = new_data;
			break;
		}
		default:
		{
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return false;
		}
	}

	// update capacity
	vec_info->capacity = capacity;

	return true;

}

i32
vec_size(void* self)
{
	return ((vec_info_t*)self)->size;
}

bool
vec_sort(void* self)
{
	if (!self) return false;

	vec_info_t* vec_info = (vec_info_t*)self;
	size_t element_size = _vec_get_element_size(self);

	void* data = _vec_get_data_ptr(self);

	switch (vec_info->type)
	{
		case VEC_I32_T:
		{
			qsort(data, vec_info->size, element_size, _vec_compare_func_i32);
			break;
		}
		case VEC_I64_T:
		{
			qsort(data, vec_info->size, element_size, _vec_compare_func_i64);
			break;
		}
		case VEC_U32_T:
		{
			qsort(data, vec_info->size, element_size, _vec_compare_func_u32);
			break;
		}
		case VEC_U64_T:
		{
			qsort(data, vec_info->size, element_size, _vec_compare_func_u64);
			break;
		}
		case VEC_F32_T:
		{
			qsort(data, vec_info->size, element_size, _vec_compare_func_f32);
			break;
		}
		case VEC_F64_T:
		{
			qsort(data, vec_info->size, element_size, _vec_compare_func_f64);
			break;
		}
		default:
		{
			fprintf(stderr, "[*] vec_init: unsupported vector type\n");
			return false;
		}
	}

	return true;
}

// internal vec functions

i32
_vec_compare_func_i32(const void* a, const void* b)
{
	return (*(const i32*)a - *(const i32*)b);
}

i32
_vec_compare_func_i64(const void* a, const void* b)
{
	return (*(const i64*)a - *(const i64*)b);
}

i32
_vec_compare_func_u32(const void* a, const void* b)
{
	return (*(const u32*)a - *(const u32*)b);
}

i32
_vec_compare_func_u64(const void* a, const void* b)
{
	return (*(const u64*)a - *(const u64*)b);
}

i32
_vec_compare_func_f32(const void* a, const void* b)
{
	f32 diff = *(const f32*)a - *(const f32*)b;
	if (diff < 0) return -1;
	else if (diff > 0) return 1;
	else return 0;
}

i32
_vec_compare_func_f64(const void* a, const void* b)
{
	f64 diff = *(const f64*)a - *(const f64*)b;
	if (diff < 0) return -1;
	else if (diff > 0) return 1;
	else return 0;
}

void*
_vec_get_data_ptr(void* self)
{
	if (!self) return NULL;

	vec_info_t* vec_info = (vec_info_t*)self;

	switch (vec_info->type)
	{
	case VEC_I32_T:
	{
		vec_i32_t* vec = (vec_i32_t*)self;
		return vec->data;
	}
	case VEC_I64_T:
	{
		vec_i64_t* vec = (vec_i64_t*)self;
		return vec->data;
	}
	case VEC_U32_T:
	{
		vec_u32_t* vec = (vec_u32_t*)self;
		return vec->data;
	}
	case VEC_U64_T:
	{
		vec_u64_t* vec = (vec_u64_t*)self;
		return vec->data;
	}
	case VEC_F32_T:
	{
		vec_f32_t* vec = (vec_f32_t*)self;
		return vec->data;
	}
	case VEC_F64_T:
	{
		vec_f64_t* vec = (vec_f64_t*)self;
		return vec->data;
	}
	default:
	{
		fprintf(stderr, "[*] vec_init: unsupported vector type\n");
		return NULL;
	}
	}
}

u64
_vec_get_element_size(void* self)
{
	switch (((vec_info_t*)self)->type)
	{
	case VEC_I32_T:
	{
		return sizeof(i32);
	}
	case VEC_I64_T:
	{
		return sizeof(i64);
	}
	case VEC_U32_T:
	{
		return sizeof(u32);
	}
	case VEC_U64_T:
	{
		return sizeof(u64);
	}
	case VEC_F32_T:
	{
		return sizeof(f32);
	}
	case VEC_F64_T:
	{
		return sizeof(f64);
	}
	default:
	{
		fprintf(stderr, "[*] vec_init: unsupported vector type\n");
		return 0;
	}
	}
}

i32
_vec_get_i32(vec_i32_t* self, u32 index)
{
	if (!self || index > self->vec_info.size)
	{
		fprintf(stderr, "[*] vec_get_i32 : null pointer or invalid index.");
		return NULL_VAL;
	}

	return self->data[index];
}

i64
_vec_get_i64(vec_i64_t* self, u32 index)
{
	if (!self || index > self->vec_info.size)
	{
		fprintf(stderr, "[*] vec_get_i64 : null pointer or invalid index.");
		return NULL_VAL;
	}

	return self->data[index];
}

u32
_vec_get_u32(vec_u32_t* self, u32 index)
{
	if (!self || index > self->vec_info.size)
	{
		fprintf(stderr, "[*] vec_get_u32 : null pointer or invalid index.");
		return NULL_VAL;
	}

	return self->data[index];
}

u64
_vec_get_u64(vec_u64_t* self, u32 index)
{
	if (!self || index > self->vec_info.size)
	{
		fprintf(stderr, "[*] vec_get_u64 : null pointer or invalid index.");
		return NULL_VAL;
	}

	return self->data[index];
}

f32
_vec_get_f32(vec_f32_t* self, u32 index)
{
	if (!self || index > self->vec_info.size)
	{
		fprintf(stderr, "[*] vec_get_f32 : null pointer or invalid index.");
		return NULL_VAL;
	}

	return self->data[index];
}

f64
_vec_get_f64(vec_f64_t* self, u32 index)
{
	if (!self || index > self->vec_info.size)
	{
		fprintf(stderr, "[*] vec_get_f64 : null pointer or invalid index.");
		return NULL_VAL;
	}

	return self->data[index];
}

i32
_vec_pop_i32(vec_i32_t* self)
{
	if (self->vec_info.size > 0)
	{
		return self->data[--self->vec_info.size];
	}
	else
	{
		fprintf(stderr, "[*] vec_pop_i32: vector is empty");
		return NULL_VAL;
	}
}

i64
_vec_pop_i64(vec_i64_t* self)
{
	if (self->vec_info.size > 0)
	{
		return self->data[--self->vec_info.size];
	}
	else
	{
		fprintf(stderr, "[*] vec_pop_i64: vector is empty");
		return NULL_VAL;
	}
}

u32
_vec_pop_u32(vec_u32_t* self)
{
	if (self->vec_info.size > 0)
	{
		return self->data[--self->vec_info.size];
	}
	else
	{
		fprintf(stderr, "[*] vec_pop_u32: vector is empty");
		return NULL_VAL;
	}
}

u64
_vec_pop_u64(vec_u64_t* self)
{
	if (self->vec_info.size > 0)
	{
		return self->data[--self->vec_info.size];
	}
	else
	{
		fprintf(stderr, "[*] vec_pop_u64: vector is empty");
		return NULL_VAL;
	}
}

f32
_vec_pop_f32(vec_f32_t* self)
{
	if (self->vec_info.size > 0)
	{
		return self->data[--self->vec_info.size];
	}
	else
	{
		fprintf(stderr, "[*] vec_pop_f32: vector is empty");
		return NULL_VAL;
	}
}

f64
_vec_pop_f64(vec_f64_t* self)
{
	if (self->vec_info.size > 0)
	{
		return self->data[--self->vec_info.size];
	}
	else
	{
		fprintf(stderr, "[*] vec_pop_f64: vector is empty");
		return NULL_VAL;
	}
}

vec_i32_t*
_vec_slice_i32(vec_i32_t* self, u32 start, u32 end)
{
	if (!self || start > end || end >= self->vec_info.size) return NULL;

	vec_i32_t* slice = vec_init(VEC_I32_T);
	if (!slice) return NULL;

	for (uint i = start; i < end; ++i)
	{
		if (!vec_push_back(slice, &self->data[i]))
		{
			vec_free(slice);
			return NULL;
		}
	}

	return slice;
}

vec_i64_t*
_vec_slice_i64(vec_i64_t* self, u32 start, u32 end)
{
	if (!self || start > end || end >= self->vec_info.size) return NULL;

	vec_i64_t* slice = vec_init(VEC_I64_T);
	if (!slice) return NULL;

	for (uint i = start; i < end; ++i)
	{
		if (!vec_push_back(slice, &self->data[i]))
		{
			vec_free(slice);
			return NULL;
		}
	}

	return slice;
}

vec_u32_t*
_vec_slice_u32(vec_u32_t* self, u32 start, u32 end)
{
	if (!self || start > end || end >= self->vec_info.size) return NULL;

	vec_u32_t* slice = vec_init(VEC_U32_T);
	if (!slice) return NULL;

	for (uint i = start; i < end; ++i)
	{
		if (!vec_push_back(slice, &self->data[i]))
		{
			vec_free(slice);
			return NULL;
		}
	}

	return slice;
}

vec_u64_t*
_vec_slice_u64(vec_u64_t* self, u32 start, u32 end)
{
	if (!self || start > end || end >= self->vec_info.size) return NULL;

	vec_u64_t* slice = vec_init(VEC_U64_T);
	if (!slice) return NULL;

	for (uint i = start; i < end; ++i)
	{
		if (!vec_push_back(slice, &self->data[i]))
		{
			vec_free(slice);
			return NULL;
		}
	}

	return slice;
}

vec_f32_t*
_vec_slice_f32(vec_f32_t* self, u32 start, u32 end)
{
	if (!self || start > end || end >= self->vec_info.size) return NULL;

	vec_f32_t* slice = vec_init(VEC_F32_T);
	if (!slice) return NULL;

	for (uint i = start; i < end; ++i)
	{
		if (!vec_push_back(slice, &self->data[i]))
		{
			vec_free(slice);
			return NULL;
		}
	}

	return slice;
}

vec_f64_t*
_vec_slice_f64(vec_f64_t* self, u32 start, u32 end)
{
	if (!self || start > end || end >= self->vec_info.size) return NULL;

	vec_f64_t* slice = vec_init(VEC_F64_T);
	if (!slice) return NULL;

	for (uint i = start; i < end; ++i)
	{
		if (!vec_push_back(slice, &self->data[i]))
		{
			vec_free(slice);
			return NULL;
		}
	}

	return slice;
}