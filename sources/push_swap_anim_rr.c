/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:01:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/16 00:01:58 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_len(t_char display[48][80], int col)
{
	int		y;
	int		len;

	len = 0;
	y = 14;
	while (y < 39)
		if (display[y++][col].c != ' ')
			len++;
	if (display[26][col - 6].c == '[' && display[26][col + 6].c == ']')
		len += 4;
	return (len);
}

static void	init_lens(t_char display[48][80], int *len_a, int *len_b)
{
	*len_a = find_len(display, 20);
	*len_b = find_len(display, 59);
}

static void	launch_rr(t_char display[48][80], int len)
{
	char	*first_a;
	char	*first_b;
	int		frame;
	int		len_a;
	int		len_b;

	first_a = ps_read_element(display, 14, 14);
	first_b = ps_read_element(display, 53, 14);
	init_lens (display, &len_a, &len_b);
	frame = 0;
	while (frame < 26 + len)
	{
		if (frame < 26 + len_a)
			ps_anim_ra_loop(display, frame, len_a, first_a);
		if (frame < 26 + len_b)
			ps_anim_rb_loop(display, frame, len_b, first_b);
		if (frame < 26 + len_a)
			ps_anim_ra_longloop(display, frame, len_a);
		if (frame < 26 + len_b)
			ps_anim_rb_longloop(display, frame, len_b);
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(first_a);
	free(first_b);
}

void	ps_anim_rr(t_char display[48][80])
{
	int	len;

	if (find_len(display, 20) >= find_len(display, 59))
		len = find_len(display, 20);
	else
		len = find_len(display, 59);
	ps_put_panel(display, PANELRR);
	launch_rr(display, len);
}
