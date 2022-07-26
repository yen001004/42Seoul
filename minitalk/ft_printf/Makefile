# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 12:49:33 by yewolee           #+#    #+#              #
#    Updated: 2022/07/13 15:22:34 by yewolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
LIB = Libft
TARGETS = ft_printf.c ft_format1.c ft_format2.c ft_utils.c
OBJECTS = ${TARGETS:.c=.o}
LIB_SRCS = Libft/ft_itoa.c Libft/ft_atoi.c Libft/ft_strlen.c
LIB_OBJS = Libft/ft_itoa.o Libft/ft_atoi.o Libft/ft_strlen.o
INCLUDE = ft_printf.h
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJECTS} ${LIB_OBJS}
	ar -rc $@ $^

.o: .c
	${CC} ${CFLAGS} -c $< -o $@ -include ${INCLUDE}

${LIB_OBJS}: ${LIB_SRCS}
	make -C ${LIB} all

clean:
	make -C ${LIB} clean
	rm -f ${OBJECTS}

fclean: clean
	make -C ${LIB} fclean
	rm -f ${NAME}

re: fclean all
