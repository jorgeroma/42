/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:35:22 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 19:07:37 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Looks for the last appearance of character c in the first
 *			n elemts of s and returns a pointer to it.
 *			Returns null if is not found.
 * 
 * @param s String where it is going to look for c.
 * @param c Character it is going to look for.
 * @return char* Pointer to the last appearance of c.
 * 			NULL if c is not in s.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == c % 256)
			ret = (char *)s;
		s++;
	}
	if (c % 256 == 0)
		return ((char *)s);
	return (ret);
}
