#ifndef MINIRT_H
# define MINIRT_H

# include "types.h"
# include <stdlib.h>
# include <stdio.h>

t_tuple	*new_tuple(float x, float y, float z, float w);
t_tuple *new_point(float x, float y, float z);
t_tuple *new_vector(float x, float y, float z);

#endif // MINIRT_H
