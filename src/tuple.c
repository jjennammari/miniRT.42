#include "../include/minirt.h"

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

t_projectile	*tick(t_environment *env, t_projectile *proj)
{
	t_projectile	*new;

	if (ft_isequal(proj->position->w, 0))
	{
		printf("Error: position in tick should be a point");
		error_exit(0);
	}
	if (ft_isequal(proj->velocity->w, 1) || ft_isequal(env->gravity->w, 1) ||
		ft_isequal(env->wind->w, 1))
	{
		printf("Error: position in tick should be a point");
		error_exit(0);
	}
	new->position = sum_tuple(proj->position, proj->velocity);
	new->velocity = sum_tuple(proj->velocity, env->gravity);
	new->velocity = sum_tuple(new->velocity, env->wind);

	return (new);
}
