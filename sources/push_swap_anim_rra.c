/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_rra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:20:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/16 12:20:58 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_anim_rra_longend(t_char d[48][80], int frame, int len)
{
	char	*upwards;

	if (frame >= 15 && frame < 14 + len)
	{
		upwards = ps_read_element(d, 14, frame);
		ps_put_spaces(d, 14, 27, frame);
		if (frame < 15 + len)
			ps_write_element(d, 14, frame - 1, upwards);
		free(upwards);
	}
}

void	ps_anim_rra_longloop(t_char display[48][80], int frame, int len)
{
	char	*upwards;

	if (display[26][14].c == '[' && display[26][26].c == ']')
	{
		if (frame > 14 && frame < 24)
		{
			upwards = ps_read_element(display, 14, frame);
			ps_put_spaces(display, 14, 27, frame);
			if (frame <= 23)
				ps_write_element(display, 14, frame - 1, upwards);
			free(upwards);
		}
		if (frame > 28 && frame < 38)
		{
			upwards = ps_read_element(display, 14, frame);
			ps_put_spaces(display, 14, 27, frame);
			if (frame >= 30)
				ps_write_element(display, 14, frame - 1, upwards);
			free(upwards);
		}
	}
	else
		ps_anim_ra_longend(display, frame, len);
}

void	ps_anim_rra_loop(t_char display[48][80], int frm, int l, char *last)
{
	int	x;

	if (frm < 13)
	{
		ps_write_element(display, frm - 11 - l, 13 + l, last);
		ps_anim_rx_colors(display, 31, frm - 12);
		x = 3;
		while (x <= 27)
			display[13 + l][x++].color = '6';
	}
	else if (frm >= 13 && frm < 13 + l)
	{
		ps_write_element(display, 2, 12 + l - frm, last);
		ps_put_spaces(display, 2, 13, 13 + l + frm);
	}
	else if (frm >= 13 + l && frm < 26 + l)
	{
		ps_write_element(display, 14 - frm, 14, last);
		ps_anim_rx_colors(display, 31, frm);
		x = 3;
		while (x <= 27 - frm)
			display[14][x++].color = '6';
	}
}

void	ps_anim_rra(t_char display[48][80])
{
	char	*last;
	int		frame;
	int		y;
	int		len;

	ps_put_panel(display, PANELRRA);
	len = 0;
	y = 14;
	while (y < 39)
		if (display[y++][20].c != ' ')
			len++;
	if (display[26][14].c == '[' && display[26][26].c == ']')
		len += 4;
	frame = 0;
	last = ps_read_element(display, 14, 13 + len);
	while (frame < 26 + len)
	{
		ps_anim_rra_loop(display, frame, len, last);
		//ps_anim_rra_longloop(display, frame, len);
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(last);
}
