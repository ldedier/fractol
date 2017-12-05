/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:38:55 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 18:30:35 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_tricorn(t_env *e)
{
	e->fract.x_min_init = -2.10;
	e->fract.x_max_init = 1.90;
	e->fract.y_min_init = -2;
	e->fract.y_max_init = 2;
	e->fract.iter_init = 200;
	e->fract.smooth = 1;
	e->fract.pos[4] = 0.634122847;
	e->fract.pos[5] = 0.653526638;
	e->fract.pos[6] = -1.187829509;
	e->fract.pos[7] = -1.168425718;
	e->fract.pos[8] = 0.654694354;
	e->fract.pos[9] = 0.654732252;
	e->fract.pos[10] = -1.216584190;
	e->fract.pos[11] = -1.216546292;
	e->fract.pos[12] = 0.538333211;
	e->fract.pos[13] = 0.548035107;
	e->fract.pos[14] = 1.074561638;
	e->fract.pos[15] = 1.084263534;
	e->fract.pos[16] = 0.750260033;
	e->fract.pos[17] = 0.751472770;
	e->fract.pos[18] = -1.301268482;
	e->fract.pos[19] = -1.300055745;
}
