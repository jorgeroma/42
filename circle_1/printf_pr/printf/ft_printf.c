/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:29:27 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/03 21:14:52 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// static int	count_params(const char *str)
// {
// 	int	i;
// 	int	n_params;
// 	int	len;

// 	i = 0;
// 	n_params = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		if (str[i] == '%')
// 		{
// 			i++;
// 			while (str[i] && str[i] == ' ')
// 				i++;
// 			if (ft_memchr("cspdiluxX%", str[i], 10))
// 				n_params++;
// 			i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (n_params);
// }

int ft_int_length(int n)
{
	int	i;
	
	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
	
}

static void ft_match_case(va_list *ptr, char c, int *counter)
{
	char	*s;
	int		n;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(*ptr, int),1);
		(*counter)++;
	}
	else if (c == 's')
	{
		s = va_arg(*ptr, char *);
		ft_putstr_fd(s, 1);
		(*counter) += ft_strlen(s);
	}
	else if (c == 'p')
		ft_putptr_fd(va_arg(*ptr, void *),1, 0, 1);
	else if (c == 'd')
	{
		n = va_arg(*ptr, int);
		ft_putnbr_fd(n,1);
		(*counter) += ft_int_length(n);

	}
	else if (c == 'i')
	{
		n = va_arg(*ptr, int);
		ft_putnbr_fd(n,1);
		(*counter) += ft_int_length(n);

	}
	else if (c == 'u')
	{
		n = va_arg(*ptr, int);
		ft_putnbr_fd(n,1);
		(*counter) += ft_int_length(n);

	}
	else if (c == 'x')
		ft_putptr_fd(va_arg(*ptr, void *),1, 0, 0);
	else if (c == 'X')
		ft_putptr_fd(va_arg(*ptr, void *),1, 1, 0);
	else if (c == '%')
		ft_putchar_fd('%',1);
	
	

}

static void	ft_match(va_list *ptr, char **str, int *counter)
{
	(*str)++;
	if (**str == ' ')
	{
		write(1, " ", 1);
		(*counter)++;
	}
	while (**str && **str == ' ')
		(*str)++;
	if (ft_strchr("cspdiuxX%", **str))
	{
		ft_match_case(ptr, **str, counter);
		(*str)++;
	}
}

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

