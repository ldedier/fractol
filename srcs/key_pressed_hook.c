/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:00:51 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 19:03:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_pressed_hook_0(int keycode, t_env *e)
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	if (keycode == 49)
	{
		e->fract.x_min = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0)
	* (x_min + (e->fract.x_mouse / (double)e->image.width)
	* (x_max - x_min))) - ((x_max - x_min) / (2 + e->fract.speed));
		e->fract.y_min = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0)
	* (y_min + (e->fract.y_mouse / (double)e->image.width) *
	(y_max - y_min))) - ((x_max - x_min) / (2 + e->fract.speed));
		e->fract.x_max = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0) *
	(x_min + (e->fract.x_mouse / (double)e->image.width) *
	(x_max - x_min))) + ((x_max - x_min) / (2 + e->fract.speed));
		e->fract.y_max = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0) *
	(y_min + (e->fract.y_mouse / (double)e->image.width) *
	(y_max - y_min))) + ((x_max - x_min) / (2 + e->fract.speed));
		process_fractol(e);
	}
}

void	key_pressed_hook_1(int keycode, t_env *e)
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	if (keycode == 11)
	{
		e->fract.x_min = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0)
	* (x_max - (e->fract.x_mouse / (double)e->image.width)
	* (x_max - x_min))) - ((x_max - x_min) / (2 - e->fract.speed));
		e->fract.y_min = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0)
	* (y_max - (e->fract.y_mouse / (double)e->image.width) *
	(y_max - y_min))) - ((x_max - x_min) / (2 - e->fract.speed));
		e->fract.x_max = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0)
	* (x_max - (e->fract.x_mouse / (double)e->image.width) *
	(x_max - x_min))) + ((x_max - x_min) / (2 - e->fract.speed));
		e->fract.y_max = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0)
	* (y_max - (e->fract.y_mouse / (double)e->image.width) *
	(y_max - y_min))) + ((x_max - x_min) / (2 - e->fract.speed));
		process_fractol(e);
	}
}

void	key_pressed_hook_2(int keycode, t_env *e)
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	if (keycode == 0)
	{
		e->fract.x_min = x_min - ((x_max - x_min) / 25);
		e->fract.x_max = x_max - ((x_max - x_min) / 25);
		process_fractol(e);
	}
	if (keycode == 2)
	{
		e->fract.x_min = x_min + ((x_max - x_min) / 25);
		e->fract.x_max = x_max + ((x_max - x_min) / 25);
		process_fractol(e);
	}
}

void	key_pressed_hook_3(int keycode, t_env *e)
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	if (keycode == 1)
	{
		e->fract.y_min = y_min + ((x_max - x_min) / 25);
		e->fract.y_max = y_max + ((x_max - x_min) / 25);
		process_fractol(e);
	}
	if (keycode == 13)
	{
		e->fract.y_min = y_min - ((x_max - x_min) / 25);
		e->fract.y_max = y_max - ((x_max - x_min) / 25);
		process_fractol(e);
	}
}

int		key_pressed_hook(int keycode, t_env *e)
{
	key_pressed_hook_0(keycode, e);
	key_pressed_hook_1(keycode, e);
	key_pressed_hook_2(keycode, e);
	key_pressed_hook_3(keycode, e);
	key_hook_3(keycode, e);
	if (keycode == 124)
	{
		if (e->fract.iter_max < 2000)
		{
			e->fract.iter_max += 1;
			process_fractol(e);
			put_iters(e);
		}
	}
	if (keycode == 123)
	{
		if (e->fract.iter_max > 0)
		{
			e->fract.iter_max -= 1;
			process_fractol(e);
			put_iters(e);
		}
	}
	return (0);
}
