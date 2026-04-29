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

#include "minirt.h"

t_tuple	*assign_tuple(char **av);

int	main(int ac, char **av)
{
	t_tuple	*t1;
	t_tuple	*t2;
	t_tuple	*t3;
	double	val;

	t1 = NULL;
	t2 = NULL;
	t3 = NULL;
	val = 0;
	if (ac == 5 || ac == 9)
	{
		t1 = assign_tuple(&av[1]);
		if (ac == 9)
			t2 = assign_tuple(&av[5]);
		t3 = vector_normalize(t1);
		print_tuple(t3);
		//val = vector_normalize(t1);
		//printf("%g\n", val);
	}
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