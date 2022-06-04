# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:07:58 by yewolee           #+#    #+#              #
#    Updated: 2022/03/23 14:18:44 by yewolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
TARGETS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
TARGETS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = ${TARGETS:.c=.o}
OBJECTS_B = ${TARGETS_B:.c=.o}
INCLUDE	= libft.h
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a

ifdef WITH_BONUS
	OBJS = ${OBJECTS} ${OBJECTS_B}
else
	OBJS = ${OBJECTS}
endif

.PHONY: all clean fclean re bonus

all:	${NAME}

${NAME}:	${OBJS}
	ar -rc $@ $^

bonus:
	make WITH_BONUS=1 all

.o:	.c
	${CC} ${CFLAGS} -c $< -o $@ -include ${INCLUDE}

clean:
	rm -f ${OBJECTS}
	rm -f ${OBJECTS_B}

fclean: clean
	rm -f ${NAME}

re:	fclean all
