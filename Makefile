# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 12:16:48 by asobreir          #+#    #+#              #
#    Updated: 2021/03/30 17:15:06 by asobreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

CC = gcc

FLAGS := -Wall -Wextra -Werror -g

RM = rm -f

SRCS = ft_printf.c \
			$(wildcard sources/*.c)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	${CC} ${FLAGS} -c -o $@ $< 

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean: $(OBJS)
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME) 
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
