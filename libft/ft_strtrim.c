/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:46:39 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/26 20:37:31 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_find(char const *s, unsigned char c)
// {
// 	int	i;
	
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

static char	*ft_strtrim_substr(char const *s, int start, int end)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc(end - start + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
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
	char *a;

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
	{
		a = (char *)calloc(1, sizeof(char));
		if (!a)
			return (NULL);
		return (a);
	}
	return (ft_strtrim_substr(s1, start, end));

}