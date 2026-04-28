/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:08:15 by jemustaj          #+#    #+#             */
/*   Updated: 2026/04/28 16:25:06 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int ac, char **av);
t_tuple	*assign_tuple(char **av);
double	ft_atod(char *str);
bool	ft_isspace(char c);
bool	ft_isdigit(char c);
bool	ft_isequal(double d1, double d2);
void	error_exit(int per);

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

double	ft_atod(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		decimal = 0.1;
		while (str[i] && ft_isdigit(str[i]))
		{
			result += (str[i] - '0') * decimal;
			decimal *= 0.1;
			i++;
		}
	}
	return (result * sign);
}

bool	ft_isspace(char c)
{
	if ((c == ' ') || (c >= 8 && c <= 13))
		return (true);
	return (false);
}

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	ft_isequal(double d1, double d2)
{
	if (fabs(d1 - d2) < EPSILON)
		return (true);
	return (false);
}

void	error_exit(int per)
{
	if (per == 1)
	{
		perror("Error: ");
	}
	exit(1);
}
