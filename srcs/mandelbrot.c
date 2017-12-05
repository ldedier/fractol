/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:35:43 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 18:29:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandelbrot(t_env *e)
{
	e->fract.x_min_init = -2;
	e->fract.x_max_init = 0.5;
	e->fract.y_min_init = -1.25;
	e->fract.y_max_init = 1.25;
	e->fract.smooth = 1;
	e->fract.iter_init = 200;
	e->fract.pos[4] = -0.167612;
	e->fract.pos[5] = -0.167195;
	e->fract.pos[6] = -1.041415;
	e->fract.pos[7] = -1.040998;
	e->fract.pos[8] = 0.350869;
	e->fract.pos[9] = 0.352149;
	e->fract.pos[10] = -0.061220;
	e->fract.pos[11] = -0.059940;
	e->fract.pos[12] = -1.743360;
	e->fract.pos[13] = -1.743319;
	e->fract.pos[14] = -0.000021;
	e->fract.pos[15] = 0.000020;
	e->fract.pos[16] = -1.74885288126825932942;
	e->fract.pos[17] = -1.74884324786156253317;
	e->fract.pos[18] = 0.00030535345730858229;
	e->fract.pos[19] = 0.00031498686400527283;
}
