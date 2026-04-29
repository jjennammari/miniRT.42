#ifndef TYPES_H
# define TYPES_H

typedef struct	s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
	double	c;
}	t_tuple;

typedef struct	s_projectile
{
	t_tuple	*position;
	t_tuple	*velocity;
}	t_projectile;

typedef struct	s_environment
{
	t_tuple	*gravity;
	t_tuple	*wind;
}	t_environment;

#endif // TYPES_H
