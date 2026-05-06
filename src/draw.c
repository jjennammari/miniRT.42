#include "../include/minirt.h"

void	set_projectile(t_rt *rt);
static void	draw_block(t_rt *rt, int x, int y, int size, t_tuple *color);

void	set_projectile(t_rt *rt)
{
	t_projectile	proj;
	t_environment	env;
	t_tuple			*color;
	int				canvas_x;
	int				canvas_y;
	bool			at_end;

	color = hadamard_product(create_tuple(0.9, 0.3, 1.5, 2), create_tuple(1, 0.2, 0.4, 2));
	proj.position = create_point(0, 1, 0);
	proj.velocity = vector_normalize(create_vector(1, 1.8, 0));
	proj.velocity = scalar_multiply_tuple(proj.velocity, 11.25);
	env.gravity = create_vector(0, -0.1, 0);
	env.wind = create_vector(-0.01, 0, 0);
	at_end = false;
	while (!at_end)
	{
		canvas_x = (int)proj.position->x;
		canvas_y = H - (int)proj.position->y;
		draw_block(rt, canvas_x, canvas_y, 6, color);
		tick(&env, &proj);
		if (proj.position->y <= 1.0)
			at_end = true;
	}
	free(color);
}

static void	draw_block(t_rt *rt, int x, int y, int size, t_tuple *color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < size)
	{
		dx = 0;
		while (dx < size)
		{
			pixel_to_canvas(&rt->data, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}
