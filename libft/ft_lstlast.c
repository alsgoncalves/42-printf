/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:56:03 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/23 11:59:01 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temporary;
	
	if (lst != NULL)
		temporary = lst;
	else
		return (NULL);
	while (temporary->next != NULL)
		temporary = temporary->next;
	return (temporary);
}
