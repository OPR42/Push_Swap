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

/*void	ps_lstadd_back(t_stack *lst, t_stack *new)
{
	t_stack	*last;

	if (!&lst || !new)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	last = ft_lstlast(lst);
	new->previous = last;
	last->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}


void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}

_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}*/
