/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:41:52 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/07 13:02:35 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_conversions(t_flag *flags)
{
	if (flags->width < flags->precision_value)
		flags->width = 0;
	if (flags->minus && flags->zero)
		flags->zero = 0;
}

int 	conv_neg_prec(char *str, int *i, int *char_count)
{
	if (*i < 0)
	{
		ft_putchar('-');
		(*char_count)++;
		if (str)
			free(str);
		str = ft_substr(str, 1, ft_strlen(str));
	}
	return (*char_count);
}

int		put_prec(t_flag *flags, int *i, char *str, int *char_count)
{
	if (*i == 0 && flags->precision_value <= 0 && flags->dot)
		return (*char_count);
	*char_count = conv_neg_prec(str, i, char_count);
	if (flags->precision_value <= (int)ft_strlen(str))
	{
		flags->precision_value = (int)ft_strlen(str);
		*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
	}
	else 
	{
		*char_count = ft_treat_width(flags->precision_value, (int)ft_strlen(str), 0, *(&char_count));
		*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
	}
	return (*char_count);
}

int		handle_width_d_i(t_flag *flags, int *i, char *str, int *char_count)
{
	if (flags->width > flags->precision_value)
	{
		if (flags->precision_value < (int)ft_strlen(str))
		{	
			if (*i == 0 && flags->dot)
				*char_count = ft_treat_width(flags->width, 0, 1, *(&char_count));
			else
				*char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 1, *(&char_count));
		 }
		 else
		 {
			 if (*i < 0)
				flags->width -= 1;
			*char_count = ft_treat_width(flags->width, flags->precision_value, 1, *(&char_count));
		 }
	}
	return (*char_count);
}

int 	ft_treat_d_i(va_list ap, t_flag *flags)
{
	int char_count;
	int i;
	char *str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, int);
	flag_conversions(flags);
	str = ft_itoa(i);
	if (flags->minus)
		char_count = put_prec(flags, &i, str, &char_count);
	if (flags->width && flags->zero && !flags->dot)
	{
		if (i < 0)
			flags->width -= 1;
		flags->precision_value = flags->width;
		flags->width = 0;
		char_count = put_prec(flags, &i, str, &char_count);
		free(str);
		return (char_count);
	}
	char_count = handle_width_d_i(flags, &i, str, &char_count);
	if (!flags->minus)
		char_count = put_prec(flags, &i, str, &char_count);
	if (str)	
		free(str);
	return (char_count);
}
