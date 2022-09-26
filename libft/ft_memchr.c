/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:48:12 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/23 15:23:44 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_memchr:
		Looks for the first appearance of c in the first
		n elemts of s and returns a pointer to it.
		Returns null if is not found.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	seek;

	seek = c;
	while (n--)
	{
		if ((unsigned char) *(char *)s == seek)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
