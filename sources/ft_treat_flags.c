/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:12:26 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 13:17:13 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_flags(va_list ap, t_flag *flags)
{
	if (flags->type == 'c')
		return (ft_treat_char(ap, flags, 'c'));
	if (flags->type == 's')
		return (ft_treat_str(ap, flags));
	if (flags->type == 'p')
		return (ft_treat_pointer(ap, flags, 'x'));
	if (flags->type == 'd')
		return (ft_treat_d_i(ap, flags));
	if (flags->type == 'i')
		return (ft_treat_d_i(ap, flags));
	if (flags->type == 'u')
		return (ft_treat_u(ap, flags));
	if (flags->type == 'x')
		return (ft_treat_x(ap, flags, 'x'));
	if (flags->type == 'X')
		return (ft_treat_x(ap, flags, 'X'));
	if (flags->type == '%')
		return (ft_treat_char(ap, flags, '%'));
	return (0);
}
