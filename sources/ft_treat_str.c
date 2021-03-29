/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:39:13 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/29 13:19:20 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		if_no_precision(t_flag *flags, char *str, int *char_count)
{
	if (!flags->dot)
	{
		if (!flags->minus && !flags->width)
			*char_count = ft_putstr(str);
		if (flags->minus)
			*char_count = ft_putstr(str);
		if (flags->width)
		{
			if (flags->width > (int)ft_strlen(str))
				*char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, *(&char_count));
			if (flags->minus == 0)
				*char_count += ft_putstr(str);
		}
	}
	return (*char_count);
}

int		if_prec_less_than_width(t_flag *flags, char *str, int *char_count)
{
	if (flags->precision_value <= flags->width && flags->dot)
	{
		if (flags->minus)
		{	
			*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
			if (flags->precision_value < (int)ft_strlen(str))
				*char_count = ft_treat_width(flags->width, flags->precision_value, 0, *(&char_count));
			else 
				*char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, *(&char_count));
		}
		else
		{
			if (flags->precision_value < (int)ft_strlen(str))
				*char_count = ft_treat_width(flags->width, flags->precision_value, 0, *(&char_count));
			else 
				*char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, *(&char_count));
			*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
		}
	}
	return (*char_count);
}

int		ft_treat_str(va_list ap, t_flag *flags)
{
	int		char_count;
	char 	*str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	if (flags->precision_value > flags->width )
	{
		if (flags->minus)
			char_count = ft_treat_precision(flags->precision_value, str, &char_count);
		if (flags->width > (int)ft_strlen(str))
			char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
		if (!flags->minus)
			char_count = ft_treat_precision(flags->precision_value, str, &char_count);
	}
	char_count = if_prec_less_than_width(flags, str, &char_count);
	char_count = if_no_precision(flags, str, &char_count);
	return (char_count);
}
