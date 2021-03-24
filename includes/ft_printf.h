/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:31:10 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/24 12:31:33 by asobreir         ###   ########.fr       */
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
	int		plus;
	int		minus;
	int		star;
	int		dot;
	int		precision_value;
	char	type;
}				t_flag;

int		ft_treat_flags(va_list ap, t_flag *flags);
int		ft_treat_char(va_list ap, t_flag *flags);
void    ft_putchar(char c);
int		ft_treat_width(int width, int minus, int has_zero, int *char_count);
int		is_num(char c);
int     char_to_int(char *str, int *n);
t_flag  ft_initialize_flags(void);
char    ft_check_type(char c);
int     ft_check_flags(const char *format, t_flag *flags);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_treat_str(va_list ap, t_flag *flags);

#endif
