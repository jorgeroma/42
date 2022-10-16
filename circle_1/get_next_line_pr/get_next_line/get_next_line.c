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

int ft_get_line(int fd, char **str)
{
	char	*buff;
	int		i;
	int		status;

	i = -1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (-1);
	while (i < 0)
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status < 0)
			return (-1);
		else if (status == 0)
		{
			i = ft_search(buff, '\0');
		}
		else
			i = ft_search(buff, '\n');
		buff[BUFFER_SIZE] = '\0';
		*str = ft_strjoin(*str, buff);
		printf("BUFF: %d\n", buff[0]);
		ft_bzero(buff, BUFFER_SIZE);
	}
	free(buff);
	return (status);
}

char	*ft_free_all(char **str)
{
	int i = 0;
	while (i < 4096)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str_array[4096];
	char		*copy;
	int			i;
	int			status;

	copy = NULL;
	i = ft_search(str_array[fd], '\n');
	if (i < 0 || !str_array[fd])
	{
		status = ft_get_line(fd, &str_array[fd]);
		if (status < 0)
			return (ft_free_all(str_array));
		// else if (status == 0)
		// 	printf("XXXXXXXXXXXX");
	}
	if (status == 0 && str_array[fd] == NULL)
		return (NULL);
	i = ft_search(str_array[fd], '\n');
	if (i < 0)
		i = ft_search(str_array[fd], '\0');

	// printf("\nSTR: %s\n", str_array[fd]);
	copy = ft_strjoin(copy, str_array[fd]);
	str_array[fd] = str_array[fd] + i + 1;
	if (str_array[fd][0] == '\0')
		str_array[fd] = NULL;
	copy[i] = '\0';
	return (copy);
}