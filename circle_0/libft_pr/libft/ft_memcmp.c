/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:58:19 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:16:02 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two arrays while the are equal.
 *			When a diffent element is found, the difference
 *			between them es returned.
 *			If the two arrays are equal, 0 is returned,
 *			1 if s1 is greater and -1 is s2 is greater.
 *
 * @param s1 Array one.
 * @param s2 Array two.
 * @param n Number of positions to compare.
 * @return int If the two arrays are equal, 0 is returned,
 *			1 if s1 is greater and -1 is s2 is greater.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		else
		{
			p1++;
			p2++;
		}
	}
	return (0);
}
