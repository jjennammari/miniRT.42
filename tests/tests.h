#ifndef TESTS_H
# define TESTS_H

# include "minirt.h"

int	test_create_tuple(void);
int	test_create_point(void);
int	test_create_vector(void);
int	test_sum_tuple(void);
int test_subtract_tuple(void);
int test_negate_tuple(void);
int	test_scalar_multiply_tuple(void);
int	test_scalar_divide_tuple(void);
int	test_dot_product(void);
int test_cross_product(void);

#endif // TESTS_H