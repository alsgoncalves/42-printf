/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:46:01 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/12 16:52:53 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_p(va_list ap, t_flag *flags, char a)
{
	unsigned int i;
	int char_count;
	char *str;
	char *str_joined;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, unsigned int);
	str = ft_xtoa(i, a);
	//printf("str %s\n", str);
	str_joined = ft_strjoin("0x", str);
	//printf("str_joined %s\n", str_joined);
	free(str);
	if (flags->minus)
		char_count = ft_putstr(str_joined);
	if (flags->width > (int)ft_strlen(str_joined))
	{
		char_count = ft_treat_width(flags->width, (int)ft_strlen(str_joined), 1, &char_count);
	}
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