/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:03:56 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/16 19:04:35 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_length(int n)
{
	int length;

	length = 0;
	if (n % 10 >= 0)
		length++;
	while (n /= 10)
		length++;
	return (length);
}

char	*ft_print_n(int n)
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
	if (!(str = (char *)malloc(negative + n_length(n) + 1)))
		return (NULL);
	index = n_length(n) + negative;
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

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == (-2147483647 - 1))
		return (ft_strdup("-2147483648"));
	return (ft_print_n(n));
}
