/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_choice.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:13:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/10 02:13:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_wait(int interval)
{
	volatile unsigned long	i;

	i = 0;
	while (i < DELAY * interval)
		i++;
}

float	ps_compute_disorder(t_data *data)
{
	t_stack			*temp;
	unsigned int	mistakes;
	unsigned int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	data->stack_a_curr = data->stack_a_hook->next;
	while (data->stack_a_curr->next != data->stack_a_hook)
	{
		temp = data->stack_a_curr->next;
		while (temp != data->stack_a_hook)
		{
			total_pairs++;
			if (data->stack_a_curr->value > temp->value)
				mistakes++;
			temp = temp->next;
		}
		data->stack_a_curr = data->stack_a_curr->next;
	}
	return ((float)mistakes / (float)total_pairs);
}

static void	ps_choose_algo(t_data *data, float disorder)
{
	if (disorder == 0)
		data->algo_type = 9;
	else if (disorder > 0 && disorder < 0.2 && data->algo_type == 0)
		data->algo_type = 1;
	else if (disorder >= 0.2 && disorder < 0.5 && data->algo_type == 0)
		data->algo_type = 2;
	else if (disorder >= 0.5 && data->algo_type == 0)
		data->algo_type = 3;
}

void	ps_algochoice(t_data *data)
{
	data->initial_disorder = ps_compute_disorder(data);
	data->initial_mess = ps_stack_not_progressive(data->stack_a_hook);
	ps_choose_algo(data, data->initial_disorder);
	if (data->bench_mode == 2)
		write(1, "\033[2J\033[?25l", 10);
	if (data->algo_type == 1)
		ps_algo_simple(data);
	else if (data->algo_type == 2)
		ps_algo_simple(data);
	else if (data->algo_type == 3)
		ps_algo_complex(data);
	else if (data->algo_type == 9)
		ps_algo_simple(data);
	if (data->bench_mode == 1)
		ps_display_bench(data);
	else if (data->bench_mode == 2)
		ps_display_benchview(data, 100);
	write(1, "\033[?25h", 6);
}
