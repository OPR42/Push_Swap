/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chainlist_helpers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:13:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/10 00:13:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_stack_not_progressive(t_stack *hook)
{
	t_stack	*current;
	int		misplaced;

	misplaced = 0;
	current = hook->next;
	while (current != hook)
	{
		if (current->next == hook)
		{
			if (current->value > current->next->next->value)
				misplaced++;
		}
		else
		{
			if (current->value > current->next->value)
				misplaced++;
		}
		current = current->next;
	}
	return (misplaced);
}

void	ps_stack_clear(t_stack *hook)
{
	t_stack	*current;
	t_stack	*next;

	current = hook;
	if (current->previous)
	{
		current->previous->next = NULL;
		current->previous = NULL;
	}
	while (current)
	{
		next = current->next;
		if (current->previous)
		{
			current->previous->next = NULL;
			current->previous = NULL;
		}
		free(current);
		current = next;
	}
	hook = NULL;
}

int	ps_init_stacks(t_data *data)
{
	data->stack_a_hook = (t_stack *)malloc(sizeof(*data->stack_a_hook));
	if (!data->stack_a_hook)
		return (-1);
	data->stack_a_hook->next = NULL;
	data->stack_b_hook = (t_stack *)malloc(sizeof(*data->stack_b_hook));
	if (!data->stack_b_hook)
		return (-1);
	data->stack_b_hook->next = data->stack_b_hook;
	data->stack_b_hook->previous = data->stack_b_hook;
	return (0);
}
