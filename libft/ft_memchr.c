/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:59:52 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/11 13:43:27 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*pointer;
	size_t			i;

	pointer = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		if (*(pointer + i) == (unsigned char)c)
		{
			pointer = (pointer + i);
			return (pointer);
		}
		i++;
	}
	return (NULL);
}
