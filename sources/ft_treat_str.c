/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:39:13 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/26 16:13:26 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_convert_stars(t_flag *flags, va_list ap)
{
	if (flags->width_star)
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	if (flags->precision_star && flags->dot)
	{
		flags->precision_value = va_arg(ap, int);
		if (flags->precision_value < 0)
			flags->minus = 1;	
	}
}

int		ft_treat_str(va_list ap, t_flag *flags)
{
	int		char_count;
	char 	*str;

	char_count = 0;
	ft_convert_stars(flags, ap);

	if (flags->precision_value > flags->width && flags->dot)
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		if (flags->minus)
			char_count = ft_treat_precision(flags->precision_value, str, &char_count);
		if (flags->width > (int)ft_strlen(str))
			char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
		if (!flags->minus)
			char_count = ft_treat_precision(flags->precision_value, str, &char_count);
	}
	if (flags->precision_value <= flags->width && flags->dot)
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		if (flags->minus)
		{	
			char_count = ft_treat_precision(flags->precision_value, str, &char_count);
			if (flags->precision_value < (int)ft_strlen(str))
				char_count = ft_treat_width(flags->width, flags->precision_value, 0, &char_count);
			else 
			{
				char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
			}
		}
		else
		{
			if (flags->precision_value < (int)ft_strlen(str))
				char_count = ft_treat_width(flags->width, flags->precision_value, 0, &char_count);
			else 
				char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
			char_count = ft_treat_precision(flags->precision_value, str, &char_count);
		}
	}
	if (!flags->dot)
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		if (!flags->minus && !flags->width && !flags->dot)
			char_count = ft_putstr(str);
		if (flags->minus)
			char_count = ft_putstr(str);
		if (flags->width)
		{
			if (flags->width > (int)ft_strlen(str))
				char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
			if (flags->minus == 0)
				char_count += ft_putstr(str);
		}
	}
	return (char_count);
}
