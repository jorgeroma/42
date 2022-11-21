/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:01:38 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 16:40:29 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		len;
	char	*cat;

	len = 0;
	if (!s2)
		return (NULL);
	if (s1)
		len = ft_strlen(s1);
	len += ft_strlen(s2);
	cat = (char *)ft_calloc((len + 1), sizeof(char));
	if (!cat)
		return (free(cat), NULL);
	if (s1)
		ft_strlcat(cat, s1, len + 1);
	ft_strlcat(cat, s2, len + 1);
	cat[len] = '\0';
	free(s1);
	return (cat);
}
