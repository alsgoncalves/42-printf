/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:40:35 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 13:16:30 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_x(unsigned long n, char a)
{
	int		i;
	int		temp;
	char	*hexadecimalnum;

	hexadecimalnum = ft_calloc(100, sizeof(char));
	i = 0;
	while (n != 0)
	{
		temp = n % 16;
		if ((a == 'x' || a == 'X') && temp < 10)
			hexadecimalnum[i++] = temp + 48;
		else if (a == 'X' && temp >= 10)
			hexadecimalnum[i++] = temp + 55;
		else if (a == 'x' && temp >= 10)
			hexadecimalnum[i++] = temp + 87;
		n = n / 16;
	}
	return (hexadecimalnum);
}

char	*ft_print_correct_order(char *str, int str_len)
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	i = str_len - 1;
	while (i >= ((int)ft_strlen(str) / 2))
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

char	*ft_xtoa(unsigned long n, char a)
{
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = ft_print_x(n, a);
	return (ft_print_correct_order(str, ft_strlen(str)));
}
