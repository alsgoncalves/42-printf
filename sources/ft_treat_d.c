/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:41:52 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/30 19:29:40 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		put_prec(t_flag *flags, int *i, char *str, int *char_count)
{
	//char *temp;

	if (flags->width < flags->precision_value)
		flags->width = 0;
	if (flags->precision_value <= (int)ft_strlen(str))
	{
		flags->precision_value = (int)ft_strlen(str);
		*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
	}
	else 
	{
		if (*i < 0)
		{
			ft_putchar('-');
			char_count++;
			*i *= -1;
			free(str);
			str = ft_itoa(*i);
		}
			*char_count = ft_treat_width((flags->precision_value), (int)ft_strlen(str), 1, *(&char_count));
			//printf("char_count %i\n", *char_count); NOT WORKING !!!
			*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
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
	//str = ft_itoa(i);
	if (i == 0 && flags->dot && !flags->precision_value)
		return (char_count);

	//Conversions
	if (flags->precision_value != -1 && flags->zero)
		flags->zero = 0;
	if (i < 0 && !flags->width)
	{
		ft_putchar('-');
		char_count++;
		i *= -1;
		str = ft_itoa(i);
		flags->width -= 1;
	}
	else
		str = ft_itoa(i);
	if (flags->precision_value <= (int)ft_strlen(str))
		flags->precision_value = (int)ft_strlen(str);
	if (flags->minus)
	{
		char_count = put_prec(flags, &i, str, &char_count);
		flags->zero = 0;
	}
	if (flags->width && flags->zero)
	{
		if (i < 0)
		{
			ft_putchar('-');
			char_count++;
			i *= -1;
			str = ft_itoa(i);
			flags->width -= 2;
		}
		char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 1, &char_count);
	}
		
	if (flags->width > flags->precision_value && flags->dot)
	{
		if (flags->precision_value <= (int)ft_strlen(str))
			char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
		else
		{
		// 	char_count = ft_treat_width(flags->width, flags->precision_value, 0, &char_count);
			if (i < 0)
			{
				char_count = ft_treat_width(flags->width - 1, flags->precision_value, 0, &char_count);
				ft_putchar('-');
				char_count++;
				i *= -1;
				str = ft_itoa(i);
			}
			else
				char_count = ft_treat_width(flags->width, flags->precision_value, 0, &char_count);
		}
	}
	if (!flags->minus)
		char_count = put_prec(flags, &i, str, &char_count);
	free(str);
	return (char_count);
}
