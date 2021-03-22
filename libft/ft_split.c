/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:56:37 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/05 11:32:03 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

bool			char_is_separator(char s, char c)
{
	if (s == c)
		return (true);
	if (s == '\0')
		return (true);
	return (false);
}

long long		ft_word_count(const char *str, char c)
{
	long long w_count;
	long long i;

	i = 0;
	w_count = 0;
	while (str[i] != 0)
	{
		while (!char_is_separator(str[i], c))
			i++;
		if (!char_is_separator(str[i - 1], c))
			w_count++;
		if (str[i] == 0)
			return (w_count);
		i++;
	}
	return (w_count);
}

char			**ft_split(char const *str, char c)
{
	int		i;
	char	**arr_of_strs;
	char	*str_copy;

	i = 0;
	if (!(arr_of_strs = malloc((ft_word_count(str, c) + 1) * sizeof(char *))))
		return (0);
	while (*str)
	{
		str_copy = (char *)str;
		while (!char_is_separator(*str, c))
			str++;
		if (str_copy != str)
		{
			arr_of_strs[i] = malloc((str - str_copy + 1) * sizeof(char));
			if (!arr_of_strs[i])
				return (NULL);
			ft_strlcpy(arr_of_strs[i], str_copy, str - str_copy + 1);
			i++;
		}
		if (*str)
			str++;
	}
	arr_of_strs[i] = 0;
	return (arr_of_strs);
}
