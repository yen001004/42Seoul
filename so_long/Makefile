# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 15:11:43 by yewolee           #+#    #+#              #
#    Updated: 2022/06/29 18:48:42 by yewolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
TARGETS = src/main.c src/init.c src/map.c src/so_long_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJECTS = ${TARGETS:.c=.o}
INCLUDE = so_long.h gnl/get_next_line.h
CFLAGS = -Wall -Wextra -Werror
MLX	= mlx_opengl
NAME = so_long

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJECTS}
	make -C ${MLX}
	${CC} ${CFLAGS} -o $@ $^ -L ${MLX} -lmlx -framework OpenGL -framework AppKit

.o: .c
	${CC} ${CFLAGS} -c $< -o $@ -include ${INCLUDE}

clean:
	make clean -C ${MLX}
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all
