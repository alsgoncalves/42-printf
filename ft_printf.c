/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:49:08 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 16:27:47 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_initialize_flags(void)
{
	t_flag	flags;

	flags.width = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.width_star = 0;
	flags.dot = 0;
	flags.prec_val = -1;
	flags.precision_star = 0;
	flags.type = 0;
	return (flags);
}

int	ft_save_flags(const char *format, t_flag *flags, int *n)
{
	int	i;

	i = *n;
	if (format[i] == '-')
		flags->minus = 1;
	else if (format[i] == '0')
		flags->zero = 1;
	else if (format[i] == '*' && !flags->dot)
		flags->width_star = 1;
	else if (is_num(format[i]))
		flags->width = char_to_int((char *)format, &i);
	*n = i;
	return (*n);
}

void	ft_check_flags(const char *format, t_flag *flags)
{
	int	i;

	i = 0;
	while (format[i])
	{
		i = ft_save_flags(format, flags, &i);
		if (format[i] == '.' && format[i + 1])
		{
			flags->dot = 1;
			i++;
			if (format[i] == '*')
				flags->precision_star = 1;
			else
				flags->prec_val = char_to_int((char *)format, &i);
			i--;
		}
		if (ft_check_type(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
}

int	ft_treat_fmt(const char *format, t_flag *flags, va_list ap, int *char_cnt)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_flags((format), flags);
			while (*format != flags->type)
				format++;
			*char_cnt += ft_treat_flags(ap, flags);
			*flags = ft_initialize_flags();
		}
		else
		{
			write(1, format, 1);
			(*char_cnt)++;
		}
		format++;
	}
	return (*char_cnt);
}

int	ft_printf(const char *format, ...)
{
	t_flag	flags;
	int		char_count;
	va_list	ap;

	char_count = 0;
	flags = ft_initialize_flags();
	va_start(ap, (char *)format);
	char_count = ft_treat_fmt(format, &flags, ap, &char_count);
	va_end(ap);
	return (char_count);
}
