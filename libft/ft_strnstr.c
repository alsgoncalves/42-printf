/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:50:16 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/15 15:30:07 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t catch;

	i = 0;
	j = 0;
	catch = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (needle[j] && haystack[i] == needle[j])
		{
			catch++;
			i++;
			j++;
		}
		if (j == ft_strlen(needle))
			return ((char *)haystack + (i - catch));
		i++;
	}
	return (NULL);
}
