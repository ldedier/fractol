/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:45:45 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 21:46:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image			ft_new_image(int width, int height)
{
	t_image		image;

	image.width = width;
	image.height = height;
	return (image);
}

void			put_iter_inter(t_env *e, int color)
{
	char *str;

	str = ft_itoa(e->fract.iter_max);
	mlx_string_put(e->mlx, e->win, 25, 20,
	color, "number of iterations:");
	mlx_string_put(e->mlx, e->win, 240, 20, color, str);
	ft_strdel(&str);
}

void			put_interface(t_env *e)
{
	char		*str;
	char		*str2;
	int			color;
	void		*img;
	int			nbr;

	color = 0x00ffaa00;
	nbr = (int)((((e->fract.speed) * 101 / 0.5)));
	if (e->toggled_info)
	{
		if (!(img = mlx_new_image(e->mlx, 265, 45)))
			put_fatal_error();
		mlx_put_image_to_window(e->mlx, e->win, img, 20, 20);
		mlx_destroy_image(e->mlx, img);
		put_iter_inter(e, color);
		str = ft_itoa(nbr);
		str2 = ft_strjoin(str, "%");
		mlx_string_put(e->mlx, e->win, 25, 40,
		color, "zoom speed:");
		mlx_string_put(e->mlx, e->win, 140, 40, color, str2);
		ft_strdel(&str);
		ft_strdel(&str2);
	}
}
