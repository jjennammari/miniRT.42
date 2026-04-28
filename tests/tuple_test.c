#include "minirt.h"

int	tuple(void)
{
	t_tuple *t;
	t_tuple	*p;
	t_tuple	*v;

	t = new_tuple(4.3, -4.2, 3.1, 1);
	p = new_point(4.2, -4, 3);
	v = new_vector(4, -4, 3);

	if (t->x != 4.3f || t->y != -4.2f || t->z != 3.1f || t->w != 1)
		return (-1);
	if (p->x != 4.2f || p->y != -4 || p->z != 3 || p->w != 1)
		return (-1);
	if (v->x != 4 || v->y != -4 || v->z != 3 || v->w != 0)
		return (-1);
	return (0);
}