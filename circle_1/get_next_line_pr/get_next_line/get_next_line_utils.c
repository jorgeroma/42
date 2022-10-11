/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:01:38 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/11 17:54:06 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr)
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
	return (NULL);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	cat = (char *)ft_calloc((len + 1), sizeof(char));
	if (!cat)
		return (NULL);
	ft_strlcat(cat, s1, len + 1);
	ft_strlcat(cat, s2, len + 1);
	cat[len] = '\0';
	return (cat);
}