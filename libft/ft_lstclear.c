/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:51:30 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/27 21:01:08 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (lst && *lst)
	{
		current = *lst;
		if (!(current -> next))
			ft_lstdelone(current, del);
		else
		{
			while (current -> next)
			{
				tmp = current;
				current = tmp -> next;
				ft_lstdelone(tmp, del);
			}
		}
	}
	*lst = NULL;
	lst = NULL;
}
