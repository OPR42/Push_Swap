/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_sx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:08:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 12:08:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_anim_sa_loop(t_char display[48][80], int frame, char *a, char *b)
{
	if (frame < 7)
	{
		ps_write_element(display, 14 - frame, 14, a);
		ps_write_element(display, 14 + frame, 15, b);
	}
	if (frame == 7)
	{
		ps_put_spaces(display, 4, 40, 14);
		ps_put_spaces(display, 4, 40, 15);
		ps_paint_zone_up(display, '6', '7', '6');
	}
	if (frame >= 7)
	{
		ps_write_element(display, 28 - frame, 14, b);
		ps_write_element(display, 0 + frame, 15, a);
	}
}

static void	ps_anim_sb_loop(t_char display[48][80], int frame, char *a, char *b)
{
	if (frame < 7)
	{
		ps_write_element(display, 53 + frame, 14, a);
		ps_write_element(display, 53 - frame, 15, b);
	}
	if (frame == 7)
	{
		ps_put_spaces(display, 41, 77, 14);
		ps_put_spaces(display, 41, 77, 15);
		ps_paint_zone_up(display, '7', '6', '6');
	}
	if (frame >= 7)
	{
		ps_write_element(display, 39 + frame, 14, b);
		ps_write_element(display, 67 - frame, 15, a);
	}
}

void	ps_anim_sa(t_char display[48][80])
{
	char	*first;
	char	*second;
	int		frame;

	first = ps_read_element(display, 14, 14);
	second = ps_read_element(display, 14, 15);
	ps_put_panel(display, PANELSA);
	frame = 0;
	while (frame < 14)
	{
		ps_anim_sa_loop(display, frame, first, second);
		ps_anim_sx_colors(display, 11, frame);
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(first);
	free(second);
}

void	ps_anim_sb(t_char display[48][80])
{
	char	*first;
	char	*second;
	int		frame;

	first = ps_read_element(display, 53, 14);
	second = ps_read_element(display, 53, 15);
	ps_put_panel(display, PANELSB);
	frame = 0;
	while (frame < 14)
	{
		ps_anim_sb_loop(display, frame, first, second);
		ps_anim_sx_colors(display, 12, frame);
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(first);
	free(second);
}

void	ps_anim_ss(t_char display[48][80])
{
	char	*firsta;
	char	*seconda;
	char	*firstb;
	char	*secondb;
	int		frame;

	firsta = ps_read_element(display, 14, 14);
	seconda = ps_read_element(display, 14, 15);
	firstb = ps_read_element(display, 53, 14);
	secondb = ps_read_element(display, 53, 15);
	ps_put_panel(display, PANELSS);
	frame = 0;
	while (frame < 14)
	{
		ps_anim_sa_loop(display, frame, firsta, seconda);
		ps_anim_sb_loop(display, frame, firstb, secondb);
		ps_anim_sx_colors(display, 13, frame);
		ps_print_canvas(display, '7', 0, 0);
		frame++;
	}
	free(firsta);
	free(seconda);
	free(firstb);
	free(secondb);
}
