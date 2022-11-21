/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:04 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 18:01:03 by jorgerod         ###   ########.fr       */
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
    t_list  *list_iter;
    t_list    *tmp_1;
    t_list    *tmp_2;
    int     size;

    size = ft_lstsize(*stk);
    if (size > 2)
    {
        list_iter = *stk;
        while (((list_iter -> next) -> next) -> next != NULL)
            list_iter = list_iter -> next;
        tmp_1 = list_iter -> next;
        tmp_2 = (list_iter -> next) -> next;
        list_iter -> next = tmp_2;
        tmp_2 -> next = tmp_1;
        tmp_1 -> next = NULL;
    }else if (size == 2)
        rotate(stk);
}

void    push(t_list **stk_org, t_list **stk_dst)
{
    t_list  *list_iter;
    t_list  *tmp;
    int     size;

    size = ft_lstsize(*stk_org);
    if (size > 0)
    {
        if (size == 1)
        {
            tmp = *stk_org;
            *stk_org = NULL; 
        }
        else
        {
            list_iter = *stk_org;
            while ((list_iter -> next) -> next != NULL)
                list_iter = list_iter -> next;

            tmp = list_iter -> next;
            list_iter -> next = NULL;
        }
        list_iter = *stk_dst;
        while (list_iter -> next != NULL)
            list_iter = list_iter -> next;
        list_iter -> next = tmp;
    }
}

void    rotate(t_list **stk)
{
    t_list  *list_iter;
    t_list  *tmp;

    if (ft_lstsize(*stk) > 1)
    {
        tmp = *stk;
        *stk = (*stk) -> next;
        list_iter = *stk;
        while (list_iter -> next != NULL)
            list_iter = list_iter -> next;
        tmp -> next = NULL;
        list_iter -> next = tmp;
    }
}

void    rev_rotate(t_list **stk)
{
    t_list  *list_iter;
    t_list  *tmp;

    if (ft_lstsize(*stk) > 1)
    {
        list_iter = *stk;
        while ((list_iter -> next) -> next != NULL)
            list_iter = list_iter -> next;
        tmp = list_iter -> next;
        list_iter -> next = NULL;
        tmp -> next = *stk;
        *stk = tmp;
    }
}