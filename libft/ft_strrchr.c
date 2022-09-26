/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:35:22 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/23 15:38:32 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_strrchr
		Looks for the last appearance of character c in the first
		n elemts of s and returns a pointer to it.
		Returns null if is not found.
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
