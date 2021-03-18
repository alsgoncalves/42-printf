#include "ft_printf.h"

#include <stdio.h> // to be removed

int is_num(char c)
{
    if ((c >= '0' && c <= '9') || c == '%')
        return (1);
    return (0);
}

int     char_to_int(char *str)
{
    int num;
    int i;

    i = 0;
    num = 0;
    while (str[i])
    {
        if (is_num(str[i]))
        {
            num += str[i] - '0';
            while (is_num(str[i + 1]))
            {
                num = (num * 10) + (str[i + 1]- '0');
                i++;
            }
            i++;
        }
        i++;
    }
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
	flags.star_location = 0;
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

void     ft_check_flags(const char *format, t_flag *flags)
{
    //flags = ft_initialize_flags();

    while (*format)
    {   
        if (*format == '-')
            flags->minus = 1;
        else if (*format == '+')
            flags->plus = 1;
        else if (*format == '0')
            flags->zero = 1;
        else if (is_num(*format))
            flags->width = char_to_int((char*)format);
        else if (*format == '.' && (*format + 1))
        {
            flags->dot = 1;
            flags->precision_value =  char_to_int((char*)format + 1);
            format++;
        }
        else if (ft_check_type(*format))
        {
            flags->type = *format;
            break ;
        }
        format++;
    }
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
            ft_check_flags((format + 1), &flags);
        }
        else
        {
            write(1, format, 1);
            char_count++;
        }
        format++;
    }
    
    printf("ZERO = %i\n", flags.zero);
    printf("MINUS = %i\n", flags.minus);
    printf("PLUS = %i\n", flags.plus);
    printf("TYPE = %c\n", flags.type);
    va_end(ap);
    // To return total number of chars displayed by printf
    return (char_count);
}

int main()
{
    // char a;
    //t_flag flags;
    //  int num;
    //  int i;
    //char *str;

    // i = 0;
    //  num = 0;
    //str = "Hello beautiful day";
    // // flags = ft_initialize_flags();
    // // a = ft_check_type(str, flags);
    // // printf("Printing a : %c\n", a);
    
    // num = char_to_int(str);
    // printf("%i\n", num);
    // printf("%i\n", 130999870098765);
    // //printf("%.7896f\n", num);
    ft_printf("Bea %-050s hey + hey");
    
    return 0;
}