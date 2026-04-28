#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>// printf
#include <stdlib.h>// malloc
#include <stdbool.h>// booleans
#include <unistd.h>// NULL
#include <math.h>// fabs, sqrt
/* cc math with -lm */

# ifndef EPSILON
#  define EPSILON 0.00001
# endif

typedef struct	s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

/* main.c */
int		main(int ac, char **av);
t_tuple	*assign_tuple(char **av);
double	ft_atod(char *str);
bool	ft_isspace(char c);
bool	ft_isdigit(char c);
bool	ft_isequal(double d1, double d2);
void	error_exit(int per);

/* tuple.c */
t_tuple	*create_tuple(double x, double y, double z, double w);
void	print_tuple(t_tuple *tuple);
t_tuple	*sum_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*scalar_multiply_tuple(t_tuple *tuple, double scalar);
t_tuple	*scalar_divide_tuple(t_tuple *tuple, double scalar);
double	vector_magnitude(t_tuple *v);
t_tuple	*vector_normalize(t_tuple *t);

#endif
