/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:53:43 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 14:44:01 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (s_len - start < len)
		substring = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else if (s_len < start)
		substring = (char *)malloc(sizeof(char) * (s_len + 1));
	else
		substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len && i + start < ft_strlen(s))
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
