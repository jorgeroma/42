/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:29:27 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/05 16:58:50 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/**
* @brief Recursive function to convert usigned decimal int to hexadecimal.
 * 			Used with modifier 'p'.
 * 
 * @param i	Decimal number.
 * @param counter Counter of characters printed by ft_printf.
 * @param capital	If 0 number will be printed in lowercase, else in uppercase.
 */
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

/**
 * @brief Recursive function to convert usigned decimal int to hexadecimal.
 * 			Used with modifiers 'x' and 'X'.
 * 
 * @param i	Decimal number.
 * @param counter Counter of characters printed by ft_printf.
 * @param capital	If 0 number will be printed in lowercase, else in uppercase.
 */
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

/**
 * @brief Represents numbers in hexadecimal for modifiers p, x and X.
 * 
 * @param ptr Pointer to the variable argument list.
 * @param counter	Counter of characters printed by ft_printf.
 * @param capital	If 0 number will be printed in lowercase, else in uppercase.
 * @param prefix	If greater than 0, will pring '0x' before the number.
 */
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

/**
 * @brief An extension of ft_match_case for the case of 's' specifically.
 * 
 * @param ptr	Pointer to variable argument list.
 * @param counter	Counter of characters printed by ft_printf.
 */
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

/**
 * @brief Checks if is necessary to represent an space whem there are
 * 			spaces between '%' and the conversion character.
 * 
 * @param str	Input string
 * @return int	Returns 1 if an space is necessary and 0 otherwise. 
 */
int	ft_check_space(char *str)
{
	while (*str == ' ')
		str++;
	return (*str == 'p' || *str == 'd' || *str == 'i');
}
