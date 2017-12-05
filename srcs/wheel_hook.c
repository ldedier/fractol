/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:00:46 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 21:52:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wheel_hook_forward(int keycode, int x, int y, t_env *e)
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	if (keycode == 5)
	{
		e->fract.x_min = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0) *
	(x_min + (x / (double)e->image.width) *
	(x_max - x_min))) - ((x_max - x_min) / 2.2);
		e->fract.y_min = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0) *
	(y_min + (y / (double)e->image.width) *
	(y_max - y_min))) - ((x_max - x_min) / 2.2);
		e->fract.x_max = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0) *
	(x_min + (x / (double)e->image.width) *
	(x_max - x_min))) + ((x_max - x_min) / 2.2);
		e->fract.y_max = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0) *
	(y_min + (y / (double)e->image.width) *
	(y_max - y_min))) + ((x_max - x_min) / 2.2);
		process_fractol(e);
	}
}

void	wheel_hook_backward(int keycode, int x, int y, t_env *e)
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	if (keycode == 4)
	{
		e->fract.x_min = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0) *
	(x_max - (x / (double)e->image.width) *
	(x_max - x_min))) - ((x_max - x_min) / 1.8);
		e->fract.y_min = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0) *
	(y_max - (y / (double)e->image.width) *
	(y_max - y_min))) - ((x_max - x_min) / 1.8);
		e->fract.x_max = ((3 / 4.0) * ((x_min + x_max) / 2) + (1 / 4.0) *
	(x_max - (x / (double)e->image.width) *
	(x_max - x_min))) + ((x_max - x_min) / 1.8);
		e->fract.y_max = ((3 / 4.0) * ((y_min + y_max) / 2) + (1 / 4.0) *
	(y_max - (y / (double)e->image.width) *
	(y_max - y_min))) + ((x_max - x_min) / 1.8);
		process_fractol(e);
	}
}

void	key_hook_3(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		if (e->fract.speed <= 0.45)
		{
			e->fract.speed += 0.05;
		}
		put_speed(e);
		put_interface(e);
	}
	if (keycode == 125)
	{
		if (e->fract.speed >= 0.05)
		{
			e->fract.speed -= 0.05;
		}
		put_speed(e);
		put_interface(e);
	}
}
