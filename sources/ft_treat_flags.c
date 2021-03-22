/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:12:26 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/22 15:42:29 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_treat_flags(va_list ap, t_flag *flags)
{
    if (flags->type == 'c')
        return (ft_treat_char(ap, flags));
    if (flags->type == 's') 
		return (ft_treat_str(ap, flags));
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

