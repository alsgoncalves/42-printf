/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:25:05 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 14:50:35 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_length_u(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		length++;
		return (length);
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	index;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		str = (char *)malloc(n_length_u(n) + 1);
		if (!str)
			return (NULL);
		index = n_length_u(n);
		str[index--] = '\0';
		while (n >= 10)
		{
			str[index--] = (n % 10) + '0';
			n /= 10;
		}
		str[index--] = n + '0';
	}
	return (str);
}
