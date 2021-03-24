/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:49:09 by asobreir          #+#    #+#             */
/*   Updated: 2021/03/24 15:35:41 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int char_count;

	char_count = 0;
	while (*s)
	{
		write(1, s, 1);
		char_count++;
		s++;
	}
	return (char_count);
}
