/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:39:48 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 16:40:17 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates a memory space defined by count and size.
 * 
 * @param count Number of positions.
 * @param size Size of element type.
 * @return void* Pointer to the allocated memmory.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr)
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
	return (NULL);
}
