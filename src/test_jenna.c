/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_jenna.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:05:16 by jemustaj          #+#    #+#             */
/*   Updated: 2026/04/29 17:06:11 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	test_operations(int ac, char **av);
void	test_tick(char **av, t_rt *rt);

void	test_operations(int ac, char **av)
{
	t_tuple			*t1;
	t_tuple			*t3;

	(void)ac;
	t1 = assign_tuple(&av[1]);
	t3 = vector_normalize(t1);
	print_tuple(t3);
	//val = vector_normalize(t1);
	//printf("%g\n", val);
}

void	test_tick(char **av, t_rt *rt)
{
	t_environment	env;
	t_projectile	proj;

	if (rt)
	{
		rt->proj->position = assign_tuple(&av[1]);
		rt->proj->velocity = vector_normalize(assign_tuple(&av[5]));
		rt->envi->gravity = assign_tuple(&av[9]);
		rt->envi->wind = assign_tuple(&av[13]);
	}
	proj.position = assign_tuple(&av[1]);
	print_tuple(proj.position);
	proj.velocity = vector_normalize(assign_tuple(&av[5]));
	print_tuple(proj.velocity);
	env.gravity = assign_tuple(&av[9]);
	print_tuple(env.gravity);
	env.wind = assign_tuple(&av[13]);
	print_tuple(env.wind);
	while (proj.position->y > 0)
		tick(&env, &proj);
	print_tuple(proj.position);
	print_tuple(proj.velocity);
}
