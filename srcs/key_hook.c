/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:56:33 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 23:07:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	teleport(int ind, t_env *e)
{
	e->fract.toggled = 0;
	e->fract.c_r = e->fract.c_r_init;
	e->fract.c_i = e->fract.c_i_init;
	e->fract.x_min = e->fract.pos[ind * 4];
	e->fract.x_max = e->fract.pos[ind * 4 + 1];
	e->fract.y_min = e->fract.pos[ind * 4 + 2];
	e->fract.y_max = e->fract.pos[ind * 4 + 3];
	process_fractol(e);
}

void	key_hook_1(int keycode, t_env *e)
{
	if (keycode >= 18 && keycode <= 23)
		teleport((keycode - (keycode / 23)) - 18, e);
	if (keycode == 26)
	{
		e->fract.color = SMOOTH_COLOR;
		e->fract.smooth = 1;
	}
	if (keycode == 28)
	{
		e->fract.color = BURNING_COLOR;
		e->fract.smooth = 1;
	}
	if (keycode == 25)
	{
		if (e->fract.iter_max <= 1900)
			e->fract.iter_max += 100;
		else
			e->fract.iter_max = 2000;
		process_fractol(e);
		put_iters(e);
	}
}

void	key_hook_2(int keycode, t_env *e)
{
	if (keycode == 15)
		init_fract_pos(e);
	if (keycode == 78)
	{
		if (e->fract.iter_max > 100)
			e->fract.iter_max -= 100;
		else
			e->fract.iter_max = 0;
		process_fractol(e);
		put_iters(e);
	}
	if (keycode == 3)
	{
		if (e->fract.toggled == 1)
		{
			e->fract.c_r = e->fract.x_min + (e->fract.x_mouse /
			(double)720) * (e->fract.x_max - e->fract.x_min);
			e->fract.c_i = e->fract.y_min + (e->fract.y_mouse
			/ (double)720) * (e->fract.y_max - e->fract.y_min);
			e->fract.toggled = 0;
		}
		else
			e->fract.toggled = 1;
		process_fractol(e);
	}
}

void	key_hook_3_1(int keycode, t_env *e)
{
	if (keycode == 34)
	{
		if (e->toggled_info)
			e->toggled_info = 0;
		else
			e->toggled_info = 1;
		process_fractol(e);
	}
	if (keycode == 81)
	{
		e->fract.iter_max = e->fract.iter_init;
		process_fractol(e);
		put_iters(e);
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	key_hook_1(keycode, e);
	key_hook_2(keycode, e);
	key_hook_3_1(keycode, e);
	if (keycode == 85)
	{
		e->fract.color = NEONS;
		e->fract.smooth = 0;
	}
	if ((keycode >= 83 && keycode <= 85) || keycode == 15)
		process_fractol(e);
	return (0);
}
