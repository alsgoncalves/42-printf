/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:47:37 by asobreir          #+#    #+#             */
/*   Updated: 2021/02/24 12:49:18 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *p_list_next;
	t_list *p_new_list;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew((*f)(lst->content))))
		return (NULL);
	p_new_list = new_list;
	p_list_next = lst->next;
	while (true)
	{
		if (p_list_next == NULL)
			break ;
		if (!(p_new_list->next = ft_lstnew((*f)(p_list_next->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		p_new_list = p_new_list->next;
		p_list_next = p_list_next->next;
	}
	return (new_list);
}
