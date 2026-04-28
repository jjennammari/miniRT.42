#include "minirt.h"

t_tuple	*create_tuple(double x, double y, double z, double w);
void	print_tuple(t_tuple *tuple);
t_tuple	*sum_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*scalar_multiply_tuple(t_tuple *tuple, double scalar);
t_tuple	*scalar_divide_tuple(t_tuple *tuple, double scalar);
double	vector_magnitude(t_tuple *v);
t_tuple	*vector_normalize(t_tuple *t);

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

void	print_tuple(t_tuple *tuple)
{
	printf("x = %g\n", tuple->x);
	printf("y = %g\n", tuple->y);
	printf("z = %g\n", tuple->z);
	printf("w = %g\n", tuple->w);
	printf("\n");
}

t_tuple	*sum_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*new_tuple;
	double	sum_x;
	double	sum_y;
	double	sum_z;
	double	sum_w;

	sum_x = t1->x + t2->x;
	sum_y = t1->y + t2->y;
	sum_z = t1->z + t2->z;
	sum_w = t1->w + t2->w;
	new_tuple = create_tuple(sum_x, sum_y, sum_z, sum_w);
	return (new_tuple);
}

t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*new_tuple;
	double	dif_x;
	double	dif_y;
	double	dif_z;
	double	dif_w;

	dif_x = t1->x - t2->x;
	dif_y = t1->y - t2->y;
	dif_z = t1->z - t2->z;
	dif_w = t1->w - t2->w;
	new_tuple = create_tuple(dif_x, dif_y, dif_z, dif_w);
	return (new_tuple);
}

t_tuple	*scalar_multiply_tuple(t_tuple *tuple, double scalar)
{
	t_tuple	*new_tuple;
	double	mult_x;
	double	mult_y;
	double	mult_z;
	double	mult_w;

	mult_x = tuple->x * scalar;
	mult_y = tuple->y * scalar;
	mult_z = tuple->z * scalar;
	mult_w = tuple->w * scalar;
	new_tuple = create_tuple(mult_x, mult_y, mult_z, mult_w);
	return (new_tuple);
}

t_tuple	*scalar_divide_tuple(t_tuple *tuple, double scalar)
{
	t_tuple	*new_tuple;
	double	div_x;
	double	div_y;
	double	div_z;
	double	div_w;

	if (fabs(scalar) < EPSILON)
		error_exit(1);
	div_x = tuple->x / scalar;
	div_y = tuple->y / scalar;
	div_z = tuple->z / scalar;
	div_w = tuple->w / scalar;
	new_tuple = create_tuple(div_x, div_y, div_z, div_w);
	return (new_tuple);
}

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

t_tuple	*vector_normalize(t_tuple *t)
{
	double	magn;
	double	x;
	double	y;
	double	z;
	double	w;

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
	w = t->w / magn;
	return (create_tuple(x, y, z, w));
}
