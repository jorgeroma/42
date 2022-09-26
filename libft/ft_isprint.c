/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:17:13 by jorgerod          #+#    #+#             */
/*   Updated: 2022/09/23 15:15:34 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	ft_isprint:
		Returns 1 if c is a printable character, 0 if not.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
