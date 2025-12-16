/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_px.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:46:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 18:52:14 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_anim_pa(t_char display[48][80])
{
	char	*first;
	int		frame;
	int		x;

	first = ps_read_element(display, 53, 14);
	ps_put_panel(display, PANELPA);
	frame = 0;
	while (frame < 39)
	{
		ps_write_element(display, 53 - frame, 14, first);
		ps_anim_pa_a_down(display, frame);
		ps_anim_pa_b_up(display, frame);
		ps_anim_px_colors(display, 21, frame);
		x = 53 - frame;
		while (x <= 67 - frame)
			display[14][x++].color = '6';
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(first);
}

void	ps_anim_pb(t_char display[48][80])
{
	char	*first;
	int		frame;
	int		x;

	first = ps_read_element(display, 14, 14);
	ps_put_panel(display, PANELPB);
	frame = 0;
	while (frame < 39)
	{
		ps_write_element(display, 14 + frame, 14, first);
		ps_anim_pb_a_up(display, frame);
		ps_anim_pb_b_down(display, frame);
		ps_anim_px_colors(display, 22, frame);
		x = 14 + frame;
		while (x <= 28 + frame)
			display[14][x++].color = '6';
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(first);
}

void	ps_anim_choose(t_char display[48][80], int step)
{
	if (step == 22)
		ps_anim_pb(display);
	/*if (step == 11)
		ps_anim_sa(display);
	else if (step == 12)
		ps_anim_sb(display);
	else if (step == 13)
		ps_anim_ss(display);
	else if (step == 21)
		ps_anim_pa(display);
	else if (step == 22)
		ps_anim_pb(display);
	else if (step == 31)
		ps_anim_ra(display);
	else if (step == 32)
		ps_anim_rb(display);
	else if (step == 33)
		ps_anim_rr(display);*/
	/*else if (step == 41)
		ps_anim_rra(display);
	else if (step == 42)
		ps_anim_rrb(display);
	else if (step == 43)
		ps_anim_rrr(display);*/
}
