/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_rx_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:29:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 18:59:21 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_anim_rx_colors(t_char display[48][80], short op, int frame)
{
	if (op == 31 && (frame < 1 || frame > 37))
		ps_paint_zone_up(display, '7', '7', '0');
	else if (op == 31 && (frame < 3 || frame > 35))
		ps_paint_zone_up(display, '7', '7', '4');
	else if (op == 31)
		ps_paint_zone_up(display, '7', '7', '6');
	else if (op == 32 && (frame < 1 || frame > 37))
		ps_paint_zone_up(display, '7', '7', '0');
	else if (op == 32 && (frame < 3 || frame > 35))
		ps_paint_zone_up(display, '7', '7', '4');
	else if (op == 32)
		ps_paint_zone_up(display, '7', '7', '6');
	else if (op == 33 && (frame < 1 || frame > 37))
		ps_paint_zone_up(display, '7', '7', '0');
	else if (op == 33 && (frame < 3 || frame > 35))
		ps_paint_zone_up(display, '7', '7', '4');
	else if (op == 33)
		ps_paint_zone_up(display, '7', '7', '6');
}
