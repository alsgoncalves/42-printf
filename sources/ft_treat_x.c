/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:55:17 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/14 15:45:06 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_x(va_list ap, t_flag *flags, char a)
{
	int				char_count;
	unsigned int	i;
	char			*str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, unsigned int);
	ft_flag_conversions(flags);
	str = ft_xtoa(i, a);
	if (flags->minus)
		char_count = put_prec_u(flags, &i, str, &char_count);
	if (flags->width && flags->zero && !flags->dot)
	{
		flags->prec_val = flags->width;
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
