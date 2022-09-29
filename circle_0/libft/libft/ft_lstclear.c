/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:51:30 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:53 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Clears the list from a given pointer.
 * 
 * @param lst List it is going to delete.
 * @param del Funtion used to delete the content of each node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst && *lst)
	{
		while (*lst)
		{	
			next = (*lst)-> next;
			ft_lstdelone((*lst), del);
			(*lst) = next;
		}
	}
}
