/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:41:52 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/06 15:44:26 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	conv_neg_prec(char *str, int *i, int *char_count)
{
	if (*i < 0)
	{
		ft_putchar('-');
		(*char_count)++;
		*i *= -1;
		if (str)
			free(str);
		str = ft_itoa(*i);
	}
	return (*char_count);
}

int		put_prec(t_flag *flags, int *i, char *str, int *char_count)
{
	int len;

	len = 0;
	if (*i == 0 && flags->precision_value <= 0 && flags->dot)
		return (*char_count);
	if (flags->precision_value <= (int)ft_strlen(str))
	{
		// if (*i < 0)
		// {
		// 	len = (int)ft_strlen(str) + 1;
		// 	//printf("xx: %i\n", len);
		// }
		// else 
		len = (int)ft_strlen(str);
		*char_count = conv_neg_prec(str, i, char_count);
		flags->precision_value = len;
		*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
	}
	else 
	{
		*char_count = conv_neg_prec(str, i, char_count);
		*char_count = ft_treat_width(flags->precision_value, (int)ft_strlen(str), 0, *(&char_count));
		//printf("LEN : %zu\n", ft_strlen(str));
		*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
	}
	//printf("\nCHAR COUNT in PUT PREC: %i\n", *char_count);
	return (*char_count);
}

int 	ft_treat_d(va_list ap, t_flag *flags)
{
	int char_count;
	int i;
	//int len;
	char *str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, int);
	
	if (i == 0 && flags->width && !flags->dot)
	{
		char_count = ft_treat_width(flags->width, 0, 1, &char_count);
		return (char_count);
	}
	// if (i == 0 && flags->dot && flags->precision_value <= 0)
	// {
	// 	//char_count = ft_treat_width(1, 0, 1, &char_count);
	// 	flags->dot = 0;
	// }
	if (i < 0)
			
	if (flags->width < flags->precision_value)
		flags->width = 0;
	// //Conversions
	if (flags->minus && flags->zero)
		flags->zero = 0;
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
		return (char_count);
	}
	if (flags->width > flags->precision_value)
	{
		if (i < 0 && flags->precision_value > (int)ft_strlen(str))
			flags->width -= 1;
		if (flags->precision_value <= (int)ft_strlen(str) && i != 0)
		{	
			flags->precision_value = (int)ft_strlen(str);
			//printf("PREC VAL %i\n", flags->precision_value);
		}
		//printf("PREC VAL %i\n", flags->precision_value);
		//printf("WIDTH %i\n", flags->width);
		char_count = ft_treat_width(flags->width, flags->precision_value, 1, &char_count);
	}
	if (!flags->minus)
		char_count = put_prec(flags, &i, str, &char_count);
	if (str)	
		free(str);
	return (char_count);
}
