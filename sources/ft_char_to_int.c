/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:33:45 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/13 11:40:46 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	char_to_int(char *str, int *n)
{
	int	num;
	int	i;

	i = *n;
	num = 0;
	while (str[i])
	{
		if (is_num(str[i]))
		{
			num += str[i] - '0';
			while (is_num(str[i + 1]))
			{
				num = (num * 10) + (str[i + 1] - '0');
				i++;
			}
		}
		if (!is_num(str[i]))
			break ;
		i++;
	}
	*n = i;
	return (num);
}
