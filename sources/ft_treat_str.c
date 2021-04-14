/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:39:13 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/14 15:50:12 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	if_no_precision(t_flag *flags, char *str, int *char_cnt)
{
	int	len;

	len = (int)ft_strlen(str);
	if (!flags->dot)
	{
		if (!flags->minus && !flags->width)
			*char_cnt = ft_putstr(str);
		if (flags->minus)
			*char_cnt = ft_putstr(str);
		if (flags->width)
		{
			if (flags->width > len)
				*char_cnt = ft_treat_width(flags->width, len, 1, *(&char_cnt));
			if (flags->minus == 0)
				*char_cnt += ft_putstr(str);
		}
	}
	return (*char_cnt);
}

int	if_prec_less_than_width(t_flag *flags, char *str, int *char_cnt)
{
	int	len;

	len = (int)ft_strlen(str);
	if (flags->prec_val <= flags->width && flags->dot)
	{
		if (flags->minus)
		{	
			*char_cnt = ft_treat_prec(flags->prec_val, str, *(&char_cnt));
			if (flags->prec_val < len)
				*char_cnt = ft_treat_width(flags->width,
						flags->prec_val, 1, *(&char_cnt));
			else
				*char_cnt = ft_treat_width(flags->width, len, 1, *(&char_cnt));
		}
		else
		{
			if (flags->prec_val < len)
				*char_cnt = ft_treat_width(flags->width,
						flags->prec_val, 1, *(&char_cnt));
			else
				*char_cnt = ft_treat_width(flags->width, len, 1, *(&char_cnt));
			*char_cnt = ft_treat_prec(flags->prec_val, str, *(&char_cnt));
		}
	}
	return (*char_cnt);
}

int	ft_treat_str(va_list ap, t_flag *flags)
{
	int		char_count;
	char	*str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	if (flags->prec_val > flags->width)
	{
		if (flags->minus)
			char_count = ft_treat_prec(flags->prec_val, str, &char_count);
		if (flags->width > (int)ft_strlen(str))
			char_count = ft_treat_width(flags->width,
					(int)ft_strlen(str), 1, &char_count);
		if (!flags->minus)
			char_count = ft_treat_prec(flags->prec_val, str, &char_count);
	}
	char_count = if_prec_less_than_width(flags, str, &char_count);
	char_count = if_no_precision(flags, str, &char_count);
	return (char_count);
}
