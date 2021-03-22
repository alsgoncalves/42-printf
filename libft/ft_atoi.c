/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:36:16 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/13 13:24:22 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
			c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	unsigned int	i;
	long long		sign;
	long long		result;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += sign * (str[i++] - '0');
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
	}
	return (result);
}
