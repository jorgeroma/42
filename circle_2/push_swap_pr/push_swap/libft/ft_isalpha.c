/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:54:48 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 16:40:22 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns 1 if c is a letter, 0 if not.
 * 
 * @param c Character to check.
 * @return int, 1 if c is a letter, 0 if not.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
