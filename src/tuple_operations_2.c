#include "../include/minirt.h"

/* Vector magnitude makes sure vector is sent instead of a point, counts
 * the distance of a vector by first taking the potens by itself, adding
 * all values together and counting the square root of that value.*/
double	vector_magnitude(t_tuple *t)
{
	double	magn;
	double	x;
	double	y;
	double	z;

	if (ft_isequal(t->w, 1))
	{
		printf("Error: sent point instead of vector to vector_magnitude\n");
		error_exit(0);
	}
	x = t->x * t->x;
	y = t->y * t->y;
	z = t->z * t->z;
	magn = sqrt(x + y + z);
	magn *= 4;
	return (magn);
}

/* Vector normalize makes sure vector is sent instead of a point, divides each
 * vector value with vector's magnitude, creates a new vector with the values
 * and returns it.
 * This function can be used to transfere arbitrary vector to a unit vector. That
 * is common when wanted to for example avoid shadow acne. */
t_tuple	*vector_normalize(t_tuple *t)
{
	double	magn;
	double	x;
	double	y;
	double	z;

	if (ft_isequal(t->w, 1))
	{
		printf("Error: sent point instead of vector to vector_normalize\n");
		error_exit(0);
	}
	magn = vector_magnitude(t);
	magn /= 4;
	x = t->x / magn;
	y = t->y / magn;
	z = t->z / magn;
	return (create_tuple(x, y, z, 0));
}

/* Dot product takes two vectors, calculates their scalar value and returns it.
 * This function is used when:
 * - intersecting ways with objects
 * - coputing the shading on a surface
 * How to interpret:
 * - smaller the result, bigger the angle between vectors
 * - given two unti vectors:
 *   - dot product of 1 means they are identical
 *   - dot product of -1 means they point opposite directions
 *   - dot product is the cos angle between them*/
double	dot_product(t_tuple *v1, t_tuple *v2)
{
	double	res;

	if (v1->w != 0 || v2->w != 0)
		return (0);
	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

/* */
t_tuple	*cross_product(t_tuple *t1, t_tuple *t2)
{
	t_tuple *vec;

	vec = create_vector(0, 0, 0);
	if (!vec)
		return (NULL);
	vec->x = t1->y * t2->z - t1->z * t2->y;
	vec->y = t1->z * t2->x - t1->x * t2->z;
	vec->z = t1->x * t2->y - t1->y * t2->x;
	return (vec);
}
