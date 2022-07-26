# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 13:16:44 by yewolee           #+#    #+#              #
#    Updated: 2022/07/13 16:06:29 by yewolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
SERVER_TARGETS = src/server.c 
CLIENT_TARGETS = src/client.c
SERVER_OBJECTS	= ${SERVER_TARGETS:.c=.o}
CLIENT_OBJECTS	= ${CLIENT_TARGETS:.c=.o}
INCLUDE	= include/minitalk.h
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= server
NAME2 	= client
FT_PRINTF	= ft_printf

.PHONY: all clean fclean re

all: ${NAME} ${NAME2}

${NAME}: ${SERVER_OBJECTS}
	make -C ${FT_PRINTF} all
	${CC} ${CFLAGS} -o $@ $^ -L${FT_PRINTF} -lftprintf -include ${INCLUDE}

${NAME2}: ${CLIENT_OBJECTS}
	${CC} ${CFLAGS} -o $@ $^ -L${FT_PRINTF} -lftprintf -include ${INCLUDE}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make clean -C ${FT_PRINTF}
	rm -f ${SERVER_OBJECTS}
	rm -f ${CLIENT_OBJECTS}

fclean: clean
	make fclean -C ${FT_PRINTF}
	rm -f ${NAME}
	rm -f ${NAME2}

re: fclean all
