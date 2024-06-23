#pragma once
#include <datatypes/data/vec.h>
#include <unity.h>

void
vec_init_test(void)
{
	vec_i32_t* vec = vec_init(VEC_I32_T);

	TEST_ASSERT_EQUAL(vec->vec_info.type, VEC_I32_T);
}

void
vec_free_test(void)
{
	vec_i32_t* vec = vec_init(VEC_I32_T);

	TEST_ASSERT_EQUAL(vec->vec_info.type, VEC_I32_T);
	TEST_ASSERT_EQUAL(vec_free(vec), true);
}

void
vec_capacity_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(10, vec_capacity(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
}

void
vec_contains_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 i32_contains = 1;
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	f32 f32_contains = 1.5;
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_contains(vec_i32, &i32_contains));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_contains(vec_f32, &f32_contains));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_clear_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 i32_push_back = 1;
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	vec_clear(vec_i32);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	f32 f32_push_back = 1.5;
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	vec_clear(vec_f32);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(0, vec_size(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_push_back(vec_i32, &i32_push_back));
	TEST_ASSERT_EQUAL(1, vec_size(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(0, vec_size(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_push_back(vec_f32, &f32_push_back));
	TEST_ASSERT_EQUAL(1, vec_size(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_extend_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 ints_extend[] = { 4, 5, 6 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);
	vec_i32_t* vec_i32_extend = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
	{
		vec_push_back(vec_i32, &ints[i]);
		vec_push_back(vec_i32_extend, &ints_extend[i]);
	}

	vec_extend(vec_i32, vec_i32_extend);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	f32 floats_extend[] = { 4.5, 5.5, 6.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);
	vec_f32_t* vec_f32_extend = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
	{
		vec_push_back(vec_f32, &floats[i]);
		vec_push_back(vec_f32_extend, &floats_extend[i]);
	}

	vec_extend(vec_f32, vec_f32_extend);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32_extend->vec_info.type);
	TEST_ASSERT_EQUAL(6, vec_size(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32_extend));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32_extend->vec_info.type);
	TEST_ASSERT_EQUAL(6, vec_size(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32_extend));
}

void
vec_find_all_test(void)
{
	i32 ints[] = { 1, 1, 1 };
	i32 i32_contains = 1;
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	f32 floats[] = { 1.5, 1.5, 1.5 };
	f32 f32_contains = 1.5;
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_find_all(vec_i32, &i32_contains));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_find_all(vec_f32, &f32_contains));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_get_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_get(vec_i32, 2));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(3.5f, vec_get(vec_f32, 2));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_index_of_test(void)
{
	i32 ints[] = { 1, 1, 3 };
	i32 i32_index = 1;
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	vec_u32* vec_i32_index = vec_index_of(vec_i32, &i32_index);

	f32 floats[] = { 1.5, 1.5, 3.5 };
	f32 f32_index = 1.5;
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	vec_u32* vec_u32_index = vec_index_of(vec_f32, &f32_index);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(2, vec_size(vec_i32_index));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32_index));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(2, vec_size(vec_u32_index));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_u32_index));
}

void
vec_insert_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 i32_insert_first = 0, i32_insert_last = 4;
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	vec_insert(vec_i32, 0, &i32_insert_first);
	vec_insert(vec_i32, 4, &i32_insert_last);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	f32 f32_insert_first = 0.5, f32_insert_last = 4.5;
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &ints[i]);

	vec_insert(vec_f32, 0, &f32_insert_first);
	vec_insert(vec_f32, 4, &f32_insert_last);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(0, vec_get(vec_i32, 0));
	TEST_ASSERT_EQUAL(4, vec_get(vec_i32, 4));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(0.5, vec_get(vec_f32, 0));
	TEST_ASSERT_EQUAL(4.5, vec_get(vec_f32, 4));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_is_empty_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);
	vec_i32_t* vec_i32_empty = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32_empty->vec_info.type);
	TEST_ASSERT_EQUAL(false, vec_is_empty(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_is_empty(vec_i32_empty));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
}

void
vec_is_equal_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 ints_equal[] = { 1, 2, 3 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);
	vec_i32_t* vec_i32_2 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
	{
		vec_push_back(vec_i32, &ints[i]);
		vec_push_back(vec_i32_2, &ints_equal[i]);
	}

	f32 floats[] = { 1.5, 2.5, 3.5 };
	f32 equal_floats[] = { 1.5, 2.5, 3.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);
	vec_f32_t* vec_f32_2 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
	{
		vec_push_back(vec_f32, &floats[i]);
		vec_push_back(vec_f32_2, &equal_floats[i]);
	}

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_i32, vec_i32_2));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32_2));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_f32, vec_f32_2));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32_2));
}

void
vec_pop_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_pop(vec_i32));
	TEST_ASSERT_EQUAL(2, vec_pop(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(3.5, vec_pop(vec_f32));
	TEST_ASSERT_EQUAL(2.5, vec_pop(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_push_back_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	f32 floats[] = { 1.5f, 2.5f, 3.5f };
	vec_f32* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_get(vec_i32, 2));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(3.5, vec_get(vec_f32, 2));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_remove_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	vec_remove(vec_i32, 1);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	vec_remove(vec_f32, 1);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(2, vec_size(vec_i32));
	TEST_ASSERT_EQUAL(3, vec_get(vec_i32, 1));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(2, vec_size(vec_f32));
	TEST_ASSERT_EQUAL(3.5f, vec_get(vec_f32, 1));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_reverse_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 ints_reverse[] = { 3, 2, 1 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);
	vec_i32_t* vec_i32_reverse = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
	{
		vec_push_back(vec_i32, &ints[i]);
		vec_push_back(vec_i32_reverse, &ints_reverse[i]);
	}

	vec_reverse(vec_i32);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	f32 floats_reverse[] = { 3.5, 2.5, 1.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);
	vec_f32_t* vec_f32_reverse = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
	{
		vec_push_back(vec_f32, &floats[i]);
		vec_push_back(vec_f32_reverse, &floats_reverse[i]);
	}

	vec_reverse(vec_f32);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32_reverse->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_i32, vec_i32_reverse));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32_reverse));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32_reverse->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_f32, vec_f32_reverse));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32_reverse));
}

void
vec_set_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 set_i32 = 99;
	vec_i32* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	vec_set(vec_i32, 0, &set_i32);

	f32 floats[] = { 1.5f, 2.5f, 3.5f };
	f32 set_f32 = 99.5f;
	vec_f32* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	vec_set(vec_f32, 0, &set_f32);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(99, vec_get(vec_i32, 0));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(99.5f, vec_get(vec_f32, 0));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_shrink_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	vec_shrink(vec_i32);

	f32 floats[] = { 1.5f, 2.5f, 3.5f };
	vec_f32* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	vec_shrink(vec_f32);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_capacity(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_capacity(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}


void
vec_size_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	vec_i32* vec_i32 = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
		vec_push_back(vec_i32, &ints[i]);

	f32 floats[] = { 1.5f, 2.5f, 3.5f };
	vec_f32* vec_f32 = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
		vec_push_back(vec_f32, &floats[i]);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_size(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(3, vec_size(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
}

void
vec_slice_test(void)
{
	i32 ints[] = { 1, 2, 3 };
	i32 ints_slice[] = { 1, 2};
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);
	vec_i32_t* vec_i32_slice = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
	{
		vec_push_back(vec_i32, &ints[i]);
	}

	for (uint i = 0; i < ARRAY_SIZE(ints_slice); i++)
	{
		vec_push_back(vec_i32_slice, &ints_slice[i]);
	}

	vec_i32_t* vec_i32_slice_test = vec_slice(vec_i32, 0, 2);

	f32 floats[] = { 1.5, 2.5, 3.5 };
	f32 floats_slice[] = { 1.5, 2.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);
	vec_f32_t* vec_f32_slice = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
	{
		vec_push_back(vec_f32, &floats[i]);
	}

	for (uint i = 0; i < ARRAY_SIZE(floats_slice); i++)
	{
		vec_push_back(vec_f32_slice, &floats_slice[i]);
	}

	vec_f32_t* vec_f32_slice_test = vec_slice(vec_f32, 0, 2);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32_slice->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_i32_slice, vec_i32_slice_test));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32_slice));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32_slice_test));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32_slice->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_f32_slice, vec_f32_slice_test));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32_slice));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32_slice_test));
}

void
vec_sort_test(void)
{
	i32 ints[] = { 3, 2, 1 };
	i32 ints_sorted[] = { 1, 2, 3 };
	vec_i32_t* vec_i32 = vec_init(VEC_I32_T);
	vec_i32_t* vec_i32_sorted = vec_init(VEC_I32_T);

	for (uint i = 0; i < ARRAY_SIZE(ints); i++)
	{
		vec_push_back(vec_i32, &ints[i]);
		vec_push_back(vec_i32_sorted, &ints_sorted[i]);
	}

	vec_sort(vec_i32);

	f32 floats[] = { 3.5, 2.5, 1.5 };
	f32 floats_sorted[] = { 1.5, 2.5, 3.5 };
	vec_f32_t* vec_f32 = vec_init(VEC_F32_T);
	vec_f32_t* vec_f32_sorted = vec_init(VEC_F32_T);

	for (uint i = 0; i < ARRAY_SIZE(floats); i++)
	{
		vec_push_back(vec_f32, &floats[i]);
		vec_push_back(vec_f32_sorted, &floats_sorted[i]);
	}

	vec_sort(vec_f32);

	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_I32_T, vec_i32_sorted->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_i32, vec_i32_sorted));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_i32_sorted));

	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32->vec_info.type);
	TEST_ASSERT_EQUAL(VEC_F32_T, vec_f32_sorted->vec_info.type);
	TEST_ASSERT_EQUAL(true, vec_is_equal(vec_f32, vec_f32_sorted));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32));
	TEST_ASSERT_EQUAL(true, vec_free(vec_f32_sorted));
}

void
vec_tests(void)
{
	RUN_TEST(vec_init_test);
	RUN_TEST(vec_free_test);
	RUN_TEST(vec_capacity_test);
	RUN_TEST(vec_contains_test);
	RUN_TEST(vec_clear_test);
	RUN_TEST(vec_extend_test);
	RUN_TEST(vec_find_all_test);
	RUN_TEST(vec_index_of_test);
	RUN_TEST(vec_insert_test);
	RUN_TEST(vec_is_empty_test);
	RUN_TEST(vec_is_equal_test);
	RUN_TEST(vec_get_test);
	RUN_TEST(vec_pop_test);
	RUN_TEST(vec_push_back_test);
	RUN_TEST(vec_remove_test);
	RUN_TEST(vec_reverse_test);
	RUN_TEST(vec_set_test);
	RUN_TEST(vec_shrink_test);
	RUN_TEST(vec_size_test);
	RUN_TEST(vec_slice_test);
	RUN_TEST(vec_sort_test);
}