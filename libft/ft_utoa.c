/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:25:05 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/07 15:26:07 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_length_u(unsigned int n)
{
	int length;

	length = 0;
	if (n % 10 >= 0)
		length++;
	while (n /= 10)
		length++;
	return (length);
}

char	*ft_print_n_u(unsigned int n)
{
	char			*str;
	int				negative;
	unsigned int	index;

	negative = 0;
	if (n < 0)
	{
		negative += 1;
		n = -n;
	}
	if (!(str = (char *)malloc(negative + n_length_u(n) + 1)))
		return (NULL);
	index = n_length_u(n) + negative;
	str[index--] = '\0';
	while (n >= 10)
	{
		str[index--] = (n % 10) + '0';
		n /= 10;
	}
	if (n % 10 >= 0)
		str[index--] = n + '0';
	if (negative == 1)
		str[index] = '-';
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_print_n_u(n));
}