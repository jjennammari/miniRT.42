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

void	test_operations(int ac, char **av)
{
	t_tuple			*t1;
	t_tuple			*t2;
	t_tuple			*t3;
	double			val;
	
	t1 = assign_tuple(&av[1]);
	if (ac == 9)
		t2 = assign_tuple(&av[5]);
	t3 = vector_normalize(t1);
	print_tuple(t3);
	//val = vector_normalize(t1);
	//printf("%g\n", val);
}

void	test_tick(char **av)
{
	t_environment	*env;
	t_projectile	*proj;
	t_projectile	*new;

	proj->position = assign_tuple(&av[1]);
	proj->velocity = assign_tuple(&av[2]);
	env->gravity = assign_tuple(&av[3]);
	env->wind = assign_tuple(&av[4]);
	new = 
}
