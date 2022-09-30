/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:29:27 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/29 19:57:44 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	count_params(const char *str)
{
	int	i;
	int	n_params;
	int	len;

	i = 0;
	n_params = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			if (ft_memchr("cspdiluxX%", str[i], 10))
				n_params++;
			i++;
		}
		else
			i++;
	}
	return (n_params);
}

static void ft_match_case(va_list *ptr, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*ptr, int),1);
	else if (c == 's')
		ft_putstr_fd(va_arg(*ptr, char *),1);
	else if (c == 'p')
		ft_putptr_fd(va_arg(*ptr, void *),1);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(*ptr, int),1);
	else if (c == 'i')
		ft_putstr_fd(va_arg(*ptr, char *),1);
	else if (c == 'l')
		ft_putstr_fd(va_arg(*ptr, char *),1);
	else if (c == 'u')
		ft_putstr_fd(va_arg(*ptr, char *),1);
	else if (c == 'x')
		ft_putstr_fd(va_arg(*ptr, char *),1);
	else if (c == 'X')
		ft_putstr_fd(va_arg(*ptr, char *),1);
	else if (c == '%')
		ft_putchar_fd('%',1);
	
	

}

static void	ft_match(va_list *ptr, char **str)
{
	(*str)++;
	while (**str && **str == ' ')
		(*str)++;
	if (ft_strchr("cspdiluxX%", **str))
	{
		ft_match_case(ptr, **str);
		(*str)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;

	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
			ft_match(&ptr, (char **)&str);
		else
		{
			ft_putchar_fd(*str, 1);	
			str++;
		}
	}
	va_end(ptr);
	return (count_params(str));	
}

