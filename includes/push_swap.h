/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:12:56 by orobert           #+#    #+#             */
/*   Updated: 2025/12/09 16:13:00 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define ALGONONE "None. The input was already sorted."
# define ALGOSIMPLE "Shaker (O(n^2))"
# define ALGOMEDIUM "medium (O(n sqrt n)"
# define ALGOCOMPLEX "complex (O(n log n))"

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	struct s_stack	*stack_a_hook;
	struct s_stack	*stack_b_hook;
	struct s_stack	*stack_a_curr;
	struct s_stack	*stack_b_curr;
	short			algo_type;
	short			bench_mode;
	int				count_nb;
	float			disorder;
	int				count_ops;
	int				count_sa;
	int				count_sb;
	int				count_ss;
	int				count_pa;
	int				count_pb;
	int				count_ra;
	int				count_rb;
	int				count_rr;
	int				count_rra;
	int				count_rrb;
	int				count_rrr;
}	t_data;

int		ps_atoi(const char *nptr);
int		ps_isnumber(const char *nptr);
size_t	ps_strlen(const char *s);
int		ps_strncmp(const char *s1, const char *s2, size_t n);
void	ps_stack_clear(t_stack *hook);
void	push_swap_algochoice(t_data *data);

#endif
