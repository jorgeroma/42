/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:09:51 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 19:21:54 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a copy of a substring from s, delimited by start and len.
 * 
 * @param s Source string
 * @param start Start index
 * @param len End index
 * @return char* Resoult string
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbtr;
	size_t	slen;

	while (*s && start--)
		s++;
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	sbtr = (char *)malloc((len + 1) * sizeof(char));
	if (!sbtr)
		return (NULL);
	ft_strlcpy(sbtr, s, len + 1);
	return (sbtr);
}
