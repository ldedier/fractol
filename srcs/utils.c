/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:59:20 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 21:46:49 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_speed(t_env *e)
{
	char		*str;
	char		*str2;
	void		*img;

	if (e->toggled_info == 0)
	{
		if (!(img = mlx_new_image(e->mlx, 177, 23)))
			put_fatal_error();
		mlx_put_image_to_window(e->mlx, e->win, img, 440, 20);
		mlx_destroy_image(e->mlx, img);
		str = ft_itoa((int)((((e->fract.speed) * 101 / 0.5))));
		str2 = ft_strjoin(str, "%");
		mlx_string_put(e->mlx, e->win, 450, 20,
		0x00FFaa00, "zoom speed:");
		mlx_string_put(e->mlx, e->win, 570, 20, 0x00FFaa00, str2);
		ft_strdel(&str);
		ft_strdel(&str2);
	}
}

void			put_iters(t_env *e)
{
	char		*str;
	void		*img;

	if (e->toggled_info == 0)
	{
		if (!(img = mlx_new_image(e->mlx, 177, 23)))
			put_fatal_error();
		mlx_put_image_to_window(e->mlx, e->win, img, 440, 20);
		mlx_destroy_image(e->mlx, img);
		mlx_string_put(e->mlx, e->win, 450, 20,
		0x00FFaa00, "iterations:");
		str = ft_itoa(e->fract.iter_max);
		mlx_string_put(e->mlx, e->win, 570, 20, 0x00FFaa00, str);
		ft_strdel(&str);
	}
}

void			process_fractol(t_env *e)
{
	mlx_put_fract_img_open_cl(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.ptr, 0, 0);
	put_interface(e);
	mlx_destroy_image(e->mlx, e->image.ptr);
}
