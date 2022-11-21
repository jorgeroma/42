/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:39:29 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 17:57:33 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// gcc main.c push_swap/*.c push_swap/libft/*.c && a.out

#include "./push_swap/push_swap.h"
#include <fcntl.h>

int main(){

    // int fd = open("./prueba.txt", O_RDONLY);

    int nums[6] = {0, 1, 2, 3, 4, 5};
    t_list  *stack = ft_lstnew(nums);
    int nums2[2] = {7, 10};
    int i = 0;
    t_list  *stack2 = ft_lstnew(nums2);
    
    i = 1;
    while (i < 6)
    {
        ft_lstadd_back(&stack, ft_lstnew(nums + i));

        i++;
    }
    i = 1;
    while (i < 2)
    {
        ft_lstadd_back(&stack2, ft_lstnew(nums2 + i));
        i++;
    }
    ft_print_stk(stack);
    ft_printf("\n");
    ft_print_stk(stack2);
    ft_printf("\n------------------\n");

    swap(&stack2);
    // push(&stack, &stack2);
    // rotate(&stack2);
    // rev_rotate(&stack2);
    
    ft_print_stk(stack);
    ft_printf("\n");
    ft_print_stk(stack2);
    ft_printf("\n");

}