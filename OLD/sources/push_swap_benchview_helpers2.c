/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_benchview_helpers2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:49:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 19:48:56 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_put_char_xy7(char c, int x, int y, t_char display[48][80])
{
	display[y][x].color = '7';
	display[y][x].c = c;
}

void	ps_put_spaces(t_char display[48][80], int x, int x_end, int y)
{
	while (x <= x_end)
	{
		display[y][x].c = ' ';
		display[y][x].color = '7';
		x++;
	}
}

void	ps_put_nbr_center7(t_char display[48][80], int n, int x, int y)
{
	long	nb;
	int		len;
	int		i;

	nb = n;
	len = ps_intlen(n);
	if (nb == 0)
		ps_put_char_xy7('0', x + 5 - (len / 2), y, display);
	if (nb < 0)
	{
		ps_put_char_xy7('-', x + 5 - (len / 2), y, display);
		nb = -nb;
	}
	i = len - 1;
	while (nb > 0)
	{
		ps_put_char_xy7('0' + (nb % 10), x + 5 - (len / 2) + i, y, display);
		i--;
		nb /= 10;
	}
}

void	ps_put_separator(t_char display[48][80], int x, unsigned int count)
{
	int		i;
	int		x_curr;
	int		y_curr;

	i = 0;
	y_curr = 24;
	while (y_curr < 29)
	{
		x_curr = x;
		while (x_curr < x + 13)
		{
			display[y_curr][x_curr].c = SEPARATOR[i++];
			display[y_curr][x_curr].color = '3';
			x_curr++;
		}
		y_curr++;
	}
	ps_put_nbr_center7(display, count, x + 1, 26);
}

void	ps_put_progress(t_data *data, t_char display[48][80])
{
	int		done;
	int		mess;
	int		x;

	mess = ps_stack_not_progressive(data->stack_a_hook) - 1;
	done = (1000 * (data->initial_mess - mess)) / data->initial_mess;
	if (done > data->max_progress)
		data->max_progress = done;
	display[11][41].c = data->max_progress % 10 + '0';
	display[11][39].c = (data->max_progress / 10) % 10 + '0';
	display[11][38].c = (data->max_progress / 100) % 10 + '0';
	display[11][37].c = (data->max_progress / 1000) % 10 + '0';
	x = 28;
	while (x < 52)
	{
		if (data->max_progress / (1000 / 24) > x - 28)
			display[12][x].c = '#';
		else
			display[12][x].c = '-';
		x++;
	}
}
