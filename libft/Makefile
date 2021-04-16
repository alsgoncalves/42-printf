# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asobreir <asobreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 16:43:30 by asobreir          #+#    #+#              #
#    Updated: 2021/04/16 13:28:25 by asobreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRCS= ft_itoa.c \
	  		ft_memset.c \
	  		ft_calloc.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_substr.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_utoa.c \

OBJS= ${SRCS:.c=.o}

CC=	gcc

FLAGS= -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re

