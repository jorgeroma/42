/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:32:59 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:34 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the number of elements needed to represent
 * 			a number.
 * 
 * @param n Input number.
 * @return int Number of elements needed.
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

/**
 * @brief Recursive function that fills an array with
 * 			the corresponding digit on each position.
 * 
 * @param n Full number to fill the string with.
 * @param out String it is going to fill.
 * @param pos Specific position of out it is goin to fill.
 */
static void	ft_itoa_rec(int n, char *out, int pos)
{
	if (n > 9)
		ft_itoa_rec(n / 10, out, pos - 1);
	out[pos] = (n % 10) + 48;
}

/**
 * @brief Given an integer returns a string with the number.
 * 
 * @param n Input number.
 * @return char* Pointer to string containing the number.
 */
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
