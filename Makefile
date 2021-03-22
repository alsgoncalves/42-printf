# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 12:16:48 by asobreir          #+#    #+#              #
#    Updated: 2021/03/22 14:01:13 by asobreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS := -Wall -Wextra -Werror

RM = rm -f

SRCS := $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean: $(OBJS)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: clean fclean
