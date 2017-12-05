/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:57:51 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 21:24:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			motion_hook(int x, int y, t_env *e)
{
	e->fract.x_mouse = x;
	e->fract.y_mouse = y;
	if (e->fract.toggled == 1)
		process_fractol(e);
	return (0);
}

void		zoom_in_action(int x, int y, t_env *e)
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	e->fract.x_min = x_min + (x / (double)e->image.width) *
	(x_max - x_min) - ((x_max - x_min) / 4);
	e->fract.y_min = y_min + (y / (double)e->image.height) *
	(y_max - y_min) - ((x_max - x_min) / 4);
	e->fract.x_max = x_min + (x / (double)e->image.width) *
	(x_max - x_min) + ((x_max - x_min) / 4);
	e->fract.y_max = y_min + (y / (double)e->image.height) *
	(y_max - y_min) + ((x_max - x_min) / 4);
}

void		zoom_out_action(int x, int y, t_env *e)
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	e->fract.x_min = x_max - (x / (double)e->image.width) *
	(x_max - x_min) - ((x_max - x_min));
	e->fract.y_min = y_max - (y / (double)e->image.height) *
	(y_max - y_min) - ((x_max - x_min));
	e->fract.x_max = x_max - (x / (double)e->image.width) *
	(x_max - x_min) + ((x_max - x_min));
	e->fract.y_max = y_max - (y / (double)e->image.height) *
	(y_max - y_min) + ((x_max - x_min));
}

int			mouse_event_funct(int keycode, int x, int y, t_env *e)
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	x_min = e->fract.x_min;
	x_max = e->fract.x_max;
	y_min = e->fract.y_min;
	y_max = e->fract.y_max;
	wheel_hook_forward(keycode, x, y, e);
	wheel_hook_backward(keycode, x, y, e);
	if (y > 1)
	{
		if ((keycode == 1) &&
		fabs(x_min - x_max) > 0.00000000000001)
			zoom_in_action(x, y, e);
		if (keycode == 2)
			zoom_out_action(x, y, e);
		process_fractol(e);
	}
	return (0);
}
