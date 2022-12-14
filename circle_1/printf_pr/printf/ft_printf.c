/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:29:27 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/05 16:37:52 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/**
 * @brief Finds the number of characters necesary to represent a number.
 * 
 * @param n	Number.
 * @return int	Number of characters necesary to represent n.
 */
int	ft_int_length(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

/**
 * @brief Extension of ft_match_case.
 * 
 * @param ptr	Pointer to the variable argument list.
 * @param c	Conversion identifier character.
 * @param counter	Counter of characters printed by ft_printf.
 */
static void	ft_match_case_exted(va_list *ptr, char c, int *counter)
{
	long long int			n;
	unsigned long long int	un;

	if (c == 'd')
	{
		n = va_arg(*ptr, int);
		ft_putnbr_fd(n, 1);
		(*counter) += ft_int_length(n);
	}
	else if (c == 'i')
	{
		n = va_arg(*ptr, int);
		ft_putnbr_fd(n, 1);
		(*counter) += ft_int_length(n);
	}
	else if (c == 'u')
	{
		un = va_arg(*ptr, unsigned int);
		n = un;
		ft_putnbr_fd(n, 1);
		(*counter) += ft_int_length(n);
	}
}

/**
 * @brief Checks with character matchs with c and executes the corresponding
 * 			function.
 * 
 * @param ptr	Pointer to the variable argument list.
 * @param c	Conversion identifier character.
 * @param counter	Counter of characters printed by ft_printf.
 */
static void	ft_match_case(va_list *ptr, char c, int *counter)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(*ptr, int), 1);
		(*counter)++;
	}
	else if (c == 's')
		ft_match_case_s(ptr, counter);
	else if (c == 'p')
		ft_putptr_fd(va_arg(*ptr, void *), counter, 0, 1);
	else if (c == 'x')
		ft_putptr_fd(va_arg(*ptr, void *), counter, 0, 0);
	else if (c == 'X')
		ft_putptr_fd(va_arg(*ptr, void *), counter, 1, 0);
	else if (c == '%')
	{
		(*counter)++;
		ft_putchar_fd('%', 1);
	}
	else
		ft_match_case_exted(ptr, c, counter);
}

/**
 * @brief Writes an space if needed adn checks if the conversion parameter
 * 			recognized, if so checks wich one with ft_match_case.
 * 
 * @param ptr	Pointer to the variable argument list.
 * @param str	Pointer to the input string.
 * @param counter	Counter of characters printed by ft_printf.
 */
static void	ft_match(va_list *ptr, char **str, int *counter)
{
	(*str)++;
	if (**str == ' ')
	{
		if (ft_check_space(*str))
		{
			write(1, " ", 1);
			(*counter)++;
		}
	}
	while (**str && **str == ' ')
		(*str)++;
	if (ft_strchr("cspdiuxX%", **str))
	{
		ft_match_case(ptr, **str, counter);
		(*str)++;
	}
}

/**
 * @brief	Function similar to printf.
 * 
 * @param str Input text to write.
 * @param ...	Variable number of input parameters.
 * @return int	Number of characters represented.
 */
int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		counter;

	va_start(ptr, str);
	counter = 0;
	while (*str)
	{
		if (*str == '%')
			ft_match(&ptr, (char **)&str, &counter);
		else
		{
			ft_putchar_fd(*str, 1);
			counter++;
			str++;
		}
	}
	va_end(ptr);
	return (counter);
}
