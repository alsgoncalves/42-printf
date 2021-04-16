/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:31:10 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 16:25:29 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_flag
{
	int		width;
	int		zero;
	int		minus;
	int		width_star;
	int		dot;
	int		prec_val;
	int		precision_star;
	char	type;
}				t_flag;

int		is_num(char c);
char	ft_check_type(char c);
int		char_to_int(char *str, int *n);
int		ft_treat_flags(va_list ap, t_flag *flags);
int		ft_treat_char(va_list ap, t_flag *flags, char a);
int		ft_treat_width(int width, int minus, int has_zero, int *char_count);
int		is_num(char c);
t_flag	ft_initialize_flags(void);
char	ft_check_type(char c);
void	ft_check_flags(const char *format, t_flag *flags);
int		ft_printf(const char *format, ...);
int		ft_treat_str(va_list ap, t_flag *flags);
int		ft_treat_prec(int precision, char *str, int *char_count);
void	ft_convert_stars(t_flag *flags, va_list ap);
int		ft_treat_d_i(va_list ap, t_flag *flags);
void	flag_conversions(t_flag *flags);
int		ft_treat_u(va_list ap, t_flag *flags);
int		handle_width_u(t_flag *flags,
			unsigned int *i, char *str, int *char_cnt);
int		put_prec_u(t_flag *flags, unsigned int *i, char *str, int *char_count);
int		conv_neg_prec_u(char *str, unsigned int *i, int *char_count);
int		ft_treat_x(va_list ap, t_flag *flags, char a);
char	*ft_xtoa(unsigned long n, char a);
int		ft_treat_pointer(va_list ap, t_flag *flags, char a);
int		ft_conv_args_i(va_list ap, t_flag *flags);
void	ft_flag_conversions(t_flag *flags);

#endif
