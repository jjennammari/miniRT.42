#include "minirt.h"

t_tuple *new_tuple(float x, float y, float z, float w)
{
	t_tuple *t;
	
	t = malloc(sizeof(t_tuple));
	if (!t)
		return (NULL);
	t->x = x;
	t->y = y;
	t->z = z;
	t->w = w;
	return (t);
}

t_tuple *new_point(float x, float y, float z)
{
	return (new_tuple(x, y, z, 1));
}

t_tuple *new_vector(float x, float y, float z)
{
	return (new_tuple(x, y, z, 0));
}