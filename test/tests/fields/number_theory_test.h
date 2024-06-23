#pragma once
#include <fields/number_theory.h>


void
greatest_common_divisor_test(void)
{
	TEST_ASSERT_EQUAL(2, greatest_common_divisor(2, 4));
	TEST_ASSERT_EQUAL(3, greatest_common_divisor(3, 9));
	TEST_ASSERT_EQUAL(4, greatest_common_divisor(4, 12));
}

void
least_common_multiple_test(void)
{
	TEST_ASSERT_EQUAL(4, least_common_multiple(2, 4));
	TEST_ASSERT_EQUAL(9, least_common_multiple(3, 9));
	TEST_ASSERT_EQUAL(12, least_common_multiple(4, 12));
}

void
num_of_divisors_test(void)
{
	TEST_ASSERT_EQUAL(1, num_of_divisors(1));
	TEST_ASSERT_EQUAL(6, num_of_divisors(12));
	TEST_ASSERT_EQUAL(8, num_of_divisors(24));

}

void
modular_exponentiation_test(void)
{
	TEST_ASSERT_EQUAL(3, modular_exponentiation(2, 3, 5));
	TEST_ASSERT_EQUAL(4, modular_exponentiation(5, 2, 7));
	TEST_ASSERT_EQUAL(1, modular_exponentiation(3, 5, 11));
}

void
sum_of_divisors_test(void)
{
	TEST_ASSERT_EQUAL(12, sum_of_divisors(6));
	TEST_ASSERT_EQUAL(28, sum_of_divisors(12));
	TEST_ASSERT_EQUAL(56, sum_of_divisors(28));
}

void
sum_of_proper_divisors_test(void)
{
	TEST_ASSERT_EQUAL(16, sum_of_proper_divisors(12));
	TEST_ASSERT_EQUAL(15, sum_of_proper_divisors(16));
	TEST_ASSERT_EQUAL(6, sum_of_proper_divisors(25));
}

void
sum_of_squares_test(void)
{
	TEST_ASSERT_EQUAL(14, sum_of_squares(123));
	TEST_ASSERT_EQUAL(75, sum_of_squares(555));
	TEST_ASSERT_EQUAL(230, sum_of_squares(9876));
}

void
number_theory_tests(void)
{
	RUN_TEST(greatest_common_divisor_test);
	RUN_TEST(least_common_multiple_test);
	RUN_TEST(num_of_divisors_test);
	RUN_TEST(modular_exponentiation_test);
	RUN_TEST(sum_of_divisors_test);
	RUN_TEST(sum_of_proper_divisors_test);
	RUN_TEST(sum_of_squares_test);
}