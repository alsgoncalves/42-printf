/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:31:10 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/28 16:17:34 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

#include "../libft/libft.h"

#include <stdio.h> // To be removed

typedef	struct	s_flag
{
	int		width;
	int		zero;
	int		minus;
	int		width_star;
	int		dot;
	int		precision_value;
	int		precision_star;
	char	type;
}				t_flag;

int		ft_treat_flags(va_list ap, t_flag *flags);
int		ft_treat_char(va_list ap, t_flag *flags);
int		ft_treat_width(int width, int minus, int has_zero, int *char_count);
int		is_num(char c);
int     char_to_int(char *str, int *n);
t_flag  ft_initialize_flags(void);
char    ft_check_type(char c);
int     ft_check_flags(const char *format, t_flag *flags);
int		ft_printf(const char *format, ...);
int		ft_treat_str(va_list ap, t_flag *flags);
int		ft_treat_precision(int precision, char *str, int *char_count);
void	ft_convert_stars(t_flag *flags, va_list ap);
int 	ft_treat_d(va_list ap, t_flag *flags);

#endif
