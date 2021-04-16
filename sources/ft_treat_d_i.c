/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:41:52 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 13:17:20 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_neg_prec(char **str, int *i, int *char_count)
{
	char	*dup;

	if (*i < 0)
	{
		ft_putchar('-');
		(*char_count)++;
		if (*str)
		{
			dup = ft_strdup(*str);
			free(*str);
			*str = ft_substr(dup, 1, ft_strlen(dup));
			free(dup);
		}
	}
	return (*char_count);
}

int	put_prec(t_flag *flags, int *i, char **str, int *char_cnt)
{
	int	len;

	len = 0;
	if (*i == 0 && flags->prec_val <= 0 && flags->dot)
		return (*char_cnt);
	*char_cnt = conv_neg_prec(*(&str), i, char_cnt);
	len = (int)ft_strlen(*str);
	if (flags->prec_val <= len)
	{
		flags->prec_val = len;
		*char_cnt = ft_treat_prec(flags->prec_val, *str, *(&char_cnt));
	}
	else
	{
		*char_cnt = ft_treat_width(flags->prec_val, len, 0, *(&char_cnt));
		*char_cnt = ft_treat_prec(flags->prec_val, *str, *(&char_cnt));
	}
	return (*char_cnt);
}

int	handle_width_d_i(t_flag *flags, int *i, char *str, int *char_cnt)
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
		{
			if (*i < 0)
				flags->width -= 1;
			*char_cnt = ft_treat_width(flags->width,
					flags->prec_val, 1, *(&char_cnt));
		}
	}
	return (*char_cnt);
}

int	ft_treat_d_i(va_list ap, t_flag *flags)
{
	int		char_count;
	int		i;
	char	*str;

	char_count = 0;
	i = ft_conv_args_i(ap, flags);
	str = ft_itoa(i);
	if (flags->minus)
		char_count = put_prec(flags, &i, &str, &char_count);
	if (flags->width && flags->zero && !flags->dot)
	{
		if (i < 0)
			flags->width -= 1;
		flags->prec_val = flags->width;
		flags->width = 0;
		char_count = put_prec(flags, &i, &str, &char_count);
		free(str);
		return (char_count);
	}
	char_count = handle_width_d_i(flags, &i, str, &char_count);
	if (!flags->minus)
		char_count = put_prec(flags, &i, &str, &char_count);
	if (str)
		free(str);
	return (char_count);
}
