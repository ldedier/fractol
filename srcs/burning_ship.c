/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:38:13 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 18:30:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_burning_ship(t_env *e)
{
	e->fract.x_min_init = -2.2;
	e->fract.x_max_init = 1.2;
	e->fract.y_min_init = -2.2;
	e->fract.y_max_init = 1.2;
	e->fract.smooth = 1;
	e->fract.iter_init = 200;
	e->fract.color = BURNING_COLOR;
	e->fract.pos[4] = -1.802289;
	e->fract.pos[5] = -1.707127;
	e->fract.pos[6] = -0.082436;
	e->fract.pos[7] = 0.012726;
	e->fract.pos[8] = -1.621628;
	e->fract.pos[9] = -1.621535;
	e->fract.pos[10] = 0.000880;
	e->fract.pos[11] = 0.000973;
	e->fract.pos[12] = -1.520539360;
	e->fract.pos[13] = -1.520538360;
	e->fract.pos[14] = 0.000454920;
	e->fract.pos[15] = 0.000455920;
	e->fract.pos[16] = -0.874084;
	e->fract.pos[17] = -0.874083;
	e->fract.pos[18] = -0.782494;
	e->fract.pos[19] = -0.782493;
}
