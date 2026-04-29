/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:16:15 by jemustaj          #+#    #+#             */
/*   Updated: 2026/04/29 12:18:10 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_tuple	*create_tuple(double x, double y, double z, double w);
t_tuple	*create_point(double x, double y, double z);
t_tuple	*create_vector(double x, double y, double z);
void	print_tuple(t_tuple *tuple);
void	tick(t_environment *env, t_projectile *proj);

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

t_tuple	*create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, 1.0));
}

t_tuple	*create_vector(double x, double y, double z)
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

void	tick(t_environment *env, t_projectile *proj)
{
	if (ft_isequal(proj->position->w, 0))
	{
		printf("Error: position in tick should be a point");
		error_exit(0);
	}
	if (ft_isequal(proj->velocity->w, 1) || ft_isequal(env->gravity->w, 1)
		|| ft_isequal(env->wind->w, 1))
	{
		printf("Error: position in tick should be a point");
		error_exit(0);
	}
	proj->position = sum_tuple(proj->position, proj->velocity);
	proj->velocity = sum_tuple(proj->velocity, env->gravity);
	proj->velocity = sum_tuple(proj->velocity, env->wind);
}
