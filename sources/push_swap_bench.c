/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bench.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:02:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/12 22:02:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	build_canvas(t_char display[19][80])
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	while (y < 19)
	{
		x = 0;
		while (x < 80)
		{
			if (x < 79)
				display[y][x].c = BENCH[i++];
			display[y][x].color = COLORBENCH[j++];
			x++;
		}
		display[y][79].c = '\n';
		y++;
	}
}

static void	fill_canvas(t_data *data, t_char display[19][80])
{
	float	disorder;

	disorder = data->initial_disorder;
	ps_put_bench_nbr(data->count_nb, 36, 11, display);
	ps_put_bench_nbr((disorder * 10000) - 10000, 74, 11, display);
	ps_put_bench_nbr((disorder * 1000) - 1000, 73, 11, display);
	ps_put_bench_nbr((disorder * 100), 71, 11, display);
	ps_put_cyan_char_xy('.', 72, 11, display);
	ps_put_cyan_char_xy('%', 75, 11, display);
	ps_put_bench_nbr(data->count_ops, 36, 12, display);
	ps_put_algo(data->algo_type, 75, 12, display);
	ps_put_bench_nbr(data->count_sa, 17, 14, display);
	ps_put_bench_nbr(data->count_sb, 17, 15, display);
	ps_put_bench_nbr(data->count_ss, 17, 16, display);
	ps_put_bench_nbr(data->count_pa, 36, 14, display);
	ps_put_bench_nbr(data->count_pb, 36, 15, display);
	ps_put_bench_nbr(data->count_ra, 55, 14, display);
	ps_put_bench_nbr(data->count_rb, 55, 15, display);
	ps_put_bench_nbr(data->count_rr, 55, 16, display);
	ps_put_bench_nbr(data->count_rra, 75, 14, display);
	ps_put_bench_nbr(data->count_rrb, 75, 15, display);
	ps_put_bench_nbr(data->count_rrr, 75, 16, display);
}

static void	print_canvas(t_char display[19][80], char color)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < 19)
	{
		x = 0;
		while (x < 80)
		{
			c = display[y][x].c;
			if (color != display[y][x].color && c != ' ')
			{
				color = display[y][x].color;
				write(2, "\033[0;1;3", 7);
				write(2, &color, 1);
				write(2, "m", 1);
			}
			write(2, &c, 1);
			x++;
		}
		y++;
	}
	write(2, "\033[0m", 4);
}

void	ps_display_bench(t_data *data)
{
	t_char	display[19][80];

	build_canvas(display);
	fill_canvas(data, display);
	print_canvas(display, '7');
}
