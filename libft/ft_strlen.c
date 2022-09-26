/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:29:54 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/23 15:35:12 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
	ft_strlen:
		Returns the length of s.
*/
unsigned int	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
