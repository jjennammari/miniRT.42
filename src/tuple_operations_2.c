#include "minirt.h"

double	dot_product(t_tuple *v1, t_tuple *v2)
{
	double	res;

	if (v1->w != 0 || v2->w != 0)
		return (0);
	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

t_tuple	*cross_product(t_tuple *t1, t_tuple *t2)
{
	t_tuple *vec;

	vec = new_vector(0, 0, 0);
	if (!vec)
		return (NULL);
	vec->x = t1->y * t2->z - t1->z * t2->y;
	vec->y = t1->z * t2->x - t1->x * t2->z;
	vec->z = t1->x * t2->y - t1->y * t2->x;
	return (vec);
}