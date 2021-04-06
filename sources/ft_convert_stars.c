/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_stars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:36:20 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/05 11:52:04 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_convert_stars(t_flag *flags, va_list ap)
{
	//printf("flags->width_star : %i\n", flags->width_star);
	//printf("width before if : %i\n", flags->width);
	if (flags->width_star)
	{
		flags->width = va_arg(ap, int);
		//printf("CONV STARS width : %i\n", flags->width);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	if (flags->precision_star)
	{
		flags->precision_value = va_arg(ap, int);
		//printf("CONV STARS : %i\n", flags->precision_value);
		if (flags->precision_value < 0)
			flags->dot = 0;	
	}
}
