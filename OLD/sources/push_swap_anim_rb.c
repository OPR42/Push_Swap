/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_rb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:37:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 21:37:58 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_anim_rb_longend(t_char d[48][80], int frame, int len)
{
	char	*upwards;

	if (frame >= 15 && frame < 14 + len)
	{
		upwards = ps_read_element(d, 53, frame);
		ps_put_spaces(d, 53, 67, frame);
		if (frame < 15 + len)
			ps_write_element(d, 53, frame - 1, upwards);
		free(upwards);
	}
}

void	ps_anim_rb_longloop(t_char display[48][80], int frame, int len)
{
	char	*upwards;

	if (display[26][53].c == '[' && display[26][65].c == ']')
	{
		if (frame > 14 && frame < 24)
		{
			upwards = ps_read_element(display, 53, frame);
			ps_put_spaces(display, 53, 67, frame);
			if (frame <= 23)
				ps_write_element(display, 53, frame - 1, upwards);
			free(upwards);
		}
		if (frame > 28 && frame < 38)
		{
			upwards = ps_read_element(display, 53, frame);
			ps_put_spaces(display, 53, 67, frame);
			if (frame >= 30)
				ps_write_element(display, 53, frame - 1, upwards);
			free(upwards);
		}
	}
	else
		ps_anim_rb_longend(display, frame, len);
}

void	ps_anim_rb_loop(t_char display[48][80], int frm, int l, char *frst)
{
	int	x;

	if (frm < 13)
	{
		ps_write_element(display, 53 + frm, 14, frst);
		ps_anim_rx_colors(display, 32, frm);
		x = 53;
		while (x <= 77)
			display[14][x++].color = '6';
	}
	else if (frm >= 13 && frm < 13 + l)
	{
		ps_write_element(display, 66, frm + 1, frst);
		ps_put_spaces(display, 66, 77, frm);
	}
	else if (frm >= 13 + l && frm < 26 + l)
	{
		ps_write_element(display, 78 + l - frm, 13 + l, frst);
		ps_anim_rx_colors(display, 32, frm - 12);
		x = 53;
		while (x <= 77)
			display[13 + l][x++].color = '6';
	}
}

void	ps_anim_rb(t_char display[48][80])
{
	char	*first;
	int		frame;
	int		y;
	int		len;

	first = ps_read_element(display, 53, 14);
	ps_put_panel(display, PANELRB);
	len = 0;
	y = 14;
	while (y < 39)
		if (display[y++][59].c != ' ')
			len++;
	if (display[26][53].c == '[' && display[26][65].c == ']')
		len += 4;
	frame = 0;
	while (frame < 26 + len)
	{
		ps_anim_rb_loop(display, frame, len, first);
		ps_anim_rb_longloop(display, frame, len);
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(first);
}
