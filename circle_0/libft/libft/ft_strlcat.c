/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:07:52 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:54:17 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates dst and src string.
 *		If dstsize is smaller than dst length, the return value
 *		is the sum of dstsize + src legth,
 *		else the return value is the sum of dst and src legnths.
 * 
 * @param dst Destiny string
 * @param src Source string
 * @param dstsize Size of destiny
 * @return size_t If dstsize is smaller than dst length, the return value
 *			is the sum of dstsize + src legth,
 *			else the return value is the sum of dst and src legnths.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = ft_strlen(dst);
	slen = ft_strlen(src);
	dlen = j;
	if (dstsize == 0 || dstsize <= dlen)
		return (slen + dstsize);
	while (src[i] != '\0' && i < dstsize - dlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
