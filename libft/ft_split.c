/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:18:24 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/27 19:32:13 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_split:
		Splits a given string by the delimiter c.
		Returns an array of strings.
*/
static int	ft_split_count(char const *s, char c)
{
	int	words;
	int	bw;
	int	i;

	i = 0;
	words = 0;
	bw = 1;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (bw)
				words++;
			bw = 0;
		}
		else
			bw = 1;
		i++;
	}
	return (words);
}

static char	*ft_split_get_word(char *s, char c, int *i)
{
	int		start;
	int		count;
	char	*word;

	start = *i;
	count = 0;
	while (s[*i] && s[*i] != c)
		*i = *i + 1;
	word = (char *)malloc((*i - start + 1) * sizeof(char));
	if (word == NULL)
	{
		return (NULL);
	}
	while (start < *i)
	{
		word[count] = s[start];
		start++;
		count++;
	}
	word[count] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;
	int		count;

	words = ft_split_count(s, c);
	i = 0;
	count = 0;
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (split == NULL)
	{
		return (NULL);
	}
	while (count < words)
	{
		while (s[i] && s[i] == c)
			i++;
		split[count] = ft_split_get_word((char *)s, c, &i);
		count++;
		i++;
	}
	split[words] = NULL;
	return (split);
}
