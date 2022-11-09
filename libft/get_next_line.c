/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:18:29 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/24 19:29:29 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_gnl_search(char *str, char c)
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

static char	*ft_rest(char **str)
{
	int		i;
	int		len;
	int		counter;
	char	*remain;

	i = ft_gnl_search(*str, '\n');
	if (i < 0)
		i = ft_gnl_search(*str, '\0');
	len = ft_strlen(*str);
	remain = (char *)ft_calloc((len - i) + 1, sizeof(char));
	counter = 0;
	i++;
	if (remain)
	{
		while (i < len)
		{
			remain[counter++] = (*str)[i++];
		}
		remain[counter] = '\0';
		return (free(*str), remain);
	}
	return (free(remain), free(*str), NULL);
}

static char	*ft_line(char **str)
{
	char	*line;
	int		i;
	int		counter;

	if (!(*str)[0])
		return (NULL);
	i = ft_gnl_search(*str, '\n');
	if (i < 0)
		i = ft_gnl_search(*str, '\0');
	if ((*str)[i] == '\n')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(line), NULL);
	counter = 0;
	while (counter < i)
	{
		line[counter] = (*str)[counter];
		counter++;
	}
	return (line);
}

static int	ft_read(int fd, char **str)
{
	int		status;
	char	*buffer;

	status = 1;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || BUFFER_SIZE < 0)
		return (free(buffer), free(*str), -1);
	while (status > 0 && ft_gnl_search(*str, '\n') < 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status < 0)
			return (free(buffer), -1);
		*str = ft_gnl_strjoin(*str, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (status);
}

char	*get_next_line(int fd)
{
	static char	*str_array[4096];
	char		*line;
	int			status;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	status = ft_read(fd, &str_array[fd]);
	if (status < 0)
		return (free(str_array[fd]), str_array[fd] = NULL, NULL);
	else
	{	
		if (status == 0 && ft_strlen(str_array[fd]) == 0)
			return (free(str_array[fd]), str_array[fd] = NULL, NULL);
		line = ft_line(&str_array[fd]);
		str_array[fd] = ft_rest(&str_array[fd]);
		return (line);
	}
	return (NULL);
}
