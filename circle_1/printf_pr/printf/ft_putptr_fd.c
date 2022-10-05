/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:29:27 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/05 15:34:30 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_base_change_p(unsigned long int i, int *counter, int capital)
{
	char			*base;
	unsigned int	len;

	if (capital)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 16;
	if (i >= len)
		ft_base_change_p(i / len, counter, capital);
	(*counter)++;
	write(1, &base[i % len], 1);
}

static void	ft_base_change_xx(unsigned int i, int *counter, int capital)
{
	char			*base;
	unsigned int	len;

	if (capital)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 16;
	if (i >= len)
		ft_base_change_xx(i / len, counter, capital);
	(*counter)++;
	write(1, &base[i % len], 1);
}

void	ft_putptr_fd(void *ptr, int *counter, int capital, int prefix)
{
	unsigned long int	pp;
	unsigned int		pxx;

	if (prefix)
	{
		pp = (long int) ptr;
		*counter += 2;
		write(1, "0x", 2);
		ft_base_change_p(pp, counter, capital);
	}
	else
	{
		pxx = (long int) ptr;
		ft_base_change_xx(pxx, counter, capital);
	}
}

void	ft_match_case_s(va_list *ptr, int *counter)
{
	char	*s;

	s = va_arg(*ptr, char *);
	if (s)
	{
		ft_putstr_fd(s, 1);
		(*counter) += ft_strlen(s);
	}
	else
	{
		write(1, "(null)", 6);
		(*counter) += 6;
	}
}

int	ft_check_space(char *str)
{
	while (*str == ' ')
		str++;
	return (*str == 'p' || *str == 'd' || *str == 'i');
}
