/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:52:42 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 23:08:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_fatal_error(void)
{
	ft_putendl_fd("a memory allocation error occured", 2);
	exit(1);
}

void	ft_print_commands(void)
{
	ft_putendl_fd("\nlist of available commands:\n\nMOUSE1:\t\tzoom in"\
			"\nMOUSE2:\t\tzoom out\n\n"\
			"LEFT_ARROW:\tdecrease iterations by 1\n"\
			"RIGHT_ARROW:\tincrease iterations by 1\n"\
			"UP_ARROW:\tincrease zoom speed by 1\n"\
			"DOWN_ARROW:\tdecrease zoom speed by 1\n\n"\
			"-:\t\tdecrease iterations by 100\n"\
			"+:\t\tincrease iterations by 100\n"\
			"=:\t\treset iterations to its initial state\n"\
			"I:\t\ttoggle/untoggle informations\n"\
			"R:\t\treset the fractal to its initial state\n"\
			"1/2/3 (KEYPAD):\tswitch color set\n"\
			"1/2/3/4/5:\tswitch spot\n"\
			"SPACE:\t\tkeep pressed to zoom in progressively\n"\
			"B:\t\tkeep pressed to zoom out progressively\n"\
			"F:\t\ttoggle/untoggle deformations\n"\
			"W-A-S-D :\tmove around", 2);
}

void	ft_print_man(void)
{
	ft_putendl_fd("\nlist of available fractals:\n\n-julia\n-mandelbrot\n-ship"\
"\n-tricorn\n-balloons\n-ship2\n\nusage:\n./fractol mandelbrot ship"\
"\n./fractol julia\n./fractol help", 2);
}

int		ft_error(int argc, char **argv, t_env *e, t_env *e2)
{
	if (argc == 2 && !ft_strcmp("help", argv[1]))
		return (2);
	if (argc != 2 && argc != 3)
	{
		ft_putendl_fd("wrong number of arguments", 2);
		return (1);
	}
	init_t_init(e);
	init_t_init(e2);
	if (init_fract(argv[1], e) == 1)
	{
		ft_putendl_fd("first argument name invalid", 2);
		return (1);
	}
	if (argc == 3)
	{
		if (init_fract(argv[2], e2) == 1)
		{
			ft_putendl_fd("second argument name invalid", 2);
			return (1);
		}
	}
	return (0);
}
