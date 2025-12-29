/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:13:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/09 16:13:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	send_nodes(t_data *data, int value)
{
	t_stack	*node;

	data->stack_a_curr = data->stack_a_hook;
	while (data->stack_a_curr->next)
	{
		data->stack_a_curr = data->stack_a_curr->next;
		if (data->stack_a_curr->value == value)
			return (-1);
	}
	node = (t_stack *)malloc(sizeof(*node));
	if (!node)
		return (-1);
	node->value = value;
	node->next = NULL;
	node->previous = data->stack_a_curr;
	data->stack_a_curr->next = node;
	data->stack_a_curr = data->stack_a_curr->next;
	data->count_nb += 1;
	data->count_nb_a += 1;
	return (0);
}

static int	parse_flags(t_data *data, char *arg, int algo)
{
	if (ps_strncmp(arg, "--adaptative", 12) == 0)
		data->algo_type = 0;
	else if (ps_strncmp(arg, "--simple", 8) == 0 && (algo == 0 || algo == 1))
		data->algo_type = 1;
	else if (ps_strncmp(arg, "--medium", 8) == 0 && (algo == 0 || algo == 2))
		data->algo_type = 2;
	else if (ps_strncmp(arg, "--complex", 9) == 0 && (algo == 0 || algo == 3))
		data->algo_type = 3;
	else if (ps_strncmp(arg, "--bench", 8) == 0 && data->bench_mode != 2)
		data->bench_mode = 1;
	else if (ps_strncmp(arg, "--benchview", 12) == 0 && data->bench_mode != 1)
		data->bench_mode = 2;
	else
		return (-1);
	return (0);
}

static int	parse_args(t_data *data, int argc, char **argv)
{
	data->i = 1;
	while (data->i < argc)
	{
		if (ps_isint(argv[data->i]) == 1)
		{
			if (send_nodes(data, (int)ps_atolli(argv[data->i])) == -1)
				return (-1);
		}
		else if (ps_strncmp(argv[data->i], "--", 2) == 0)
		{
			if (parse_flags(data, argv[data->i], data->algo_type) != 0)
				return (-1);
		}
		else
			return (-1);
		(data->i)++;
	}
	if (data->count_nb < 2)
		return (-1);
	data->stack_a_curr->next = data->stack_a_hook;
	data->stack_a_hook->previous = data->stack_a_curr;
	return (0);
}

static int	init_data(t_data *data)
{
	if (ps_init_stacks(data) == -1)
		return (-1);
	data->algo_type = 0;
	data->bench_mode = 0;
	data->count_nb = 0;
	data->count_nb_a = 0;
	data->count_nb_b = 0;
	data->count_ops = 0;
	data->count_sa = 0;
	data->count_sb = 0;
	data->count_ss = 0;
	data->count_pa = 0;
	data->count_pb = 0;
	data->count_ra = 0;
	data->count_rb = 0;
	data->count_rr = 0;
	data->count_rra = 0;
	data->count_rrb = 0;
	data->count_rrr = 0;
	data->max_progress = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	write(1, "\033[?25h", 6);
	if (argc == 1)
		return (0);
	if (init_data(&data) == -1 || parse_args(&data, argc, argv) == -1)
	{
		ps_stack_clear((t_stack *)data.stack_a_hook);
		ps_stack_clear((t_stack *)data.stack_b_hook);
		write(2, "Error\n", 6);
		return (-1);
	}
	ps_algochoice(&data);
	ps_stack_clear((t_stack *)data.stack_a_hook);
	ps_stack_clear((t_stack *)data.stack_b_hook);
	return (0);
}
