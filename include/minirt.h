#ifndef MINIRT_H
# define MINIRT_H

# include "types.h"
# include <stdlib.h>
# include <stdio.h>

t_tuple	*new_tuple(float x, float y, float z, float w);
t_tuple *new_point(float x, float y, float z);
t_tuple *new_vector(float x, float y, float z);
t_tuple	*add_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*negate_tuple(t_tuple *t1);

#endif // MINIRT_H
