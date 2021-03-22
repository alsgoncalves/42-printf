/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:25:00 by asobreir          #+#    #+#             */
/*   Updated: 2021/01/20 15:26:42 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	int				src_count;
	unsigned int	dest_count;
	unsigned int	aux;

	aux = 0;
	src_count = 0;
	dest_count = 0;
	while (src[src_count])
		src_count++;
	if (size == 0)
		return (src_count);
	while (dest[dest_count])
		dest_count++;
	if (size <= dest_count)
		return (size + src_count);
	while (size && (--size - dest_count) && src[aux])
	{
		dest[dest_count + aux] = src[aux];
		aux++;
	}
	dest[dest_count + aux] = '\0';
	return (src_count + dest_count);
}
