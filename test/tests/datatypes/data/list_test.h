#pragma once
#include <datatypes/data/list.h>
#include <unity.h>

void
list_init_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
}

void
list_free_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_append_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12;

	list_append(list, int_append);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(1, list_size(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_contains_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12;

	list_append(list, int_append);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(1, list_size(list));
	TEST_ASSERT_EQUAL(true, list_contains(list, &int_append));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_clear_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12;

	list_append(list, int_append);
	list_clear(list);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(true, list_is_empty(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

bool
list_find_all_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_list[] = { 1, 1, 3 };

	for (uint i = 0; i < ARRAY_SIZE(int_list); i++)
	{
		list_append(list, int_list[i]);
	}

	u32 count = list_find_all(list, &int_list[0]);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(2, count);
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_first_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12;

	list_append(list, int_append);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(int_append, list_first(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_get_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12;

	list_append(list, int_append);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(int_append, list_get(list, 0));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_insert_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12, int_insert = 13;

	list_append(list, int_append);
	list_insert(list, 0, &int_insert);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(int_insert, list_get(list, 0));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_is_empty_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(true, list_is_empty(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_is_equal_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	list_i32_t* list_test = list_init(LIST_I32_T);
	i32 int_append = 12;

	list_append(list, int_append);
	list_append(list_test, int_append);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(list_test->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(true, list_is_equal(list, list_test));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_last_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12, int_append_2 = 13;

	list_append(list, int_append);
	list_append(list, int_append_2);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(int_append_2, list_last(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_remove_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12, int_append_2 = 13;

	list_append(list, int_append);
	list_append(list, int_append_2);

	list_remove(list, 1);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(1, list_size(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_reverse_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_list[] = {3, 2, 1};

	for (uint i = 0; i < ARRAY_SIZE(int_list); i++)
	{
		list_append(list, int_list[i]);
	}

	list_reverse(list);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(int_list[2], list_first(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_set_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 1, int_set = 2;

	list_append(list, int_append);
	list_set(list, 0, &int_set);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(int_set, list_first(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_size_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_append = 12;

	list_append(list, int_append);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(1, list_size(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_sort_test(void)
{
	list_i32_t* list = list_init(LIST_I32_T);
	i32 int_list[] = { 3, 2, 1 };

	for (uint i = 0; i < ARRAY_SIZE(int_list); i++)
	{
		list_i32_node_t* node = list_append(list, int_list[i]);
	}

	list_sort(list);

	TEST_ASSERT_EQUAL(list->list_info.type, LIST_I32_T);
	TEST_ASSERT_EQUAL(int_list[2], list_first(list));
	TEST_ASSERT_EQUAL(true, list_free(list));
}

void
list_tests(void)
{
	RUN_TEST(list_init_test);
	RUN_TEST(list_free_test);
	RUN_TEST(list_append_test);
	RUN_TEST(list_contains_test);
	RUN_TEST(list_clear_test);
	RUN_TEST(list_find_all_test);
	RUN_TEST(list_first_test);
	RUN_TEST(list_get_test);
 	RUN_TEST(list_insert_test);
	RUN_TEST(list_is_empty_test);
	RUN_TEST(list_last_test);
	RUN_TEST(list_remove_test);
	RUN_TEST(list_reverse_test);
	RUN_TEST(list_set_test);
	RUN_TEST(list_size_test);
	RUN_TEST(list_sort_test);
}