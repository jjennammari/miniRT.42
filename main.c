#include "minirt.h"

double	ft_atod(char *str);
bool	ft_isspace(char c);
bool	ft_isdigit(char c);
bool	ft_isequal(double d1, double d2);
void	error_exit(void);

int	main(int ac, char **av)
{
	t_tuple	*point;
	t_tuple	*vector;
	t_tuple	*new;
	int		count;

	point = NULL;
	vector = NULL;
	if (ac > 1)
	{
		//TODO: parse inputs before atod
		count = 1;
		while (count < ac)
		{
			double x = ft_atod(av[count]);
			count++;
			double y = ft_atod(av[count]);
			count++;
			double z = ft_atod(av[count]);
			count++;
			double w = ft_atod(av[count]);
			count++;
			if (ft_isequal(w, 1.0))
			{
				point[i] = create_tuple(x, y, z, w);
				printf("point\n");
				print_tuple(point);
				i++;
			}
			else
			{
				vector[j] = create_tuple(x, y, z, w);
				printf("vector\n");
				print_tuple(vector);
				j++;
			}
		}
		new = sum_tuple(vector, point);
		print_tuple(new);
	}
	else
		printf("Send arguments: x, y, z, and w\n");
	return (0);
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

void	error_exit(void)
{
	perror("Error: ");
	exit(1);
}
