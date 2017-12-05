/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:21:57 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/03 19:40:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_env	e;
	t_env	e2;
	int		ret;

	if ((ret = ft_error(argc, argv, &e, &e2)) == 1)
	{
		ft_print_man();
		return (1);
	}
	if (ret == 2)
	{
		ft_print_commands();
		return (0);
	}
	e.mlx = mlx_init();
	e2.mlx = e.mlx;
	init_env(&e, 1, argv);
	if (argc == 3)
		init_env(&e2, 2, argv);
	mlx_loop(e.mlx);
	return (0);
}
