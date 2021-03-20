/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:49:08 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/20 14:41:21 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

#include <stdio.h> // to be removed

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int     char_to_int(char *str, int *n)
{
    int num;
    int i;

    i = *n;
    num = 0;
    while (str[i])
    {
        if (is_num(str[i]))
        {
            num += str[i] - '0';
            while (is_num(str[i + 1]))
            {
                num = (num * 10) + (str[i + 1] - '0');
                i++;
            }
        }
        if (!is_num(str[i]))
            break ;
        i++;
    }
    *n = i;
    return (num);
}

t_flag  ft_initialize_flags(void)
{
    t_flag flags;

    flags.width = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.star = 0;
	flags.dot = 0;
	flags.precision_value = -1;
	flags.type = 0;
    return(flags);
}

char    ft_check_type(char c)
{
    if (c == 'c' || c == 's' || c == 'p' 
            || c == 'd' || c == 'i' || c == 'u'
                || c == 'x' || c == 'X' || c == '%')
        return (c);
    return (0);
}

int     ft_check_flags(const char *format, t_flag *flags)
{
    int i;

    i = 0;
    while (format[i])
    {   
        if (format[i] == '-')
            flags->minus = 1;
        if (format[i] == '+')
            flags->plus = 1;
        if (format[i] == '0' && flags->width == 0)
            flags->zero = 1;
        if (format[i] == '*')
            flags->star = 1;
        if (is_num(format[i]))
            flags->width = char_to_int((char *)format, &i);
        if (format[i] == '.' && format[i + 1])
        {
            flags->dot = 1;
            i++;
            flags->precision_value =  char_to_int((char *)format, &i);
        }
        if (ft_check_type(format[i]))
        {
            flags->type = format[i];
            break ;
        }
        i++;
    }
    return (i);
}


int ft_printf(const char *format, ...)
{
    int i;
    t_flag flags;
    int char_count;
    va_list ap;

    char_count = 0;
    i = 0;
    flags = ft_initialize_flags();
    va_start(ap, (char *)format);
    // calculate char_count
    while (*format)
    {
        if (*format == '%')
        {
            i = ft_check_flags((format + 1), &flags);
            while (*format != flags.type)
            {
                format++;
            }
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
    
    // printf("ZERO = %i\n", flags.zero);
    // printf("MINUS = %i\n", flags.minus);
    // printf("PLUS = %i\n", flags.plus);
    // printf("TYPE = %c\n", flags.type);
    // printf("DOT = %i\n", flags.dot);
    // printf("Precision = %i\n", flags.precision_value);
    // printf("Width = %i\n", flags.width);
    va_end(ap);
    // To return total number of chars displayed by printf
    return (char_count);
}
