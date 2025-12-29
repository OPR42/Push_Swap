/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_benchview_helpers1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:37:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 19:04:52 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a_short(t_data *data, t_char display[48][80], unsigned int *y)
{
	while (*y <= 37)
	{
		ps_put_spaces(display, 15, 26, *y);
		if (data->count_nb_a >= *y - 13)
			ps_put_nbr_center7(display, data->stack_a_curr->value, 15, *y);
		data->stack_a_curr = data->stack_a_curr->next;
		(*y)++;
	}
}

static void	stack_a_long(t_data *data, t_char display[48][80], unsigned int *y)
{
	while (*y <= 23)
	{
		ps_put_spaces(display, 15, 26, *y);
		ps_put_nbr_center7(display, data->stack_a_curr->value, 15, *y);
		data->stack_a_curr = data->stack_a_curr->next;
		(*y)++;
	}
	ps_put_separator(display, 14, data->count_nb_a - 19);
	data->stack_a_curr = data->stack_a_hook->previous;
	*y = 37;
	while (*y >= 29)
	{
		ps_put_spaces(display, 15, 26, *y);
		ps_put_nbr_center7(display, data->stack_a_curr->value, 15, *y);
		data->stack_a_curr = data->stack_a_curr->previous;
		(*y)--;
	}
}

static void	stack_b_short(t_data *data, t_char display[48][80], unsigned int *y)
{
	while (*y <= 37)
	{
		ps_put_spaces(display, 54, 65, *y);
		if (data->count_nb_b >= *y - 13)
			ps_put_nbr_center7(display, data->stack_b_curr->value, 54, *y);
		data->stack_b_curr = data->stack_b_curr->next;
		(*y)++;
	}
}

static void	stack_b_long(t_data *data, t_char display[48][80], unsigned int *y)
{
	while (*y <= 23)
	{
		ps_put_spaces(display, 54, 65, *y);
		ps_put_nbr_center7(display, data->stack_b_curr->value, 54, *y);
		data->stack_b_curr = data->stack_b_curr->next;
		(*y)++;
	}
	ps_put_separator(display, 53, data->count_nb_b - 19);
	data->stack_b_curr = data->stack_b_hook->previous;
	*y = 37;
	while (*y >= 29)
	{
		ps_put_spaces(display, 54, 65, *y);
		ps_put_nbr_center7(display, data->stack_b_curr->value, 54, *y);
		data->stack_b_curr = data->stack_b_curr->previous;
		(*y)--;
	}
}

void	ps_put_stacks(t_data *data, t_char display[48][80])
{
	unsigned int	y;

	data->stack_a_curr = data->stack_a_hook->next;
	y = 14;
	if (data->count_nb_a <= 24)
		stack_a_short(data, display, &y);
	else
		stack_a_long(data, display, &y);
	data->stack_b_curr = data->stack_b_hook->next;
	y = 14;
	if (data->count_nb_b <= 24)
		stack_b_short(data, display, &y);
	else
		stack_b_long(data, display, &y);
}
