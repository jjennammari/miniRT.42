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
void	test_tick(char **av);

void	test_operations(int ac, char **av)
{
	t_tuple			*t1;
	t_tuple			*t2;
	t_tuple			*t3;

	t1 = assign_tuple(&av[1]);
	if (ac == 9)
		t2 = assign_tuple(&av[5]);
	t3 = create_tuple(t1->x, t1->y, t1->z, t1->w);
	print_tuple(t3);
	//val = vector_normalize(t1);
	//printf("%g\n", val);
}

void	test_tick(char **av)
{
	t_environment	env;
	t_projectile	proj;

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
