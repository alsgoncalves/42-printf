/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:31:10 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/13 11:34:49 by asobreir         ###   ########.fr       */
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


int	is_num(char c);
int	char_to_int(char *str, int *n);
int		ft_treat_flags(va_list ap, t_flag *flags);
int		ft_treat_char(va_list ap, t_flag *flags, char a);
int		ft_treat_width(int width, int minus, int has_zero, int *char_count);
int		is_num(char c);
t_flag  ft_initialize_flags(void);
char    ft_check_type(char c);
void     ft_check_flags(const char *format, t_flag *flags);
int		ft_printf(const char *format, ...);
int		ft_treat_str(va_list ap, t_flag *flags);
int		ft_treat_precision(int precision, char *str, int *char_count);
void	ft_convert_stars(t_flag *flags, va_list ap);
int 	ft_treat_d_i(va_list ap, t_flag *flags);
void	flag_conversions(t_flag *flags);
// int 	conv_neg_prec(char *str, int *i, int *char_count);
// int		put_prec(t_flag *flags, int *i, char *str, int *char_count);
// int		handle_width_d_i(t_flag *flags, int *i, char *str, int *char_count);
int 	ft_treat_u(va_list ap, t_flag *flags);
int		handle_width_u(t_flag *flags, unsigned int *i, char *str, int *char_count);
int		put_prec_u(t_flag *flags, unsigned int *i, char *str, int *char_count);
int 	conv_neg_prec_u(char *str, unsigned int *i, int *char_count);
int 	ft_treat_x(va_list ap, t_flag *flags, char a);
//char	*ft_xtoa(unsigned int n, char a);
char	*ft_xtoa(unsigned int n, char a);
int		ft_treat_p(va_list ap, t_flag *flags, char a);

#endif
