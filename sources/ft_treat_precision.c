/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:22:40 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/26 11:43:08 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// int		ft_treat_precision(va_list ap, t_flag *flags, int *char_count)
// {
// 	int		temp;
// 	char	*str;

// 	temp = *char_count;
// 	if (flags->dot && !flags->precision_value && !flags->precision_star)
// 		return (*char_count);
// 	if (flags->dot && (flags->precision_value || flags->precision_star))
// 	{
// 		if (flags->precision_star)
// 			flags->precision_value = va_arg(ap, int);
// 		str = va_arg(ap, char *);
// 		if ((int)ft_strlen(str) <= flags->precision_value)
// 			temp += ft_putstr(str);
// 		else
// 		{
// 			while (flags->precision_value)
// 			{
// 				ft_putchar(*str);
// 				temp++;
// 				str++;
// 				flags->precision_value--;
// 			}
// 		}
// 	}
// 	*char_count = temp;
// 	return (*char_count);
// }

int		ft_treat_precision(int precision, char *str, int *char_count)
{
	int temp;
	int i;

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
		temp = ft_putstr(str);
	*char_count = temp;
	return (*char_count);
}
