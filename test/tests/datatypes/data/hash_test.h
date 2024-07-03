#pragma once
#include <datatypes/data/hash.h>
#include <unity.h>

void
hash_init_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);

	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_free_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);

	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_append_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);
	i32 ints[] = {1, 2, 3};

	hash_append(hash, "one", &ints[0]);
	hash_append(hash, "two", &ints[1]);
	hash_append(hash, "three", &ints[2]);

	TEST_ASSERT_EQUAL(3, hash->hash_info.size);
	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_clear_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);
	i32 ints[] = { 1, 2, 3 };

	hash_append(hash, "one", &ints[0]);
	hash_append(hash, "two", &ints[1]);
	hash_append(hash, "three", &ints[2]);

	hash_clear(hash);

	TEST_ASSERT_EQUAL(0, hash->hash_info.size);
	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_contains_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);
	i32 ints[] = { 1, 2, 3 };

	hash_append(hash, "one", &ints[0]);
	hash_append(hash, "two", &ints[1]);
	hash_append(hash, "three", &ints[2]);

	TEST_ASSERT_EQUAL(true, hash_contains(hash, "one"));
	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_get_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);
	i32 ints[] = { 1, 2, 3 };

	hash_append(hash, "one", &ints[0]);
	hash_append(hash, "two", &ints[1]);
	hash_append(hash, "three", &ints[2]);

	TEST_ASSERT_EQUAL(1, hash_get(hash, "one"));
	TEST_ASSERT_EQUAL(2, hash_get(hash, "two"));
	TEST_ASSERT_EQUAL(3, hash_get(hash, "three"));
	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_remove_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);
	i32 ints[] = { 1, 2, 3 };

	hash_append(hash, "one", &ints[0]);
	hash_append(hash, "two", &ints[1]);
	hash_append(hash, "three", &ints[2]);

	TEST_ASSERT_EQUAL(true, hash_remove(hash, "one"));
	TEST_ASSERT_EQUAL(2, hash->hash_info.size);
	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_replace_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);
	i32 ints[] = { 1, 2, 3 };

	hash_append(hash, "one", &ints[0]);
	hash_replace(hash, "one", &ints[1]);

	TEST_ASSERT_EQUAL(2, hash_get(hash, "one"));
	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_size_test(void)
{
	hash_i32_t* hash = hash_init(HASH_I32_T);
	i32 ints[] = { 1, 2, 3 };

	hash_append(hash, "one", &ints[0]);
	hash_append(hash, "two", &ints[1]);
	hash_append(hash, "three", &ints[2]);

	TEST_ASSERT_EQUAL(3, hash_size(hash));
	TEST_ASSERT_EQUAL(true, hash_free(hash));
}

void
hash_tests(void)
{
	RUN_TEST(hash_init_test);
	RUN_TEST(hash_free_test);
	RUN_TEST(hash_append_test);
	RUN_TEST(hash_clear_test);
	RUN_TEST(hash_contains_test);
	RUN_TEST(hash_get_test);
	RUN_TEST(hash_remove_test);
	RUN_TEST(hash_replace_test);
	RUN_TEST(hash_size_test);
}