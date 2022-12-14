/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:39:56 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 17:55:43 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void    swap(t_list **stk);
void    ft_print_stk(t_list *stk);
void	push(t_list **stk_org, t_list **stk_dst);
void    rotate(t_list **stk);
void    rev_rotate(t_list **stk);

#endif
