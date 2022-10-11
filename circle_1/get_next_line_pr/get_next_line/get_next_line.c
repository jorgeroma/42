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
	static char	*buff;
	char		*str;
	int			i;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buff, BUFFER_SIZE);
		printf("\n%s\n", buff);
	i = -1;
	// while (i < 0)
	// {
	// 	if (read(fd, buff, BUFFER_SIZE) < 0)
	// 		return (NULL);
		
	// 	printf("\n%s\n", buff);
	// 	str = ft_strjoin(str, buff);
		
	// 	i = ft_search(buff, '\n');
	// }
	i = 0;
	while (str[i] && str[i ] != '\n')
		i++;
	str[i + 1] = '\0';
	
	return (str);
}