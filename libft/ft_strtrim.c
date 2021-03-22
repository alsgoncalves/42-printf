/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:47:35 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/16 11:48:38 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_char_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed_str;

	start = 0;
	end = ft_strlen(s1);
	while (is_char_set(s1[start], set) && s1[start])
		start++;
	while (is_char_set(s1[end - 1], set) && end > start)
		end--;
	trimmed_str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (trimmed_str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed_str[i] = s1[start];
		start++;
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
