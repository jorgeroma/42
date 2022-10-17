/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:18:29 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/17 20:12:39 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search(char *str, char c)
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

char	*ft_join_free(char *left, char *right, int i)
{
	char	*tmp;

	tmp = ft_strjoin(left, right);
	if (i >= 0)
		free(right);
	if (i <= 0)
		free(left);
	i = 0;
	return (tmp);
}

void	ft_rest(char **str)
{
	int		i;
	int		len;
	int 	counter;
	char	*remain;
	char	*tmp;

	i = ft_search(*str, '\n');
	if (i < 0)
		i = ft_search(*str, '\0');
	len = ft_strlen(*str);
	remain = (char *)ft_calloc((len - i) + 1, sizeof(char));
	counter = 0;
	if (remain)
	{
		while ((*str)[i])
		{
			remain[counter] = (*str)[i];
			i++;
			counter++;
		}
		tmp = *str;
		*str = remain;
		free(tmp);
	}
}

char	*ft_line(char **str, int status)
{
	char	*line;
	int		i;
	int		counter;

	i = ft_search(*str, '\n');
	if (i < 0)
		i = ft_search(*str, '\0');
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	counter = 0;
	while (counter < i + 1)
	{
		// line[counter] = (*str)[counter];
		line[counter] = **str;
		counter++;
		(*str)++;
	}
	// ft_rest(str);
	status = 2;
	return (line);
}

int	ft_read(int fd, char **str)
{
	int		status;
	char	*buffer;

	status = 1;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (status > 0 && ft_search(*str, '\n') < 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		*str = ft_strjoin(*str, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	free(buffer);

	return (status);
}

char	*get_next_line(int fd)
{
	static char	*str_array[4093];
	char		*line;
	int			i;
	int			status;

	if(fd < 0 || fd > 4093 || BUFFER_SIZE <= 0 || BUFFER_SIZE > BUFSIZ)
		return (NULL);
	status = 1;
	i = ft_search(str_array[fd], '\n');
	// if (i < 0)
	// 	i = ft_search(str_array[fd], '\0');
	if (i < 0)
		status = ft_read(fd, &str_array[fd]);
	if (status <= 0)
	{
		if (status == 0 && ft_strlen(str_array[fd]) > 0)
			return (ft_line(&str_array[fd], status));
		return (NULL);
	}
	if (status > 0)
	{
		line = ft_line(&str_array[fd], status);
		// if (status == 0 && ft_strlen(line) == 0)
		// {
		// 	free(line);
		// 	return ("ASKFNASLFKNASLKFNLASKF");
		// }
		return (line);
	}
	return (NULL);
}
