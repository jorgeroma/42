/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:46:39 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/26 18:12:37 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find(char const *s, unsigned char c)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_substr(char const *s, int start, int end)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc(end - start + 1, sizeof(char));
	i = 0;
	if (NULL)
		return (NULL);
	while (start <= end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[end + 1] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	end;
	int	start;
	int	found;

	found = 1;
	end = ft_strlen(s1) - 1;
	start = 0;
	while (*(s1 + start) && found)
	{
		if (!ft_strchr(set, *(s1 + start)))
			found = 0;
		else
			start++;
	}
	found = 1;
	while (*(s1 + end) && found)
	{
		if (!ft_strchr(set, *(s1 + end)))
			found = 0;
		else
			end--;
	}
	if (end < start)
		return ((char *)calloc(1, sizeof(char)));
	return (ft_strtrim_substr(s1, start, end));

}