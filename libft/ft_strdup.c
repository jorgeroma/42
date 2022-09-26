/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:02:27 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/23 16:09:12 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_strdup:
		Creates a copy of src, allocating the necessary space in memory.
*/
char	*ft_strdup( const char *src )
{
	int		len;
	char	*cpy;

	len = ft_strlen(src);
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, src, len + 1);
	return (cpy);
}
