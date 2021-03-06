# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 12:16:48 by asobreir          #+#    #+#              #
#    Updated: 2021/04/16 18:33:17 by asobreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

CC = gcc

FLAGS := -Wall -Wextra -Werror -g -I includes

RM = rm -f

SRCS = ft_printf.c \
			$(wildcard sources/*.c)

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	${CC} ${FLAGS} -c -o $@ $< 

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
