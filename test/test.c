#include <unity.h>
#include "tests/datatypes/data/list_test.h"
#include "tests/datatypes/data/str_test.h"
#include "tests/datatypes/data/vec_test.h"
#include "tests/datatypes/fraction_test.h"
#include "tests/fields/number_theory_test.h"

void setUp(void) { }
void tearDown(void) { }

int
main(void)
{
	UNITY_BEGIN();

	// datatypes/data
	list_tests();
	// str_tests();
	vec_tests();

	// datatypes
	fraction_tests();

	// fields
	// number_theory_tests();

	return UNITY_END();
}