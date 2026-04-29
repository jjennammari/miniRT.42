#include "tests.h"

void	run_test(const char *test_msg, int (*test)());

int	main(void)
{
	printf("\n-------------------------\nRunning miniRT tests:\n\n");
	run_test("new_tuple", &test_new_tuple);
	run_test("new_point", &test_new_point);
	run_test("new_vector", &test_new_vector);
	run_test("add_tuple", &test_add_tuple);
	run_test("subtract_tuple", &test_subtract_tuple);
	run_test("negate_tuple", &test_negate_tuple);
	run_test("scalar_tuple", &test_scalar_tuple);
	run_test("divide_tuple", &test_divide_tuple);
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