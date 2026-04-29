#include "tests.h"

int	test_create_tuple(void)
{
	t_tuple *t;

	t = create_tuple(4.3, -4.2, 3.1, 1);
	if (t->x != 4.3 || t->y != -4.2 || t->z != 3.1 || t->w != 1.0)
		return (-1);
	free(t);
	return (0);
}

int	test_create_point(void)
{
	t_tuple	*p;

	p = create_point(4.2, -4, 3);
	if (p->x != 4.2 || p->y != -4 || p->z != 3 || p->w != 1)
		return (-1);
	free(p);
	return (0);
}

int	test_create_vector(void)
{
	t_tuple	*v;

	v = create_vector(4, -4, 3);
	if (v->x != 4 || v->y != -4 || v->z != 3 || v->w != 0)
		return (-1);
	free(v);
	return (0);
}

int test_sum_tuple(void)
{
	t_tuple	*t1;
	t_tuple	*t2;
	t_tuple *res;

	t1 = create_point(1, 2, 3);
	t2 = create_vector(1, 2, 3);
	res = sum_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2.0f || res->y != 4.0f || res->z != 6.0f || res->w != 1.0f)
		return (-1);
	free(res);
	
	t1 = create_vector(1, 2, 3);
	t2 = create_vector(1, 2, 3);
	res = sum_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2.0f || res->y != 4.0f || res->z != 6.0f || res->w != 0.0f)
		return (-1);
	free(res);

	return (0);
}

int test_subtract_tuple(void)
{
	t_tuple	*t1;
	t_tuple	*t2;
	t_tuple *res;

	t1 = create_point(3, 1, 2);
	t2 = create_vector(1, 2, 3);
	res = subtract_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != -1 || res->z != -1 || res->w != 1)
		return (-1);
	free(res);
	
	t1 = create_vector(3, 1, 2);
	t2 = create_vector(1, 2, 3);
	res = subtract_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != -1 || res->z != -1 || res->w != 0)
		return (-1);
	free(res);

	t1 = create_vector(3, 1, 2);
	t2 = create_vector(1, 2, 3);
	res = subtract_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != -1 || res->z != -1 || res->w != 0)
		return (-1);
	free(res);

	return (0);
}

int test_negate_tuple(void)
{
	t_tuple	*t1;
	t_tuple *res;

	t1 = create_tuple(1, 2, 3, 0);
	res = negate_tuple(t1);
	free(t1);
	if (!res || res->x != -1 || res->y != -2 || res->z != -3 || res->w != 0)
		return (-1);
	free(res);
	
	t1 = create_tuple(1, 2, 3, 0);
	res = negate_tuple(t1);
	free(t1);
	if (!res || res->x != -1 || res->y != -2 || res->z != -3 || res->w != 0)
		return (-1);
	free(res);

	t1 = create_tuple(1, -2, 3, 0);
	res = negate_tuple(t1);
	free(t1);
	if (!res || res->x != -1 || res->y != 2 || res->z != -3 || res->w != 0)
		return (-1);
	free(res);

	return (0);
}

int	test_scalar_multiply_tuple(void)
{
	t_tuple	*t1;
	t_tuple *res;

	t1 = create_tuple(1, -2, 3, -4);
	res = scalar_multiply_tuple(t1, 3.5);
	free(t1);
	if (!res || res->x != 3.5f || res->y != -7 || res->z != 10.5f || res->w != -14)
		return (-1);
	free(res);

	t1 = create_tuple(1, -2, 3, -4);
	res = scalar_multiply_tuple(t1, 0.5);
	free(t1);
	if (!res || res->x != 0.5f || res->y != -1 || res->z != 1.5f || res->w != -2)
		return (-1);
	free(res);

	return (0);
}

int	test_scalar_divide_tuple(void)
{
	t_tuple	*t1;
	t_tuple *res;

	t1 = create_tuple(1, -2, 3, -4);
	res = scalar_divide_tuple(t1, 2);
	free(t1);
	if (!res || res->x != 0.5f || res->y != -1 || res->z != 1.5f || res->w != -2)
		return (-1);
	free(res);

	return (0);
}

int	test_dot_product(void)
{
	t_tuple	*t1;
	t_tuple	*t2;
	double	res;

	t1 = create_vector(1, 2, 3);
	t2 = create_vector(2, 3, 4);
	res = dot_product(t1, t2);
	free(t1);
	free(t2);
	if (res != 20)
		return (-1);
	return (0);
}

int test_cross_product(void)
{
	t_tuple	*t1;
	t_tuple	*t2;
	t_tuple *res;

	t1 = create_vector(1, 2, 3);
	t2 = create_vector(2, 3, 4);
	res = cross_product(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != -1 || res->y != 2 || res->z != -1 || res->w != 0)
		return (-1);
	free(res);

	t1 = create_vector(1, 2, 3);
	t2 = create_vector(2, 3, 4);
	res = cross_product(t2, t1);
	free(t1);
	free(t2);
	if (!res || res->x != 1 || res->y != -2 || res->z != 1 || res->w != 0)
		return (-1);
	free(res);
	return (0);
}