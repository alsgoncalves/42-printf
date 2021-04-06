/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:28:15 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/06 12:02:55 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_width(int width, int minus, int has_zero, int *char_count)
{
	int temp;

	temp = *char_count;
	if (minus < 0)
		return (*char_count);
	while (width - minus > 0)
	{	
		if (has_zero == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		temp++;
		width--;
	}
	*char_count = temp;
	return (*char_count);
}