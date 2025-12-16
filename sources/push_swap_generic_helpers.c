/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_generic_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:43:07 by orobert           #+#    #+#             */
/*   Updated: 2025/12/09 20:43:10 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_intlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

long long	ps_atolli(const char *nptr)
{
	size_t				i;
	unsigned long long	n;
	int					sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if ('0' > nptr[i] || nptr[i] > '9')
			break ;
		n = (10 * n) + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}

int	ps_isint(const char *nptr)
{
	size_t			i;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if ('0' > nptr[i] || nptr[i] > '9')
			return (0);
		i++;
	}
	if (ps_atolli(nptr) > INT_MAX || ps_atolli(nptr) < INT_MIN)
		return (0);
	return (1);
}

size_t	ps_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ps_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
