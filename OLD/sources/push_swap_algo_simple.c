/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_simple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:05:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/12 15:05:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	find_distance(t_data *data)
{
	unsigned int	i;
	int				min;
	unsigned int	distance;

	i = 0;
	min = INT_MAX;
	data->stack_a_curr = data->stack_a_hook->next;
	while (data->stack_a_curr != data->stack_a_hook)
	{
		if (data->stack_a_curr->value < min)
		{
			min = data->stack_a_curr->value;
			distance = i;
		}
		i++;
		data->stack_a_curr = data->stack_a_curr->next;
	}
	return (distance);
}

static void	stack_align(t_data *data)
{
	unsigned int	i;
	unsigned int	distance;

	distance = find_distance(data);
	if (distance > 0 && distance <= data->count_nb_a / 2)
	{
		i = 0;
		while (i < distance)
		{
			ps_exec(data, "ra");
			i++;
		}
	}
	else if (distance > 0)
	{
		distance = data->count_nb_a - distance;
		i = 0;
		while (i < distance)
		{
			ps_exec(data, "rra");
			i++;
		}
	}
}

static unsigned int	forward_loop(t_data *data, unsigned int i, unsigned int end)
{
	if (ps_stack_not_progressive(data->stack_a_hook) <= 1)
		return (i);
	while (i < end - 1)
	{
		if (ps_stack_not_progressive(data->stack_a_hook) <= 1)
			return (i);
		data->stack_a_curr = data->stack_a_hook->next->next;
		if (data->stack_a_hook->next->value > data->stack_a_curr->value)
			ps_exec(data, "sa");
		else
		{
			ps_exec(data, "ra");
			i++;
		}
	}
	return (i);
}

static unsigned int	backward_loop(t_data *data, unsigned int i)
{
	if (ps_stack_not_progressive(data->stack_a_hook) <= 1)
		return (i);
	while (i > 0)
	{
		if (ps_stack_not_progressive(data->stack_a_hook) <= 1)
			return (i);
		data->stack_a_curr = data->stack_a_hook->next->next;
		if (data->stack_a_hook->next->value > data->stack_a_curr->value)
			ps_exec(data, "sa");
		else
		{
			ps_exec(data, "rra");
			i--;
		}
	}
	return (i);
}

void	ps_algo_simple(t_data *data)
{
	unsigned int	end;
	unsigned int	i;

	end = data->count_nb_a - 1;
	i = 0;
	while (end > 0)
	{
		i = forward_loop(data, i, end);
		end--;
		i = backward_loop(data, i);
	}
	stack_align(data);
}
