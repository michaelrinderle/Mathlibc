#pragma once
#include <datatypes/data/str.h>
#include <unity.h>
#include <string.h>

void
str_init_test(void)
{
	str_t* str = str_init("test");

	TEST_ASSERT_EQUAL(4, str->length);
	TEST_ASSERT_EQUAL(true, str_free(str));
}

void
str_free_test(void)
{
	str_t* str = str_init("test");

	TEST_ASSERT_EQUAL(true, str_free(str));
}

void
str_concatonate_test(void)
{
	str_t* str = str_init("test");
	str_concatenate(&str, "test");

	TEST_ASSERT_EQUAL(8, str->length);
	TEST_ASSERT_EQUAL(true, str_free(str));
}

void
str_compare_test(void)
{
	str_t* str1 = str_init("test");
	str_t* str2 = str_init("test");

	TEST_ASSERT_EQUAL(true, str_compare(str1, str2));
	TEST_ASSERT_EQUAL(true, str_free(str1));
	TEST_ASSERT_EQUAL(true, str_free(str2));
}

void
str_copy_test(void)
{
	str_t* str1 = str_init("test");
	str_t* str2 = str_copy(str1);

	TEST_ASSERT_EQUAL(true, str_compare(str1, str2));
	TEST_ASSERT_EQUAL(true, str_free(str1));
	TEST_ASSERT_EQUAL(true, str_free(str2));
}

void
str_insert_test(void)
{
	str_t* str1 = str_init("test");
	str_t* str2 = str_init("1test");
	str_insert(&str1, 0, "1");

	TEST_ASSERT_EQUAL(true, str_compare(str1, str2));
	TEST_ASSERT_EQUAL(true, str_free(str1));
	TEST_ASSERT_EQUAL(true, str_free(str2));
}

void
str_is_null_test(void)
{
	str_t* str = str_init("");

	TEST_ASSERT_EQUAL(true, str_is_null(str));
	TEST_ASSERT_EQUAL(true, str_free(str));
}

void
str_is_number_test(void)
{
	str_t* str = str_init("1");

	TEST_ASSERT_EQUAL(true, str_is_number(str));
	TEST_ASSERT_EQUAL(true, str_free(str));
}

void
str_is_sub_char_test(void)
{
	str_t* str = str_init("test");

	TEST_ASSERT_EQUAL(true, str_is_sub_char(str, 't'));
	TEST_ASSERT_EQUAL(true, str_free(str));
}

void
str_replace_test(void)
{
	str_t* str1 = str_init("test");
	str_t* str2 = str_init("t1st");
	str_replace(str1, 'e', '1');

	TEST_ASSERT_EQUAL(true, str_compare(str1, str2));
	TEST_ASSERT_EQUAL(true, str_free(str1));
	TEST_ASSERT_EQUAL(true, str_free(str2));
}

void
str_tokenize_test(void)
{
	str_t* str1 = str_init("test, test1");
	str_t* str2 = str_init("test");
	char** tokens = str_tokenize(str1, ',');

	TEST_ASSERT_EQUAL(0, stricmp(tokens[0], str2->buffer));
	TEST_ASSERT_EQUAL(true, str_free(str1));
	TEST_ASSERT_EQUAL(true, str_free(str2));
}

void
str_trim_test(void)
{
	str_t* str1 = str_init("test    ");
	char* str2 = str_trim(str1);

	TEST_ASSERT_EQUAL(0, stricmp(str2, "test"));
	TEST_ASSERT_EQUAL(true, str_free(str1));
	TEST_ASSERT_EQUAL(true, str_free(str2));
}

void
str_tests(void)
{
	RUN_TEST(str_init_test);
	RUN_TEST(str_free_test);
//	RUN_TEST(str_concatonate_test);
	RUN_TEST(str_compare_test);
//	RUN_TEST(str_copy_test);
	RUN_TEST(str_insert_test);
	RUN_TEST(str_is_null_test);
// 	RUN_TEST(str_is_number_test);
	RUN_TEST(str_is_sub_char_test);
//	RUN_TEST(str_replace_test);
//	RUN_TEST(str_tokenize_test);
//	RUN_TEST(str_trim_test);
}