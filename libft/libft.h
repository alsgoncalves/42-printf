/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:46:18 by asobreir          #+#    #+#             */
/*   Updated: 2021/04/16 14:53:38 by asobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_utoa(unsigned int n);
void			*ft_memset(void *str, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strdup(char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);

#endif
