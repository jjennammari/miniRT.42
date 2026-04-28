#include "minirt.h"

int	equal_floats(float f1, float f2)
{
	if (fabs(f1 - f2) < EPSILON)
		return (1);
	return (0);
}