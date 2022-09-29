/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:24:51 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:46:28 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a concatenation of strings s1 and s2.
 * 
 * @param s1 String one.
 * @param s2 String two.
 * @return char* String concatenating s1 and s2.
 */
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
