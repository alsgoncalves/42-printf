/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:39:13 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/22 15:42:42 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_treat_str_width(t_flag *flags, int *char_count, char *str)
{
	int temp;
	int i;

	temp = *char_count;
	i = ft_strlen(str);
	if (flags->width > ft_strlen(str))
	{
		while (flags->width - i > 0)
		{
			ft_putchar(' ');
			flags->width--;
			temp++;
		}
	}
	if (flags->minus == 0)
	{
		while (ft_strlen(str))
		{
			ft_putchar(*str);
			temp++;
			str++;
		}
	}
	*char_count = temp;
	return (*char_count);
}

int		ft_treat_minus(int *char_count, char *str)
{
	int temp;

	temp = *char_count;
	while (ft_strlen(str))
	{
		ft_putchar(*str);
		temp++;
		str++;
	}
	*char_count = temp;
	return (*char_count);
}

int		ft_treat_str(va_list ap, t_flag *flags)
{
	int		char_count;
	char	*str;

	char_count = 0;
	str = va_arg(ap, char *);
	if (flags->minus)
		char_count = ft_treat_minus(&char_count, str);
	if (flags->width)
		char_count = ft_treat_str_width(flags, &char_count, str);
	return (char_count);
}
