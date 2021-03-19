#include "ft_printf.h"


void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int    ft_treat_width(t_flag *flags, int *char_count)
{ 
	int temp;

	temp = *char_count;
	while (flags->width - 1 > 0)
	{
		ft_putchar(' ');
		temp++;
		flags->width--;
	}
	*char_count = temp;
	return (*char_count);
}

int ft_treat_char(va_list ap, t_flag *flags)
{
	int char_count;
	char c;

	char_count = 0;
	if (flags->minus && flags->width)
	{
		c = va_arg(ap, int);
		ft_putchar(c);
		char_count++;
		char_count = ft_treat_width(flags, &char_count);
	}
	if (flags->width && flags->minus == 0)
	{
		c = va_arg(ap, int);
		char_count = ft_treat_width(flags, &char_count);
		ft_putchar(c);
		char_count++;
	}
	if (flags->star)
	{
		flags->width = va_arg(ap, int);
		char_count = ft_treat_width(flags, &char_count);
		c = va_arg(ap, int);
		ft_putchar(c);
		char_count++;
	}
	return (char_count);
}