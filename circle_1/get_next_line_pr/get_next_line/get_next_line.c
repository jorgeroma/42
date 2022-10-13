/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:00:44 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/11 18:44:01 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_search (char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*remain;
	char		*str;
	int			i;
	int			status;

	status = 1;
	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);

	str = NULL;
	i = -1;
	if (remain)
	{
		str = ft_strjoin(NULL, remain);
		i = ft_search(remain, '\n');
		remain = remain + i + 1;
	}
	while (i < 0 && status > 0)
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status < 0)
			return (NULL);
		str = ft_strjoin(str, buff);
		if (status == 0)
			i = ft_search(buff, '\0');
		else
			i = ft_search(buff, '\n');
		// printf("- I: %d\n", i);
	}
	if (buff)
		remain = ft_strjoin(remain, buff + i + 1);
	i = 0;
	while (str[i] && str[i ] != '\n')
		i++;
	str[i + 1] = '\0';
	
	return (str);
}