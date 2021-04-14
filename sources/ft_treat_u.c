/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:17:26 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/14 15:41:35 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	put_prec_u(t_flag *flags, unsigned int *i, char *str, int *char_count)
{
	int	len;

	len = (int)ft_strlen(str);
	if (*i == 0 && flags->prec_val <= 0 && flags->dot)
		return (*char_count);
	if (flags->prec_val <= len)
	{
		flags->prec_val = len;
		*char_count = ft_treat_prec(flags->prec_val, str, *(&char_count));
	}
	else
	{
		*char_count = ft_treat_width(flags->prec_val, len, 0, *(&char_count));
		*char_count = ft_treat_prec(flags->prec_val, str, *(&char_count));
	}
	return (*char_count);
}

int	handle_width_u(t_flag *flags, unsigned int *i, char *str, int *char_cnt)
{
	int	len;

	len = (int)ft_strlen(str);
	if (flags->width > flags->prec_val)
	{
		if (flags->prec_val < len)
		{	
			if (*i == 0 && flags->dot)
				*char_cnt = ft_treat_width(flags->width, 0, 1, *(&char_cnt));
			else
				*char_cnt = ft_treat_width(flags->width, len, 1, *(&char_cnt));
		}
		 else
			*char_cnt = ft_treat_width(flags->width,
					flags->prec_val, 1, *(&char_cnt));
	}
	return (*char_cnt);
}

int	ft_treat_u(va_list ap, t_flag *flags)
{
	int				char_count;
	unsigned int	i;
	char			*str;

	char_count = 0;
	ft_convert_stars(flags, ap);
	i = va_arg(ap, unsigned int);
	ft_flag_conversions(flags);
	str = ft_utoa(i);
	if (flags->minus)
		char_count = put_prec_u(flags, &i, str, &char_count);
	if (flags->width && flags->zero && !flags->dot)
	{
		flags->prec_val = flags->width;
		flags->width = 0;
		char_count = put_prec_u(flags, &i, str, &char_count);
		free(str);
		return (char_count);
	}
	char_count = handle_width_u(flags, &i, str, &char_count);
	if (!flags->minus)
		char_count = put_prec_u(flags, &i, str, &char_count);
	if (str)
		free(str);
	return (char_count);
}
