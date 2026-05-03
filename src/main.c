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

int	main(int ac, char **av)
{
	t_rt	*rt;

	rt = init_rt();
	if (ac == 17)
		test_tick(av);
	else if (ac == 5 || ac == 9)
		test_operations(ac, av);
	else
		printf("Send arguments: x, y, z, and w\n");
	mlx_loop_hook(rt->mlx, loop, rt);
	mlx_loop(rt->mlx);
	return (0);
}
