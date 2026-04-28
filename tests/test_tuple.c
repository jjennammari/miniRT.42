#include "minirt.h"

int	test_new_tuple(void)
{
	t_tuple *t;

	t = new_tuple(4.3, -4.2, 3.1, 1);
	if (t->x != 4.3f || t->y != -4.2f || t->z != 3.1f || t->w != 1)
		return (-1);
	free(t);
	return (0);
}

int	test_new_point(void)
{
	t_tuple	*p;

	p = new_point(4.2, -4, 3);
	if (p->x != 4.2f || p->y != -4 || p->z != 3 || p->w != 1)
		return (-1);
	free(p);
	return (0);
}

int	test_new_vector(void)
{
	t_tuple	*v;

	v = new_vector(4, -4, 3);
	if (v->x != 4 || v->y != -4 || v->z != 3 || v->w != 0)
		return (-1);
	free(v);
	return (0);
}

int test_add_tuple(void)
{
	t_tuple	*t1;
	t_tuple	*t2;
	t_tuple *res;

	t1 = new_point(1, 2, 3);
	t2 = new_vector(1, 2, 3);
	res = add_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != 4 || res->z != 6 || res->w != 1)
		return (-1);
	free(res);
	
	t1 = new_vector(1, 2, 3);
	t2 = new_vector(1, 2, 3);
	res = add_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != 4 || res->z != 6 || res->w != 0)
		return (-1);
	free(res);
	
	t1 = new_point(1, 2, 3);
	t2 = new_point(1, 2, 3);
	res = add_tuple(t1, t2);
	free(t1);
	free(t2);
	if (res)
	{
		free(res);
		return (-1);
	}
	return (0);
}

int test_subtract_tuple(void)
{
	t_tuple	*t1;
	t_tuple	*t2;
	t_tuple *res;

	t1 = new_point(3, 1, 2);
	t2 = new_vector(1, 2, 3);
	res = subtract_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != -1 || res->z != -1 || res->w != 1)
		return (-1);
	free(res);
	
	t1 = new_vector(3, 1, 2);
	t2 = new_vector(1, 2, 3);
	res = subtract_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != -1 || res->z != -1 || res->w != 0)
		return (-1);
	free(res);

	t1 = new_vector(3, 1, 2);
	t2 = new_vector(1, 2, 3);
	res = subtract_tuple(t1, t2);
	free(t1);
	free(t2);
	if (!res || res->x != 2 || res->y != -1 || res->z != -1 || res->w != 0)
		return (-1);
	free(res);
	
	t1 = new_vector(3, 1, 2);
	t2 = new_point(1, 2, 3);
	res = subtract_tuple(t1, t2);
	free(t1);
	free(t2);
	if (res)
	{
		free(res);
		return (-1);
	}
	return (0);
}

int test_negate_tuple(void)
{
	t_tuple	*t1;
	t_tuple *res;

	t1 = new_tuple(1, 2, 3, 0);
	res = negate_tuple(t1);
	free(t1);
	if (!res || res->x != -1 || res->y != -2 || res->z != -3 || res->w != 0)
		return (-1);
	free(res);
	
	t1 = new_tuple(1, 2, 3, 5);
	res = negate_tuple(t1);
	free(t1);
	if (!res || res->x != -1 || res->y != -2 || res->z != -3 || res->w != -5)
		return (-1);
	free(res);

	t1 = new_tuple(1, -2, 3, -1);
	res = negate_tuple(t1);
	free(t1);
	if (!res || res->x != -1 || res->y != 2 || res->z != -3 || res->w != 1)
		return (-1);
	free(res);

	return (0);
}