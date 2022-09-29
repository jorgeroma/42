/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:31:07 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:43 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds an element to the last position of the list.
 * 
 * @param lst List where it is going to add an element.
 * @param new Element it is going to add.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (lst && *lst)
	{
		node = *lst;
		while (node -> next)
			node = node -> next;
		node -> next = new;
	}
	else
		*lst = new;
}
