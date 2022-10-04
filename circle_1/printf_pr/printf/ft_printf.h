/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:38:08 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/03 20:37:52 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTPRINTF_H
# define	FTPRINTF_H

// Variadic functions
#include <stdarg.h>

# include "./libft/libft.h"

int 	    ft_printf(const char *str, ...);
void        ft_putptr_fd(void *ptr, int *counter, int capital, int prefix);


# endif
