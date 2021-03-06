/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:22:40 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 13:17:02 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_prec(int precision, char *str, int *char_count)
{
	int	temp;
	int	i;

	temp = *char_count;
	i = 0;
	if (precision < (int)ft_strlen(str))
	{
		while (precision)
		{
			ft_putchar(str[i]);
			temp++;
			i++;
			precision--;
		}
	}
	else
		temp += ft_putstr(str);
	*char_count = temp;
	return (*char_count);
}
