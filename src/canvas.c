/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:37:52 by lbuscaro          #+#    #+#             */
/*   Updated: 2026/05/03 20:37:53 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void		create_canvas(t_rt *rt);
static int	extract_rgb(double r, double g, double b);
static void	pixel_to_canvas(t_data *dt, int x, int y, t_tuple *color);

void	create_canvas(t_rt *rt)
{
	t_data	*dt;
	t_tuple	*color;

	color = create_tuple(1, 1, 1, 2);
	dt = &rt->data;
	dt->img = mlx_new_image(rt->mlx, W, H);
	dt->addr = mlx_get_data_addr(dt->img, &dt->bpp, &dt->ln_len, &dt->endian);
	pixel_to_canvas(dt, 100, 100, color);
	free(color);
	mlx_put_image_to_window(rt->mlx, rt->mlx_win, dt->img, 0, 0);
	mlx_destroy_image(rt->mlx, dt->img);
}

static void	pixel_to_canvas(t_data *dt, int x, int y, t_tuple *color)
{
	char	*dst;
	int		rgb;

	if (!(x > 0 && y > 0 && x < W && y < H))
		return ;
	rgb = extract_rgb(color->x, color->y, color->z);
	dst = dt->addr + (y * dt->ln_len + x * (dt->bpp / 8));
	*(unsigned int *)dst = rgb;
}

static int	extract_rgb(double r, double g, double b)
{
	int	ir;
	int	ig;
	int	ib;

	if (r < 0.0)
		r = 0.0;
	else if (r > 1.0)
		r = 1.0;
	if (g < 0.0)
		g = 0.0;
	else if (g > 1.0)
		g = 1.0;
	if (b < 0.0)
		b = 0.0;
	else if (b > 1.0)
		b = 1.0;
	ir = (int)(r * 255 + 0.5);
	ig = (int)(g * 255 + 0.5);
	ib = (int)(b * 255 + 0.5);
	return (ir << 16 | ig << 8 | ib);
}
