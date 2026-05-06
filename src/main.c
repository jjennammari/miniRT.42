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

void	print_matrix(double **matrix, int size);
void	test_matrix();

int	main(int ac, char **av)
{
	t_rt	*rt;

	rt = init_rt();
	if (ac == 17)
		test_tick(av, NULL);
	else if (ac == 9)
		test_operations(ac, av);
	else
		printf("Send arguments: x, y, z, and w\n");
	test_matrix();
	mlx_loop_hook(rt->mlx, loop, rt);
	mlx_loop(rt->mlx);
	return (0);
}

void	test_matrix()
{
	double	**m1;
	double	**m2;
	
	m1 = create_matrix(3);
	m2 = create_matrix(3);
	m2[0][0] = 2;

	if (!is_equal_matrix(m1, m2, 3))
		printf("yey\n");
}

void	print_matrix(double **matrix, int size)
{
	int	j;
	int	i;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf(" %g ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}