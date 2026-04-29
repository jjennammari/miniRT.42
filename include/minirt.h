#ifndef MINIRT_H
# define MINIRT_H

# include "types.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

double	dot_product(t_tuple *v1, t_tuple *v2);
t_tuple	*cross_product(t_tuple *t1, t_tuple *t2);

int		equal_floats(float f1, float t2);

#endif // MINIRT_H
