/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgerod <jorgerod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:21:23 by jorgerod          #+#    #+#             */
/*   Updated: 2022/11/21 16:40:12 by jorgerod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Given a char array with any characters of is_space,
 *			an option '+' or '-' and a sequence of numbers
 *			converts it to an integer.
 * @param str String containing a number.
 * @return int Number contained in str.
 */
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (sign * num);
}
