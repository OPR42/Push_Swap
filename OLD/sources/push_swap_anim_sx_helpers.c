/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_sx_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:29:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 18:49:25 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_anim_sx_colors(t_char display[48][80], short op, int frame)
{
	if (op == 11 && (frame < 1 || frame > 12))
		ps_paint_zone_up(display, '6', '7', '0');
	else if (op == 11 && (frame < 3 || frame > 10))
		ps_paint_zone_up(display, '6', '7', '4');
	else if (op == 11)
		ps_paint_zone_up(display, '6', '7', '6');
	else if (op == 12 && (frame < 1 || frame > 12))
		ps_paint_zone_up(display, '7', '6', '0');
	else if (op == 12 && (frame < 3 || frame > 10))
		ps_paint_zone_up(display, '7', '6', '4');
	else if (op == 12)
		ps_paint_zone_up(display, '7', '6', '6');
	else if (op == 13 && (frame < 1 || frame > 12))
		ps_paint_zone_up(display, '6', '6', '0');
	else if (op == 13 && (frame < 3 || frame > 10))
		ps_paint_zone_up(display, '6', '6', '4');
	else if (op == 13)
		ps_paint_zone_up(display, '6', '6', '6');
}
