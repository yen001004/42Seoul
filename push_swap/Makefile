# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 14:50:39 by yewolee           #+#    #+#              #
#    Updated: 2022/08/25 16:36:40 by yewolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
TARGETS = check_arg.c free_stack.c ft_atoi.c get_min_and_max.c \
		  init_sorted.c init_stack.c operation_push.c operation_reverse.c \
		  operation_rotate.c operation_swap.c push_swap.c \
		  set_operation1.c set_operation2.c set_operation3.c \
		  sort_a_b.c sort_b_a.c sort_five.c sort_two_and_three.c sort_utils.c
OBJECTS = ${TARGETS:.c=.o}
INCLUDE = push_swap.h
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} -o $@ $^

.o: .c
	${CC} ${CFLAGS} -c $< -o $@ -include ${INCLUDE}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

