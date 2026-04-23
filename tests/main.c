#include "minirt.h"
#include "tests.h"

void	run_test(const char *test_msg, int (*test)());

int	main(void)
{
	printf("Running miniRT tests:\n");
	run_test("new_tuple, new_point and new_vector", &tuple);
}

void	run_test(const char *test_msg, int (*test)())
{
	printf("%s:\n", test_msg);
	if (test() == -1)
		printf("FAIL");
	else if (test() == 0)
		printf("OK");
	else
		printf("Undefined");
	printf("\n");
}