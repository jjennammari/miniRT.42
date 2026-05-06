/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42Porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:23:21 by jemustaj          #+#    #+#             */
/*   Updated: 2026/05/06 17:59:42 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

bool	is_equal_matrix(double **m1, double **m2, int size);
double	**multiply_matrix(double **m1, double **m2);

bool	is_equal_matrix(double **m1, double **m2, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (!ft_isequal(m1[i][j], m2[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

double	**multiply_matrix(double **m1, double **m2)
{
	double	**result;
	int		i;
	int		j;
	int		k;

	result = create_matrix(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			result[i][j] = 0;
			while (k < 4)
			{
				result[i][j] += m1[i][k] * m2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}
