/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:46:01 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 13:17:08 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_pointer(va_list ap, t_flag *flags, char a)
{
	unsigned long	i;
	int				char_count;
	char			*str;
	char			*str_joined;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, unsigned long);
	str = ft_xtoa(i, a);
	str_joined = ft_strjoin("0x", str);
	free(str);
	if (flags->minus)
		char_count = ft_putstr(str_joined);
	if (flags->width > (int)ft_strlen(str_joined))
		char_count = ft_treat_width(flags->width,
				(int)ft_strlen(str_joined), 1, &char_count);
	if (!flags->minus)
	{
		if (flags->width)
			char_count += ft_putstr(str_joined);
		else
			char_count = ft_putstr(str_joined);
	}
	free(str_joined);
	return (char_count);
}
