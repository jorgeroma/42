/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:45:18 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 19:02:22 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares s1 and s2 until a different character is found.
 *			If they are equal 0 is returned,
 *			if s1 is greater 1 is returned and
 *			if s2 is greater -1 is returned.
 * 
 * @param s1 String one
 * @param s2 String two
 * @param n Number of elements to compare.
 * @return int If they are equal 0 is returned,
 *			if s1 is greater 1 is returned and
 *			if s2 is greater -1 is returned.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (n-- && (*p1 || *p2))
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
