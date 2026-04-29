#include "minirt.h"

t_tuple	*create_tuple(double x, double y, double z, double w);
t_tuple *create_point(double x, double y, double z);
t_tuple *create_vector(double x, double y, double z);
void	print_tuple(t_tuple *tuple);

t_tuple	*create_tuple(double x, double y, double z, double w)
{
	t_tuple	*new_tuple;

	new_tuple = malloc(sizeof(t_tuple));
	if (!new_tuple)
		error_exit(1);
	new_tuple->x = x;
	new_tuple->y = y;
	new_tuple->z = z;
	new_tuple->w = w;
	return (new_tuple);
}

t_tuple *create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, 1.0));
}

t_tuple *create_vector(double x, double y, double z)
{
	return (create_tuple(x, y, z, 0));
}

void	print_tuple(t_tuple *tuple)
{
	printf("x = %g\n", tuple->x);
	printf("y = %g\n", tuple->y);
	printf("z = %g\n", tuple->z);
	printf("w = %g\n", tuple->w);
	printf("\n");
}
