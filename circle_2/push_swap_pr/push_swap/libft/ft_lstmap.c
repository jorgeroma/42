/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:07 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:15:05 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a list with each element from 
 * 			the original list applied a funtion.
 * 			If function can't be applied, the outpud list is cleared.
 * 
 * @param lst List to apply the mapping to.
 * @param f Map function
 * @param del Deleting function in case mapping can't be done.
 * @return t_list* New list with mapping applied.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*new;

	cpy = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew((*f)(lst -> content));
		if (!new)
		{
			ft_lstclear(&cpy, del);
			return (cpy);
		}
		ft_lstadd_back(&cpy, new);
		lst = lst -> next;
	}
	return (cpy);
}
