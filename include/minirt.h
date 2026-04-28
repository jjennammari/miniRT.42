#ifndef MINIRT_H
# define MINIRT_H

# include "types.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define EPSILON 0.00001

t_tuple	*new_tuple(float x, float y, float z, float w);
t_tuple *new_point(float x, float y, float z);
t_tuple *new_vector(float x, float y, float z);
t_tuple	*add_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*negate_tuple(t_tuple *t1);
t_tuple	*scalar_tuple(float scalar, t_tuple *t1);
t_tuple	*divide_tuple(float scalar, t_tuple *t1);

int		equal_floats(float f1, float t2);

#endif // MINIRT_H
