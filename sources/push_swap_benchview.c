/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_benchview.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:41:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/14 19:41:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	build_largecanvas(t_char display[48][80])
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	while (y < 48)
	{
		x = 0;
		while (x < 80)
		{
			if (x < 79)
				display[y][x].c = BENCHVIEW[i++];
			display[y][x].color = COLORBENCHVIEW[j++];
			x++;
		}
		display[y][79].c = '\n';
		y++;
	}
}

static void	fill_largecanvas(t_data *data, t_char display[48][80])
{
	float	disorder;

	disorder = data->initial_disorder;
	ps_put_bench_nbr(data->count_nb, 36, 40, display);
	ps_put_bench_nbr((disorder * 10000) - 10000, 74, 40, display);
	ps_put_bench_nbr((disorder * 1000) - 1000, 73, 40, display);
	ps_put_bench_nbr((disorder * 100), 71, 40, display);
	ps_put_cyan_char_xy('.', 72, 40, display);
	ps_put_cyan_char_xy('%', 75, 40, display);
	ps_put_bench_nbr(data->count_ops, 36, 41, display);
	ps_put_algo(data->algo_type, 75, 41, display);
	ps_put_bench_nbr(data->count_sa, 17, 43, display);
	ps_put_bench_nbr(data->count_sb, 17, 44, display);
	ps_put_bench_nbr(data->count_ss, 17, 45, display);
	ps_put_bench_nbr(data->count_pa, 36, 43, display);
	ps_put_bench_nbr(data->count_pb, 36, 44, display);
	ps_put_bench_nbr(data->count_ra, 55, 43, display);
	ps_put_bench_nbr(data->count_rb, 55, 44, display);
	ps_put_bench_nbr(data->count_rr, 55, 45, display);
	ps_put_bench_nbr(data->count_rra, 75, 43, display);
	ps_put_bench_nbr(data->count_rrb, 75, 44, display);
	ps_put_bench_nbr(data->count_rrr, 75, 45, display);
	ps_put_stacks(data, display);
	ps_put_progress(data, display);
}

void	ps_print_canvas(t_char display[48][80], char color, int x, int y)
{
	char	c;

	write(1, "\033[H", 3);
	while (y < 48)
	{
		x = 0;
		while (x < 80)
		{
			c = display[y][x].c;
			if (color != display[y][x].color && c != ' ')
			{
				color = display[y][x].color;
				write(1, "\033[0;1;3", 7);
				write(1, &color, 1);
				write(1, "m", 1);
			}
			write(1, &c, 1);
			x++;
		}
		y++;
	}
	write(1, "\033[0m", 4);
	ps_wait(1);
}

static void	ps_put_debrief(t_char display[48][80], unsigned int count)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 16;
	while (y <= 32)
	{
		x = 28;
		while (x <= 51)
		{
			display[11][x].color = '2';
			display[12][x].color = '2';
			display[y][x++].c = SUCCESS[i++];
		}
		y++;
	}
	ps_put_nbr_center7(display, count, 35, 19);
	ps_paint_zone_up(display, '7', '7', '2');
}

void	ps_display_benchview(t_data *data, int step)
{
	t_char	display[48][80];

	if (step <= 10 || step >= 80)
	{
		build_largecanvas(display);
		fill_largecanvas(data, display);
	}
	else
		ps_anim_choose(display, step);
	if (step == 100)
		ps_put_debrief(display, data->count_ops);
	ps_print_canvas(display, '7', 0, 0);
}
