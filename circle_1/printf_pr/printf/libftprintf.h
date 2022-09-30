/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:38:08 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/29 18:57:26 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFTPRINTF_H
# define	LIBFTPRINTF_H

// Variadic functions
#include <stdarg.h>

# include "libft/libft.h"

int 	ft_printf(const char *str, ...);
void    ft_putptr_fd(void *ptr, int fd);

# endif
