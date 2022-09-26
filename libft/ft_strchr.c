/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:23:16 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/23 15:29:16 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_strchr:
		Looks for the first appearance of character c in the first
		n elemts of s and returns a pointer to it.
		Returns null if is not found.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c % 256)
			return ((char *)s);
		s++;
	}
	if (c % 256 == 0)
		return ((char *)s);
	return (NULL);
}
