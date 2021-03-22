# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 12:16:48 by asobreir          #+#    #+#              #
#    Updated: 2021/03/22 15:33:27 by asobreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

CC = gcc

FLAGS := -Wall -Wextra -Werror

RM = rm -f

SRCS := $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	${CC} ${FLAGS} -I includes $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: $(OBJS)
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME) 
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
