/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_stars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:36:20 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/29 15:53:11 by asobreir         ###   ########.fr       */
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
	if (flags->precision_star)
	{
		flags->precision_value = va_arg(ap, int);
		if (flags->precision_value < 0)
		{
			//if (flags->type == 's')
				flags->dot = 0;
			// 	flags->minus = 1;
			
			//flags->precision_value *= -1;
		}	
	}
}
