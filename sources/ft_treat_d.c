/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:41:52 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/07 11:58:12 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	conv_neg_prec(char *str, int *i, int *char_count)
{
	if (*i < 0)
	{
		ft_putchar('-');
		(*char_count)++;
		if (str)
			free(str);
		str = ft_substr(str, 1, ft_strlen(str));
		//*i *= -1;
		// if (str)
		// 	free(str);
		// str = ft_itoa(*i);
	}
	return (*char_count);
}

int		put_prec(t_flag *flags, int *i, char *str, int *char_count)
{
	//int len;

	//len = (int)ft_strlen(str);
	if (*i == 0 && flags->precision_value <= 0 && flags->dot)
		return (*char_count);
	*char_count = conv_neg_prec(str, i, char_count);
	//printf("LEN : %i\n", (int)ft_strlen(str));
	//printf("PREC : %i\n", flags->precision_value);
	if (flags->precision_value <= (int)ft_strlen(str))
	{
		//printf("LEN : %i\n", (int)ft_strlen(str));
		flags->precision_value = (int)ft_strlen(str);
		*char_count = ft_treat_precision(flags->precision_value, str, *(&char_count));
	}
	else 
	{
		//printf("LEN : %i\n", (int)ft_strlen(str));
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
	if (flags->width < flags->precision_value)
		flags->width = 0;
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
		// if (i < 0)
		// {
		// 	flags->width -= 1;
		// 	// if (str)
		// 	// 	free(str);
		// 	// str = ft_substr(str, 1, ft_strlen(str));
		// }
		//printf("i %i\n", i);
		//printf("str %s\n", str);
		//printf("len %d\n", (int)ft_strlen(str));
		//printf("PREC VAL %i\n", flags->precision_value);
		if (flags->precision_value < (int)ft_strlen(str) && i != 0)
		 {	
			 char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 1, &char_count);
		// 	flags->precision_value = (int)ft_strlen(str);
		// 	//printf("PREC VAL %i\n", flags->precision_value);
		 }
		 else
		 {
			 if (i < 0)
			{
				flags->width -= 1;
			}
			char_count = ft_treat_width(flags->width, flags->precision_value, 1, &char_count);
		 }
		 	
		//printf("PREC VAL %i\n", flags->precision_value);
		//printf("WIDTH %i\n", flags->width);
		
	}
	if (!flags->minus)
		char_count = put_prec(flags, &i, str, &char_count);
	if (str)	
		free(str);
	return (char_count);
}
