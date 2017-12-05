/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:36:41 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 18:29:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_env *e)
{
	e->fract.x_min_init = -1.55;
	e->fract.x_max_init = 1.55;
	e->fract.y_min_init = -1.55;
	e->fract.y_max_init = 1.55;
	e->fract.smooth = 1;
	e->fract.iter_init = 200;
	e->fract.pos[4] = -1.507782;
	e->fract.pos[5] = -1.494790;
	e->fract.pos[6] = -0.052760;
	e->fract.pos[7] = -0.039768;
	e->fract.pos[8] = 0.242575;
	e->fract.pos[9] = 0.450446;
	e->fract.pos[10] = -0.203467;
	e->fract.pos[11] = 0.004405;
	e->fract.pos[12] = -0.303606;
	e->fract.pos[13] = -0.272317;
	e->fract.pos[14] = -0.552811;
	e->fract.pos[15] = -0.521523;
	e->fract.pos[16] = 0.577969;
	e->fract.pos[17] = 0.622003;
	e->fract.pos[18] = 0.163099;
	e->fract.pos[19] = 0.207134;
}
