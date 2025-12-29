/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_px_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:45:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 19:07:03 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_anim_pa_a_down(t_char display[48][80], int frame)
{
	char	*downwards;

	if (display[26][14].c == '[' && display[26][26].c == ']')
	{
		if (frame > 14 && frame < 24)
		{
			downwards = ps_read_element(display, 14, 37 - frame);
			ps_put_spaces(display, 14, 28, 37 - frame);
			if (frame >= 15)
				ps_write_element(display, 14, 38 - frame, downwards);
			free(downwards);
		}
	}
	else
	{
		if (frame > 1 && frame < 24)
		{
			downwards = ps_read_element(display, 14, 37 - frame);
			ps_put_spaces(display, 14, 28, 37 - frame);
			if (frame >= 1)
				ps_write_element(display, 14, 38 - frame, downwards);
			free(downwards);
		}
	}
}

void	ps_anim_pa_b_up(t_char display[48][80], int frame)
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
	}
	else
	{
		if (frame > 14 && frame < 38)
		{
			upwards = ps_read_element(display, 53, frame);
			ps_put_spaces(display, 53, 67, frame);
			if (frame <= 37)
				ps_write_element(display, 53, frame - 1, upwards);
			free(upwards);
		}
	}
}

void	ps_anim_pb_a_up(t_char display[48][80], int frame)
{
	char	*upwards;

	if (display[26][14].c == '[' && display[26][26].c == ']')
	{
		if (frame > 16 && frame < 24)
		{
			upwards = ps_read_element(display, 14, frame);
			ps_put_spaces(display, 14, 28, frame);
			if (frame <= 23)
				ps_write_element(display, 14, frame - 1, upwards);
			free(upwards);
		}
	}
	else
	{
		if (frame > 14 && frame < 38)
		{
			upwards = ps_read_element(display, 14, frame);
			ps_put_spaces(display, 14, 28, frame);
			if (frame <= 37)
				ps_write_element(display, 14, frame - 1, upwards);
			free(upwards);
		}
	}
}

void	ps_anim_pb_b_down(t_char display[48][80], int frame)
{
	char	*downwards;

	if (display[26][53].c == '[' && display[26][65].c == ']')
	{
		if (frame > 16 && frame < 24)
		{
			downwards = ps_read_element(display, 53, 37 - frame);
			ps_put_spaces(display, 53, 67, 37 - frame);
			if (frame >= 15)
				ps_write_element(display, 53, 38 - frame, downwards);
			free(downwards);
		}
	}
	else
	{
		if (frame > 1 && frame < 24)
		{
			downwards = ps_read_element(display, 53, 37 - frame);
			ps_put_spaces(display, 53, 67, 37 - frame);
			if (frame >= 1)
				ps_write_element(display, 53, 38 - frame, downwards);
			free(downwards);
		}
	}
}

void	ps_anim_px_colors(t_char display[48][80], short op, int frame)
{
	if (op == 21 && (frame < 1 || frame > 37))
		ps_paint_zone_up(display, '7', '7', '0');
	else if (op == 21 && (frame < 3 || frame > 35))
		ps_paint_zone_up(display, '7', '7', '4');
	else if (op == 21)
		ps_paint_zone_up(display, '7', '7', '6');
	else if (op == 22 && (frame < 1 || frame > 37))
		ps_paint_zone_up(display, '7', '7', '0');
	else if (op == 22 && (frame < 3 || frame > 35))
		ps_paint_zone_up(display, '7', '7', '4');
	else if (op == 22)
		ps_paint_zone_up(display, '7', '7', '6');
}
