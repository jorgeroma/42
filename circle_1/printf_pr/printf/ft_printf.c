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

int	ft_printf(const char *str, ...)
{
	int		params;
	int		counter;
	va_list	ptr;

	params = count_params(str);
	counter = 0;
	va_start(ptr, str);
	while (str)
	{
		if (str == '%')
		{
			// str += 2;
			ft_putnbr_fd(va_arg(ptr, int),1);
			write(1,"\n",1);
			counter++;
		}else
		{
			ft_putchar_fd(str, 1);
		}
		str++;
	}
	va_end(ptr);
	// printf("%s\n", str);
	return (count_params(str));	
}

