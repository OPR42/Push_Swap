/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algochoice.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:13:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/10 02:13:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_disorder(t_data *data)
{
	t_stack	*temp;
	float	mistakes;
	float	total_pairs;

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
			printf("(test %.0f) %d vs %d\n", total_pairs, data->stack_a_curr->value, temp->value);
			temp = temp->next;
		}
		data->stack_a_curr = data->stack_a_curr->next;
	}
	data->disorder = mistakes / total_pairs;
	printf("%.0f pairs tested, %.0f mistakes. Disorder is %.2f\n", total_pairs, mistakes, data->disorder);
}

void	push_swap_algochoice(t_data *data)
{
	compute_disorder(data);
	if (data->disorder == 0)
		return ;
	else if (data->disorder < 0.2 && data->algo_type == 0)
		data->algo_type = 1;
	else if (data->disorder < 0.5 && data->algo_type == 0)
		data->algo_type = 2;
	else if (data->algo_type == 0)
		data->algo_type = 3;


	printf("\nalgo  : %d\nbench : %d\n", data->algo_type, data->bench_mode);
	int i = 0;
	printf("\n(pos %02d) Start from stack A hook\n\n", i);
	data->stack_a_curr = data->stack_a_hook;
	while (data->stack_a_curr->next != data->stack_a_hook)
	{
		data->stack_a_curr = data->stack_a_curr->next;
		i++;
		printf("(pos %02d) %d\n", i, data->stack_a_curr->value);
	}
	printf("\nFound %02d items in stack A.\nStopped before hitting hook's back.\nNow let's reverse!\n\n", data->count_nb);
	while (data->stack_a_curr != data->stack_a_hook)
	{
		printf("(pos %02d) %d\n", i, data->stack_a_curr->value);
		i--;
		data->stack_a_curr = data->stack_a_curr->previous;
	}
	printf("\n(pos %02d) Back to stack A hook\n\n", i);

}
