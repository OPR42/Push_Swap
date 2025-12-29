/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jr_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreibel <jreibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:23:11 by jreibel           #+#    #+#             */
/*   Updated: 2025/12/29 13:35:20 by jreibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jr_simple(t_data *data)
{
	if (data->initial_disorder == 0)
		ps_algo_none(data);
	else
	{
		data->algo_class = ps_strdup("Simple O(n²)");
		data->algo_name = ps_strdup("      Cocktail Shaker      ");
		
	}
}