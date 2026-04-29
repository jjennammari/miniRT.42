/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:08:15 by jemustaj          #+#    #+#             */
/*   Updated: 2026/04/29 12:20:24 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_tuple	*assign_tuple(char **av);

int	main(int ac, char **av)
{
	t_projectile	*new;

	if (ac == 5 || ac == 9)
		test_operations(ac, av);
	else
		printf("Send arguments: x, y, z, and w\n");
	return (0);
}

t_tuple	*assign_tuple(char **av)
{
	double	x;
	double	y;
	double	z;
	double	w;
	int		i;

	i = 0;
	while (av[i] && i < 4)
	{
		x = ft_atod(av[i]);
		i++;
		y = ft_atod(av[i]);
		i++;
		z = ft_atod(av[i]);
		i++;
		w = ft_atod(av[i]);
		i++;
	}
	return (create_tuple(x, y, z, w));
}
