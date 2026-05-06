/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:37:21 by lbuscaro          #+#    #+#             */
/*   Updated: 2026/05/03 20:37:33 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../minilibx-mac/mlx.h"

t_rt	*init_rt(void);
int		close_rt(t_rt *rt);
int		key_press(int keysym, t_rt *rt);
int		loop(t_rt *rt);

t_rt	*init_rt(void)
{
	t_rt	*rt;

	rt = ft_calloc(1, sizeof (t_rt));
	if (!rt)
		close_rt(rt);
	rt->mlx = NULL;
	rt->mlx_win = NULL;
	rt->mlx = mlx_init();
	if (!rt->mlx)
		close_rt(rt);
	rt->mlx_win = mlx_new_window(rt->mlx, W, H, "miniRT");
	if (!rt->mlx_win)
		close_rt(rt);
	mlx_hook(rt->mlx_win, 17, (1L << 17), close_rt, rt);
	mlx_hook(rt->mlx_win, 02, (1L << 0), key_press, rt);
	return (rt);
}

int	close_rt(t_rt *rt)
{
	if (rt->mlx_win)
		mlx_destroy_window(rt->mlx, rt->mlx_win);
/*	if (rt->mlx) this is commented cause mac minilibx handles it by itself
	{
		mlx_destroy_display(rt->mlx);
		free(rt->mlx);
	}*/
	if (rt)
		free(rt);
	exit (0);
}

int	key_press(int keysym, t_rt *rt)
{
	if (keysym == ESC)
		close_rt(rt);
	return (0);
}

int	loop(t_rt *rt)
{
	create_canvas(rt);
	usleep(1000);
	return (0);
}
