#pragma once
#include <datatypes/fraction.h>
#include <unity.h>

void
fraction_init_test(void)
{
	fraction_t* frac = fraction_init(1, 2);

	TEST_ASSERT_EQUAL(1, frac->numerator);
	TEST_ASSERT_EQUAL(2, frac->denominator);
	TEST_ASSERT_EQUAL(true, fraction_free(frac));
}

void
fraction_free_test(void)
{
	fraction_t* frac = fraction_init(1, 2);

	TEST_ASSERT_EQUAL(true, fraction_free(frac));
}

void
fraction_reciprocal_test(void)
{
	fraction_t* frac = fraction_init(1, 2);
	fraction_t* reciprocal = fraction_reciprocal(frac);

	TEST_ASSERT_EQUAL(2, reciprocal->numerator);
	TEST_ASSERT_EQUAL(1, reciprocal->denominator);
	TEST_ASSERT_EQUAL(true, fraction_free(frac));
}

void
fraction_simplify_test(void)
{
	fraction_t* frac = fraction_init(2, 4);
	fraction_simplify(frac);

	TEST_ASSERT_EQUAL(1, frac->numerator);
	TEST_ASSERT_EQUAL(2, frac->denominator);
	TEST_ASSERT_EQUAL(true, fraction_free(frac));
}

void
fraction_to_decimal_test(void)
{
	fraction_t* frac = fraction_init(1, 2);
	double dec = fraction_to_decimal(frac);

	TEST_ASSERT_EQUAL(0.5, dec);
	TEST_ASSERT_EQUAL(true, fraction_free(frac));
}

void
fraction_to_string_test(void)
{
	fraction_t* frac = fraction_init(1, 2);
	str_t* frac_str = fraction_to_string(frac);
	str_t* frac_str_cmp = str_init("1/2");

	TEST_ASSERT_EQUAL(true, str_compare(frac_str, frac_str_cmp));
	TEST_ASSERT_EQUAL(true, fraction_free(frac));
}

void
fraction_tests(void)
{
	RUN_TEST(fraction_init_test);
	RUN_TEST(fraction_free_test);
	RUN_TEST(fraction_reciprocal_test);
	RUN_TEST(fraction_simplify_test);
	RUN_TEST(fraction_to_decimal_test);
	RUN_TEST(fraction_to_string_test);
}