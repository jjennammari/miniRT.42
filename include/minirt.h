#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc
# include <stdbool.h> // booleans
# include <unistd.h> // NULL
# include <math.h> // fabs, sqrt
/* cc math with -lm */
# include <mlx.h>
# include "libft.h"
# include "types.h"

# ifndef EPSILON
#  define EPSILON 0.00001
# endif

#define W 1200
#define H 600

#define ESC 65307

/* main.c */
t_tuple	*assign_tuple(char **av);

/* helper.c */
double	ft_atod(char *str);
bool	ft_isspace(char c);
bool	ft_isequal(double d1, double d2);
void	error_exit(int per);

/* tuple.c */
t_tuple	*create_tuple(double x, double y, double z, double w);
t_tuple *create_point(double x, double y, double z);
t_tuple *create_vector(double x, double y, double z);
void	print_tuple(t_tuple *tuple);
void	tick(t_environment *env, t_projectile *proj);

/* tuple_operations_1.c */
t_tuple	*sum_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*negate_tuple(t_tuple *v);
t_tuple	*scalar_multiply_tuple(t_tuple *tuple, double scalar);
t_tuple	*scalar_divide_tuple(t_tuple *tuple, double scalar);

/* tuple_operations_2.c */
double	vector_magnitude(t_tuple *v);
t_tuple	*vector_normalize(t_tuple *t);
double	dot_product(t_tuple *v1, t_tuple *v2);
t_tuple	*cross_product(t_tuple *t1, t_tuple *t2);
t_tuple	*hadamard_product(t_tuple *c1, t_tuple *c2);

/* test_jenna.c */
void	test_operations(int ac, char **av);
void	test_tick(char **av, t_rt *rt);

/* setup_rt.c */
t_rt	*init_rt(void);
int		close_rt(t_rt *rt);
int		key_press(int keysym, t_rt *rt);
int		loop(t_rt *rt);

/* canvas.c */
void	create_canvas(t_rt *rt);
void	pixel_to_canvas(t_data *dt, int x, int y, t_tuple *color);

/* draw.c */
void	set_projectile(t_rt *rt);

/* matrix.c */
double	**create_matrix(int size);
void	base_matrix(double **matrix, int size);

/* matrix_operations.c */
bool	is_equal_matrix(double **m1, double **m2, int size);
double	**multiply_matrix(double **m1, double **m2);

#endif // MINIRT_H
