/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:18:24 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:50:56 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_split:
		Splits a given string by the delimiter c.
		Returns an array of strings.
*/

/**
 * @brief Counts the number of phrases separated by
 * 			the delimiter c.
 * 
 * @param s String to count the number of phrases.
 * @param c Delimiter.
 * @return int Number of phrases.
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

/**
 * @brief Dettects and allocates a phrase.
 * 
 * @param s Pointer a string.
 * @param c Delimiter.
 * @param i Offset to the begining of a phrase.
 * @return char* Returns an array allocating a phrase.
 */
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

/**
 * 
 * @brief Frees the entire structure of split in case of error.
 * 
 * @param split Split structure.
 * @return char** NULL.
 */
static char	**ft_split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}	
	free(split);
	return (NULL);
}

/**
 * @brief Splits a given string by the delimiter c.
 *			Returns an array of strings.
 * 
 * @param s String it is going to split.
 * @param c Delimiter.
 * @return char** Structure containing each phrase.
 */
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
		if (!split[count])
			return (ft_split_free(split));
		count++;
		i++;
	}
	split[words] = NULL;
	return (split);
}
