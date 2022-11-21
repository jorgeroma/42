/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:40:18 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 21:00:11 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
char	*ft_replace(char **str, char *before, char after)
{
	int		i;
	int		size;
	char	*str_copy;
	
	i = 0;
	str_copy = ft_strdup(*str);
	size = ft_strlen(before);
	while (str_copy[i])
	{	
		if (ft_memchr(before, str_copy[i], size))
			str_copy[i] = after;
		i++;
	}
	return (str_copy);
}

int	ft_all_digit(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((int) str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_parser(char **mtx, int *size)
{
	int	numbers;
	int	*num_array;

	numbers = 0;
	while (ft_all_digit(mtx[numbers]))
		numbers++;
	if (mtx[numbers] == NULL)
	{
		num_array = (int *)ft_calloc(numbers + 1, sizeof(int));
		if(!num_array)
			return (NULL);
		numbers = 0;
		while (mtx[numbers])
		{
			num_array[numbers] = ft_atoi(mtx[numbers]);
			numbers++;
		}
		*size = numbers;
		return (num_array);
		return NULL;
	}
	else
		return (NULL);
}

int main(int argc, char *argv[])
{	
	int tam;
	int	*arr;
	int i = 0;
	if (argc == 2)
	{	
		arr = ft_parser(ft_split(ft_replace(&argv[1], "\n\t", ' '), ' '), &tam);
		while (i < tam)
		{

			printf("%d\n", arr[i]);
			i++;
		}
		// ft_printf("%s", );
	}
	else if (argc > 1)
	{
		return (0);
	}
	else
		ft_printf("Error.");
	return 0;
}