/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:31:10 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/17 11:40:18 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef	struct	s_flag
{
	int		width;
	int		zero;
	int		plus;
	int		minus;
	int		star;
	int		dot;
	int		precision_value;
	char	type;
}				t_flag;

#endif
