# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 19:53:40 by yewolee           #+#    #+#              #
#    Updated: 2023/01/12 19:21:55 by yewolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
TARGETS = philo_init.c philo_monitor.c philo_print.c \
			philo_thread.c philo_time.c \
			philo_utils.c philosopher.c
OBJECTS = ${TARGETS:.c=.o}
INCLUDE = philosopher.h
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
NAME = philo

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
