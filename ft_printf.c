/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:49:08 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/12 17:15:13 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_printf.h"

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
	flags.minus = 0;
	flags.width_star = 0;
	flags.dot = 0;
	flags.precision_value = -1;
    flags.precision_star = 0;
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
        else if (format[i] == '0')
            flags->zero = 1;
        else if (format[i] == '*' && !flags->dot)
            flags->width_star = 1;
        else if (is_num(format[i]))
        {
            flags->width = char_to_int((char *)format, &i);
            //printf("WIDTH %i\n", flags->width);
        }
        if (format[i] == '.' && format[i + 1])
        {
            flags->dot = 1;
            if (format[i + 1] == '*')
                flags->precision_star = 1;
            else
            {
                i++;
                flags->precision_value = char_to_int((char *)format, &i);
                //printf("PREC %i\n", flags->precision_value);
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
    //printf("\nCHAR COUNT IN PRINTF : %i\n", i);
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
            format++;
            while (*format != flags.type)
            {
                format++;
            }
            char_count += ft_treat_flags(ap, &flags);
            // printf("ZERO = %i\n", flags.zero);
            // printf("MINUS = %i\n", flags.minus);
            // printf("TYPE = %c\n", flags.type);
            // printf("DOT = %i\n", flags.dot);
            // printf("Precision = %i\n", flags.precision_value);
            // printf("Width = %i\n", flags.width);
            // printf("Precison_star = %i\n", flags.precision_star);
            // printf("width_star = %i\n", flags.width_star);
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
    // To return total number of chars displayed by printf
    return (char_count);
}

// int main()
// {
//     char *str;

//     str = "beautiful";
//     ft_printf("RL : Today is a %-10s day\n");
//     printf("\n\n");
//     ft_printf("RL : Today is a %.200s day\n");
//     printf("\n\n");
//     ft_printf("RL : Today is a %*.*s day\n");
// }
