/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:49:08 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/13 11:36:03 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flag	ft_initialize_flags(void)
{
	t_flag	flags;

	flags.width = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.width_star = 0;
	flags.dot = 0;
	flags.precision_value = -1;
	flags.precision_star = 0;
	flags.type = 0;
	return (flags);
}

char	ft_check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

void	ft_check_flags(const char *format, t_flag *flags)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '*' && !flags->dot)
			flags->width_star = 1;
		else if (is_num(format[i]))
			flags->width = char_to_int((char *)format, &i);
		if (format[i] == '.' && format[i + 1])
		{
			flags->dot = 1;
			if (format[i + 1] == '*')
				flags->precision_star = 1;
			else
			{
				i++;
				flags->precision_value = char_to_int((char *)format, &i);
				i--;
			}
		}
		else if (ft_check_type(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_flag	flags;
	int		char_count;
	va_list	ap;

	char_count = 0;
	i = 0;
	flags = ft_initialize_flags();
	va_start(ap, (char *)format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_check_flags((format + 1), &flags);
			format++;
			while (*format != flags.type)
				format++;
			char_count += ft_treat_flags(ap, &flags);
			flags = ft_initialize_flags();
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}
		format++;
	}
	va_end(ap);
	return (char_count);
}
