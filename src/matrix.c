#include "../include/minirt.h"

double		**create_matrix(int size);
void		base_matrix(double **matrix, int size);
static void	free_rows(double **matrix, int i);
bool		is_equal_matrix(double **m1, double **m2, int size);

double	**create_matrix(int size)
{
	double	**matrix;
	double	*row;
	int		i;

	matrix = malloc(sizeof(double **) * size);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < size)
	{
		row = malloc(sizeof(double *) * size);
		if (!row)
		{
			free_rows(matrix, i + 1);
			free(matrix);
			return (NULL);
		}
		matrix[i] = row;
		i++;
	}
	base_matrix(matrix, size);
	return (matrix);
}

void	base_matrix(double **matrix, int size)
{
	int	j;
	int	i;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

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

static void	free_rows(double **matrix, int i)
{
	int	c;

	if (!matrix)
		return ;
	c = 0;
	while (c < i)
	{
		free(matrix[c]);
		c++;
	}
}