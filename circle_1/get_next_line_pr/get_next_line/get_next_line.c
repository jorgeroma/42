/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:00:44 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/14 20:09:51 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_search (char *str, char c)
{
	int	i;
	
	if (str)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

void prueba(char *str)
{
	int i = 0;
	while (str[i])
	{
		printf("%c\n", str[i]);
		i++;
	}
}

int ft_get_line(int fd, char **str)
{
	char	*buff;
	int		i;
	int		status;

	i = -1;
	buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
	while (i < 0)
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status < 0)
			return (-1);
		else if (status == 0)
		{
			i = ft_search(buff, '\0');
			prueba(buff);
		}
		else
			i = ft_search(buff, '\n');
		*str = ft_strjoin(*str, buff);
		ft_bzero(buff, BUFFER_SIZE);
	}
	free(buff);
	return (status);
}

char	*get_next_line(int fd)
{
	static char	**str_array;
	char		*copy;
	int			i;
	int			status;

	str_array = (char **)ft_calloc(4096, sizeof(char *));
	i = ft_search(str_array[fd], '\n');
	if (i < 0)
		ft_get_line(fd, &str_array[fd]);
	i = ft_search(str_array[fd], '\n');
	copy = ft_strjoin(NULL, str_array[fd]);
	str_array[fd] = str_array[fd] + i + 1;
	copy[i] = '\0';
	return (copy);
}