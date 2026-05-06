/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:08:15 by jemustaj          #+#    #+#             */
/*   Updated: 2026/05/06 18:01:29 by jemustaj         ###   ########.fr       */
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
	double	**m3;
	
	m1 = create_matrix(4);
	m2 = create_matrix(4);
	m2[0][0] = 4;
	m1[0][1] = 3;
	m2[1][1] = 5;
	m3 = multiply_matrix(m1, m2);

	print_matrix(m3, 4);
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
