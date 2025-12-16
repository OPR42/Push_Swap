/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_anim_helpers1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:24:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 19:46:02 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_paint_zone_up(t_char display[48][80], char ca, char cb, char cc)
{
	int	x;
	int	y;

	y = 14;
	while (y <= 32)
	{
		if (y <= 15)
		{
			x = 3;
			while (x <= 39)
				display[y][x++].color = ca;
			x = 41;
			while (x <= 77)
				display[y][x++].color = cb;
		}
		if (y >= 16)
		{
			x = 28;
			while (x <= 51)
				display[y][x++].color = cc;
		}
		y++;
	}
}

void	ps_paint_zone_down(t_char display[48][80], char ca, char cb)
{
	int	x;
	int	y;

	y = 29;
	x = 3;
	while (x <= 39)
		display[y][x++].color = ca;
	x = 41;
	while (x <= 77)
		display[y][x++].color = cb;
}

void	ps_put_panel(t_char display[48][80], char *panel)
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
			display[y][x++].c = panel[i++];
		y++;
	}
}

char	*ps_read_element(t_char display[48][80], int x, int y)
{
	int		i;
	char	*element;

	element = (char *)malloc(13 * sizeof(char));
	if (!element)
		return (0);
	i = 0;
	while (i < 12)
	{
		element[i] = display[y][x + i].c;
		i++;
	}
	element[i] = '\0';
	return (element);
}

void	ps_write_element(t_char display[48][80], int x, int y, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		display[y][x + i].c = str[i];
		i++;
	}
}
