/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:48:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/08/11 11:48:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		fractol_julia(t_fract fract, int i)
{
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 720;
	y = i / 720;
	
	x_fig = fract.x_min + (x / (double)720) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)720) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)720) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)720) * (fract.y_max - fract.y_min);
		cr = x_fig_m;
		ci = y_fig_m;
	}
	else
	{	
		cr = fract.c_r;
		ci = fract.c_i;
	}
	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (2 * zr_tmp * zi) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		return 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		return (r << 16) | g << 8 | b;
	}
}

int		fractol_mandelbrot(t_fract fract, int i)
{
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 720;
	y = i / 720;
	
	x_fig = fract.x_min + (x / (double)720) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)720) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)720) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)720) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}
	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (2 * zr_tmp * zi) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		return 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		return (r << 16) | g << 8 | b;
	}
}

int		fractol_burning_ship(t_fract fract, int i)
{
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 720;
	y = i / 720;

	x_fig = fract.x_min + (x / (double)720) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)720) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)720) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)720) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}

	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (2 * fabs(zr_tmp) * fabs(zi)) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		return 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		return (r << 16) | g << 8 | b;
	}
}

int		fractol_tricorn(t_fract fract, int i)
{
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 720;
	y = i / 720;

	x_fig = fract.x_min + (x / (double)720) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)720) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	nb_iter = 0;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)720) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)720) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = zr_tmp * (-2 * zi) + ci;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		return 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}
		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		return (r << 16) | g << 8 | b;
	}
}

int		fractol_perp_bs(t_fract fract, int i)
{
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;

	x = i % 720;
	y = i / 720;

	x_fig = fract.x_min + (x / (double)720) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)720) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)720) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)720) * (fract.y_max - fract.y_min);
		zr = x_fig_m;
		zi = y_fig_m;
	}
	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		zr = (zr * zr - zi * zi) + cr;
		zi = (-2 * zr_tmp * fabs(zi)) + ci;

		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		return 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}

		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		return (r << 16) | g << 8 | b;
	}
}

int		fractol_balloons(t_fract fract, int i)
{
	double zr;
	double zi;
	double cr;
	double ci;
	double nb_iter;
	double x_fig;
	double y_fig;
	double x_fig_m;
	double y_fig_m;
	double nu;
	int x;
	int y;
	double zr_tmp;
	int r;
	int g;
	int b;
	double divisor;

	x = i % 720;
	y = i / 720;

	x_fig = fract.x_min + (x / (double)720) * (fract.x_max - fract.x_min);
	y_fig = fract.y_min + (y / (double)720) * (fract.y_max - fract.y_min);
	zr = x_fig;
	zi = y_fig;
	cr = x_fig;
	ci = y_fig;
	
	if (fract.toggled)
	{
		x_fig_m = fract.x_min + (fract.x_mouse / (double)720) * (fract.x_max - fract.x_min);
		y_fig_m = fract.y_min + (fract.y_mouse / (double)720) * (fract.y_max - fract.y_min);
		cr = x_fig_m;
		ci = y_fig_m;
	}
	
	else
	{
		cr = fract.c_r;
		ci = fract.c_i;
	}

	nb_iter = 0;
	while (zr * zr + zi * zi < 4 && nb_iter < fract.iter_max)
	{
		zr_tmp = zr;
		divisor = ((zr * zr) * ((zr * zr) + 2 * (zi * zi) + 2 * cr)) + ((zi * zi) * ((zi * zi) - (2 * cr))) + (4 * (zr * zi * ci) + (ci * ci) + (cr * cr));
		zr = ((zr * zr) - (zi * zi) + cr) / divisor;
		zi = - (2 * zr_tmp * zi + ci) / divisor;
		nb_iter++;
	}
	if (zr * zr + zi * zi < 4)
		return 0;
	else
	{
		if (fract.smooth == 1)
			nu = (nb_iter + 1 - (log(log(sqrt(zr *zr + zi * zi)))) / log(2.0));
		else
			nu = (nb_iter + 1 - (log(2.0) / (log(zr *zr + zi * zi))) / log(2.0));
		
		if (fract.color == 1)
		{
			r = sin(0.064 * nu + 1.9) * 127.5 + 127.5;
			g = sin(0.064 * nu + 1.3) * 127.5 + 127.5;
			b = sin(0.064 * nu + .8) * 127.5 + 127.5;
		}

		if (fract.color == 2)
		{
			r = sin(0.34 * nu + 1) * 126 + 129;
			g = sin(0.34 * nu + 2) * 126 + 129;
			b = sin(0.034 * 2) * 127 + 128;
		}
		if (fract.color == 4)
		{	
			r = sin(-2.04 * nu + 0.2) * 127.5 + 127.5;
			g = sin(4.4 * nu + 0.2) * 127.5 + 127.5;
			b = sin(-10.04 * nu + 0.2) * 127.5 + 127.5;
		}
		return (r << 16) | g << 8 | b;
	}
}

void	ft_render_fract(t_env *e, int (*func)(t_fract, int))
{
	int i;
	i = 0;
	while (i < e->image.width * e->image.height)
	{
		e->image.data[i] = func(e->fract, i);
		i++;
	}
}


void	ft_render(t_env *e)
{
	if (e->fract.id == 1)
		ft_render_fract(e, fractol_mandelbrot);
	else if (e->fract.id == 2)
		ft_render_fract(e, fractol_burning_ship);
	else if (e->fract.id == 3)
		ft_render_fract(e, fractol_tricorn);
	else if (e->fract.id == 4)
		ft_render_fract(e, fractol_perp_bs);
	else if (e->fract.id == 5)
		ft_render_fract(e, fractol_balloons);
	else
		ft_render_fract(e, fractol_julia);
}


void	mlx_put_fract_img(t_env *e)
{
	if (!(e->image.ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT)))
		put_fatal_error();
	e->image.data = (int *)mlx_get_data_addr(e->image.ptr, 
	&(e->image.bbp), &(e->image.line_size), &(e->image.endian));
	ft_render(e);
}
