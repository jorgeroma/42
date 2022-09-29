/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:41:56 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:57 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes one element and shifts list left.
 * 
 * @param lst Element wich is being deleted.
 * @param del Function used to delete element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(del)(lst -> content);
	free(lst);
}
