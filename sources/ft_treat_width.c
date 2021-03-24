/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:28:15 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/24 12:31:29 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int		ft_treat_width(int width, int minus, int has_zero, int *char_count)
{
	int temp;

	temp = *char_count;
	while (width - minus)
	{	
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		temp++;
		width--;
	}
	*char_count = temp;
	return (*char_count);
}