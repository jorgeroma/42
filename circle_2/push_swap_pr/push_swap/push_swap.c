/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:04 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 16:40:06 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del(void *content)
{
	free(content);
}

void    ft_print_stk(t_list *stk)
{
    int tmp;
    
    ft_printf("[");
    while (stk)
    {
        tmp = *((int *) (stk -> content));
        ft_printf("%d", tmp);
        if ((stk -> next))
            ft_printf(" <- ");
        stk = stk -> next;
    }
    ft_printf("]");
}

void    swap(t_list **stk)
{
    t_list  *tmp_elem;
    void    *tmp_1;
    void    *tmp_2;
    int     i;

    if (ft_lstsize(*stk) >= 2)
    {
        tmp_elem = ft_lstlast(*stk);
        tmp_1 = tmp_elem -> content;
        i =  *((int *) (tmp_1));
        ft_printf("%d", i);
        ft_lstdelone(ft_lstlast(*stk), ft_del);
        // tmp_elem = ft_lstlast(*stk);
        // tmp_2 = tmp_elem -> content;
        // ft_lstdelone(tmp_elem, ft_del);
    }
}