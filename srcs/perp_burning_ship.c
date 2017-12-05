/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:40:37 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 18:30:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_perp_ship(t_env *e)
{
	e->fract.x_min_init = -2;
	e->fract.x_max_init = 1;
	e->fract.y_min_init = -1.5;
	e->fract.y_max_init = 1.5;
	e->fract.iter_init = 200;
	e->fract.smooth = 1;
	e->fract.color = SMOOTH_COLOR;
	e->fract.pos[4] = -1.772693041;
	e->fract.pos[5] = -1.772601488;
	e->fract.pos[6] = 0.004635891;
	e->fract.pos[7] = 0.004727444;
	e->fract.pos[8] = 0.231193108;
	e->fract.pos[9] = 0.237835713;
	e->fract.pos[10] = -0.563083886;
	e->fract.pos[11] = -0.556441281;
	e->fract.pos[12] = 0.358648210;
	e->fract.pos[13] = 0.362748583;
	e->fract.pos[14] = -0.360717991;
	e->fract.pos[15] = -0.356617618;
	e->fract.pos[16] = 0.411787689;
	e->fract.pos[17] = 0.412163538;
	e->fract.pos[18] = -0.301396522;
	e->fract.pos[19] = -0.301020673;
}
