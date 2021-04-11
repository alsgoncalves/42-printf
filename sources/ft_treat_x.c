/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:55:17 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/11 10:42:01 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	ft_treat_x(va_list ap, t_flag *flags, char a)
{
	int char_count;
	unsigned int i;
	char *str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, unsigned int);
	flag_conversions(flags);

	str = ft_xtoa(i, a);
	if (flags->minus)
		char_count = put_prec_u(flags, &i, str, &char_count);
	if (flags->width && flags->zero && !flags->dot)
	{
		if (i < 0)
			flags->width -= 1;
		flags->precision_value = flags->width;
		flags->width = 0;
		char_count = put_prec_u(flags, &i, str, &char_count);
		free(str);
		return (char_count);
	}
	char_count = handle_width_u(flags, &i, str, &char_count);
	if (!flags->minus)
		char_count = put_prec_u(flags, &i, str, &char_count);
	if (str)	
		free(str);
	return (char_count);
}