/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:41:42 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/24 12:00:05 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int		ft_treat_width(t_flag *flags, int *char_count)
// {
// 	int temp;

// 	temp = *char_count;
// 	while (flags->width - 1 > 0)
// 	{
// 		ft_putchar(' ');
// 		temp++;
// 		flags->width--;
// 	}
// 	*char_count = temp;
// 	return (*char_count);
// }


int		ft_treat_star(va_list ap, t_flag *flags, int *char_count)
{
	int		temp;
	char	c;

	temp = *char_count;
	flags->width = va_arg(ap, int);
	if (flags->minus == 1)
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
	if (flags->width)
	{
		if (flags->minus == 1)
		{
			c = va_arg(ap, int);
			ft_putchar(c);
			char_count++;
			char_count = ft_treat_width(flags->width, 1, 0, &char_count);
		}
		else
		{
			c = va_arg(ap, int);
			char_count = ft_treat_width(flags->width, 1, 0, &char_count);
			ft_putchar(c);
			char_count++;
		}
	}
	if (flags->star)
		char_count = ft_treat_star(ap, flags, &char_count);
	return (char_count);
}
