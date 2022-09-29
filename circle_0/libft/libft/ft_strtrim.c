/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:46:39 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 19:07:31 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a copy of s1 with characters appearing en set from
 *			in the extrems trimmed.
 * 
 * @param s1 Source string
 * @param set Set of elements to trim.
 * @return char* Resoult string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (end <= 0)
		return (ft_strdup(""));
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start++;
	while (*(s1 + end) && ft_strchr(set, *(s1 + end)))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
