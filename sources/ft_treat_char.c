/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:41:42 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/25 15:05:42 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_star(va_list ap, t_flag *flags, int *char_count)
{
	int		temp;
	char	c;

	temp = *char_count;
	flags->width = va_arg(ap, int);
	if (flags->minus == 1 || flags->width < 0)
	{
		c = va_arg(ap, int);
		ft_putchar(c);
		temp++;
		temp = ft_treat_width(flags->width, 1, 0, &temp);
	}
	else
	{
		temp = ft_treat_width(flags->width, 1, 0, &temp);
		c = va_arg(ap, int);
		ft_putchar(c);
		temp++;
	}
	*char_count = temp;
	return (*char_count);
}

int		ft_treat_char(va_list ap, t_flag *flags)
{
	int		char_count;
	char	c;

	char_count = 0;
	if (!flags->width && !flags->minus && !flags->width_star)
	{
		ft_putchar(va_arg(ap, int));
		char_count++;
	}
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
	if (flags->width_star)
		char_count = ft_treat_star(ap, flags, &char_count);
	return (char_count);
}
