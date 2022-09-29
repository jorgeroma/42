/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:27:38 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/28 18:15:02 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Gets the last element of a list.
 * 
 * @param lst List where it is goint to find the last element.
 * @return t_list* Pointer to the last element.
 */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}
