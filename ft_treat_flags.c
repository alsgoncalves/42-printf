#include "ft_printf.h"

int ft_treat_flags(va_list ap, t_flag *flags)
{
    if (flags->type == 'c')
        return (ft_treat_char(ap, flags));
    // if (flags->type == 's') 
    //     //
	// if (flags->type == 'p')
	// 	//
	// if (flags->type == 'd')
	// 	//
	// if (flags->type == 'i')
	// 	//
	// if (flags->type == 'u')
	// 	//
	// if (flags->type == 'x')
	// 	//
	// if (flags->type == 'X')
	// 	//
	// if (flags->type == '%')
	// 	//
	return (0);
}
