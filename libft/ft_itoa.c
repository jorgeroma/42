/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:32:59 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/27 19:29:37 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_itoa:
		Given an integer returns a string with the number.
*/

static int	ft_itoa_len(int n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		l++;
		n *= -1;
	}
	while (n > 9)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static void	ft_itoa_rec(int n, char *out, int pos)
{
	if (n > 9)
		ft_itoa_rec(n / 10, out, pos - 1);
	out[pos] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	int		pos;
	int		len;
	char	*out;

	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	pos = 0;
	len = ft_itoa_len(n);
	out = ft_calloc(len + 1, sizeof(char));
	if (out == NULL)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		pos++;
		n *= -1;
	}
	ft_itoa_rec(n, out, len - 1);
	out[len] = '\0';
	return (out);
}
