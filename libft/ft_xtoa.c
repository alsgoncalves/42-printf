/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:40:35 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/07 16:35:35 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int		n_length(int n)
// {
// 	int length;

// 	length = 0;
// 	if (n % 10 >= 0)
// 		length++;
// 	while (n /= 10)
// 		length++;
// 	return (length);
// }

char	*ft_print_n(int n)
{
	
    int             i;
    int             j;
    int             temp;
    char            hexadecimalNum[100];

    i = 0;
    while (n != 0)
    {
        temp = n % 16;
        if (temp < 10)
            hexadecimalNum[i++] = temp + 48;
        else 
            hexadecimalNum[i++] = temp + 55;
        n /= 16;
    }
    //temp = 0;
    j = 0;
    while (i != ((int)ft_strlen(hexadecimalNum)/2))
    {
        temp = hexadecimalNum[i];
        hexadecimalNum[i] = hexadecimalNum[j];
        hexadecimalNum[j] = temp;
        i--;
        j++;
    }
	return (hexadecimalNum);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == (-2147483647 - 1))
		return (ft_strdup("-2147483648"));
	return (ft_print_n(n));
}