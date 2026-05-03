#ifndef TYPES_H
# define TYPES_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		endian;
}	t_data;

typedef struct s_rt
{
	void		*mlx;
	void		*mlx_win;
	t_data		data;
}	t_rt;

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
