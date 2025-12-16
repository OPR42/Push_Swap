/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bench_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:02:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/12 22:02:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ps_strdup(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*dest;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ps_put_algo(short algo_type, int x, int y, t_char display[19][80])
{
	int		len;
	int		i;
	char	*algo;

	if (algo_type == 1)
		algo = ps_strdup(ALGOSIMPLE);
	else if (algo_type == 2)
		algo = ps_strdup(ALGOMEDIUM);
	else if (algo_type == 3)
		algo = ps_strdup(ALGOCOMPLEX);
	else if (algo_type == 9)
		algo = ps_strdup(ALGONONE);
	len = ps_strlen(algo);
	i = 0;
	while (i < len)
	{
		display[y][x + 1 - len + i].color = '6';
		display[y][x + 1 - len + i].c = algo[i];
		i++;
	}
	free(algo);
}

void	ps_put_cyan_char_xy(char c, int x, int y, t_char display[19][80])
{
	display[y][x].color = '6';
	display[y][x].c = c;
}

void	ps_put_bench_nbr(int n, int x, int y, t_char display[19][80])
{
	long	nb;
	int		len;
	int		i;

	nb = n;
	len = ps_intlen(n) - 1;
	if (nb == 0)
		ps_put_cyan_char_xy('0', x, y, display);
	if (nb < 0)
	{
		ps_put_cyan_char_xy('-', x - len, y, display);
		nb = -nb;
	}
	i = len;
	while (nb > 0)
	{
		ps_put_cyan_char_xy('0' + (nb % 10), x - len + i, y, display);
		i--;
		nb /= 10;
	}
}
