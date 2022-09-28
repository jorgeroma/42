/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:20:14 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:21:16 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets the value of the n first elements of b to c
 *			and returns a pointer to b.
 * 
 * @param b Array it is goint to set it's value to.
 * @param c Element it is goint to substitute the value to.
 * @param len Number of elements it is goint to set.
 * @return void* Pointer to b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c % 256;
		i++;
	}
	return (b);
}
