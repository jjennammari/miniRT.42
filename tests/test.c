#include "tests.h"

void	run_test(const char *test_msg, int (*test)());

int	main(void)
{
	printf("\n-------------------------\nRunning miniRT tests:\n\n");
	run_test("create_tuple", &test_create_tuple);
	run_test("create_point", &test_create_point);
	run_test("create_vector", &test_create_vector);
	run_test("sum_tuple", &test_sum_tuple);
	run_test("subtract_tuple", &test_subtract_tuple);
	run_test("negate_tuple", &test_negate_tuple);
	run_test("scalar_multiply_tuple", &test_scalar_multiply_tuple);
	run_test("scalar_divide_tuple", &test_scalar_divide_tuple);
	run_test("dot_product", &test_dot_product);
	run_test("cross_product", &test_cross_product);
	printf("\nTests finished\n-------------------------\n\n");
}

void	run_test(const char *test_msg, int (*test)())
{
	printf("\t- %s:\n", test_msg);
	if (test() == -1)
		printf("\t\tFAIL");
	else if (test() == 0)
		printf("\t\tOK");
	else
		printf("Undefined");
	printf("\n");
}