/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:41:42 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 19:01:41 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_check_char(t_flag *flags, va_list ap, char a)
{
	char	c;

	if (a == 'c')
	{
		ft_convert_stars(flags, ap);
		c = va_arg(ap, int);
	}
	else
		c = '%';
	return (c);
}

void	ft_treat_char_width(t_flag *flags, char c, int *char_count)
{
	if (flags->zero && c == '%')
		*char_count = ft_treat_width(flags->width, 1, 0, *(&char_count)) + 1;
	else
		*char_count = ft_treat_width(flags->width, 1, 1, *(&char_count)) + 1;
	ft_putchar(c);
}

int	ft_treat_char(va_list ap, t_flag *flags, char a)
{
	int		char_count;
	char	c;

	char_count = 0;
	c = ft_check_char(flags, ap, a);
	if (flags->width)
	{
		if (flags->minus == 1)
		{
			ft_putchar(c);
			char_count = ft_treat_width(flags->width, 1, 1, &char_count) + 1;
		}
		else
			ft_treat_char_width(flags, c, &char_count);
	}
	else
	{
		ft_putchar(c);
		char_count++;
	}
	return (char_count);
}
