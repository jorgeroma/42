/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:38:08 by jorgerod          #+#    #+#             */
/*   Updated: 2022/10/05 15:32:05 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Variadic functions
# include <stdarg.h>

# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_putptr_fd(void *ptr, int *counter, int capital, int prefix);
void	ft_match_case_s(va_list *ptr, int *counter);
int		ft_check_space(char *str);
#endif
