/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:43:38 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 21:43:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_init	ft_init(char *str, void f(t_env*))
{
	t_init res;

	res.name = str;
	res.func = f;
	return (res);
}

void	init_t_init(t_env *e)
{
	e->tab_init[0] = ft_init("julia", &ft_init_julia);
	e->tab_init[1] = ft_init("mandelbrot", &ft_init_mandelbrot);
	e->tab_init[2] = ft_init("ship", &ft_init_burning_ship);
	e->tab_init[3] = ft_init("tricorn", &ft_init_tricorn);
	e->tab_init[4] = ft_init("ship2", &ft_init_perp_ship);
	e->tab_init[5] = ft_init("balloons", &ft_init_balloons);
}

void	init_fract_pos(t_env *e)
{
	e->fract.x_min = e->fract.x_min_init;
	e->fract.x_max = e->fract.x_max_init;
	e->fract.y_min = e->fract.y_min_init;
	e->fract.y_max = e->fract.y_max_init;
	e->fract.pos[0] = e->fract.x_min_init;
	e->fract.pos[1] = e->fract.x_max_init;
	e->fract.pos[2] = e->fract.y_min_init;
	e->fract.pos[3] = e->fract.y_max_init;
}

int		init_fract(char *str, t_env *e)
{
	int i;

	i = 0;
	while (i < NB_FRACTALS)
	{
		if (ft_strcmp(str, e->tab_init[i].name) == 0)
		{
			e->fract.speed = 0.1;
			e->fract.color = SMOOTH_COLOR;
			e->fract.c_r_init = -0.763519;
			e->fract.c_i_init = -0.091852;
			e->tab_init[i].func(e);
			e->fract.iter_max = e->fract.iter_init;
			e->fract.id = i;
			e->fract.toggled = 0;
			e->fract.c_r = e->fract.c_r_init;
			e->fract.c_i = e->fract.c_i_init;
			e->fract.x_mouse = WIN_WIDTH / 2;
			e->fract.y_mouse = WIN_HEIGHT / 2;
			init_fract_pos(e);
			return (0);
		}
		i++;
	}
	return (1);
}

void	init_env(t_env *e, int i, char **argv)
{
	e->toggled_info = 0;
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, argv[i]);
	e->image = ft_new_image(WIN_WIDTH, WIN_HEIGHT);
	mlx_hook(e->win, MOTIONNOTIFY, BUTTONMOTIONMASK, &motion_hook, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, &key_pressed_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_event_funct, e);
	process_fractol(e);
}
