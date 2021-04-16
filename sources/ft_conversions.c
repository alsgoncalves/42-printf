/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:36:20 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 16:26:00 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (flags->precision_star)
	{
		flags->prec_val = va_arg(ap, int);
		if (flags->prec_val < 0)
		{
			flags->dot = 0;
		}
	}
}

void	ft_flag_conversions(t_flag *flags)
{
	if (flags->width < flags->prec_val)
		flags->width = 0;
	if (flags->minus && flags->zero)
		flags->zero = 0;
}

int	ft_conv_args_i(va_list ap, t_flag *flags)
{
	int	i;

	ft_convert_stars(flags, ap);
	i = va_arg(ap, int);
	ft_flag_conversions(flags);
	return (i);
}

char	ft_check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}
