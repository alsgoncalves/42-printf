/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:41:52 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/28 22:24:57 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		put_prec(t_flag *flags, char *str, int *char_count)
{
	if (flags->precision_value <= (int)ft_strlen(str))
	{
		flags->precision_value = (int)ft_strlen(str);
		*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
	}
	else 
	{
		*char_count = ft_treat_width(flags->precision_value, (int)ft_strlen(str), 1, *(&char_count));
		*char_count = ft_treat_precision(flags->precision_value - (int)ft_strlen(str), str, *(&char_count));
	}
	return (*char_count);
}

int 	ft_treat_d(va_list ap, t_flag *flags)
{
	int char_count;
	int i;
	char *str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, int);
	str = ft_itoa(i);
	if (i == 0 && !flags->dot)
	{
		//char_count = ft_treat_width(flags->width, 0, 0, &char_count);
		return (char_count);
	}
	if (flags->minus)
		char_count = put_prec(flags, str, &char_count);
	if (flags->width > flags->precision_value)
	{
		if (flags->precision_value <= (int)ft_strlen(str))
			char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
		else
			char_count = ft_treat_width(flags->width, flags->precision_value, 0, &char_count);
	}
	if (!flags->minus)
		char_count = put_prec(flags, str, &char_count);
	free(str);
	return (char_count);
}
