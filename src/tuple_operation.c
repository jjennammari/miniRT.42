#include "minirt.h"

t_tuple	*add_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple *tup;

	tup = malloc(sizeof(t_tuple));
	if (!tup)
		return (NULL);
	tup->w = t1->w + t2->w;
	if (tup->w != 1 && tup->w != 0)
	{
		free(tup);
		return (NULL);
	}
	tup->x = t1->x + t2->x;
	tup->y = t1->y + t2->y;
	tup->z = t1->z + t2->z;
	return (tup);
}

t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple *tup;

	tup = malloc(sizeof(t_tuple));
	if (!tup)
		return (NULL);
	tup->w = t1->w - t2->w;
	if (tup->w != 1 && tup->w != 0)
	{
		free(tup);
		return (NULL);
	}
	tup->x = t1->x - t2->x;
	tup->y = t1->y - t2->y;
	tup->z = t1->z - t2->z;
	return (tup);
}

t_tuple	*negate_tuple(t_tuple *t1)
{
	t_tuple *tup;

	tup = malloc(sizeof(t_tuple));
	if (!tup)
		return (NULL);
	tup->w = -t1->w;
	tup->x = -t1->x;
	tup->y = -t1->y;
	tup->z = -t1->z;
	return (tup);
}