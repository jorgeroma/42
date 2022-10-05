/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:29:27 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/05 14:41:56 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_base_change(long long int i, int *counter, int capital)
{
	char	*base;
	int		len;

	if (capital)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 16;
	if (i >= len)
		ft_base_change(i / len, counter, capital);
	(*counter)++;
	write(1, &base[i % len], 1);
}

void	ft_putptr_fd(void *ptr, int *counter, int capital, int prefix)
{
	long long int	p;

	p = (long long int) ptr;
	if (prefix)
	{
		*counter += 2;
		write(1, "0x", 2);
	}
	ft_base_change(p, counter, capital);
}
