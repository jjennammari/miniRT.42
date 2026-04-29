#include "../include/minirt.h"

double	ft_atod(char *str);
bool	ft_isspace(char c);
bool	ft_isdigit(char c);
bool	ft_isequal(double d1, double d2);
void	error_exit(int per);

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
