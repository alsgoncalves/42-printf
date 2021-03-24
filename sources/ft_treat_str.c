/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:39:13 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/24 13:15:58 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_str(va_list ap, t_flag *flags)
{
	int		char_count;
	char	*str;

	char_count = 0;
	str = va_arg(ap, char *);
	if (flags->minus)
	{
		char_count = (int)ft_strlen(str);
		ft_putstr(str);
	}
	if (flags->width)
	{
		if (flags->width > (int)ft_strlen(str))
			char_count = ft_treat_width(flags->width, (int)ft_strlen(str), 0, &char_count);
		if (flags->minus == 0)
		{
			ft_putstr(str);
			char_count += (int)ft_strlen(str);
		}
	}
	//printf("%i\n", char_count);
	return (char_count);
}
