/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:41:42 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/26 18:37:18 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_char(va_list ap, t_flag *flags)
{
	int		char_count;
	char	c;

	char_count = 0;
	ft_convert_stars(flags, ap);
	if (flags->width)
	{
		if (flags->minus == 1)
		{
			c = va_arg(ap, int);
			ft_putchar(c);
			char_count = ft_treat_width(flags->width, 1, 0, &char_count) + 1;
		}
		else
		{
			c = va_arg(ap, int);
			char_count = ft_treat_width(flags->width, 1, 0, &char_count) + 1;
			ft_putchar(c);
		}
	}
	else
	{
		ft_putchar(va_arg(ap, int));
		char_count++;
	}
	return (char_count);
}
