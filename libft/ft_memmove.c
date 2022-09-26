/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:34:36 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/23 15:21:27 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_memmove:
		n elements from src are copied to dst,
		and a pointer to dst is returned.
		This function controls overlap.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = dst;
	s = (char *) src;
	if (d > s && (d || s))
	{
		i = len;
		while (i--)
		{
			d[i] = s[i];
		}
	}
	else if (d || s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
