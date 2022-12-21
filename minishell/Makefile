CC	=	cc
SRCS =	src/main.c\
		src/signal_setting.c \
		src/ft_split_argv.c \
		src/ft_split_argv_utils.c \
		src/linked_list_utils1.c src/linked_list_utils2.c \
		src/ft_malloc.c \
		src/replace_env_variable.c \
		src/env_manage.c src/env_manage_utils.c \
		src/init_envs.c \
		src/get_exec_blocks.c \
		src/block_list_utils1.c src/block_list_utils2.c \
		src/init_tokens.c \
		src/lexer.c \
		src/execute_block.c \
		src/execute_block_utils.c src/execute_block_utils2.c \
		src/builtins/builtins_echo.c src/builtins/builtins_cd.c src/builtins/builtins_pwd.c \
		src/builtins/builtins_export.c src/builtins/builtins_unset.c src/builtins/builtins_env.c src/builtins/builtins_exit.c \
		src/exec/exec_etc.c src/exec/exec_etc_child.c src/exec/exec_etc_utils.c \
		src/exec/redirection.c src/exec/redirection_heredoc.c \
		src/exec/redirection_utils1.c src/exec/redirection_utils2.c \
		src/pipe/pipe.c \
		src/utils/wexitstatus.c \
		src/error_check.c src/error_check2.c
OBJS = ${SRCS:.c=.o}

LIBFT_DIR	= ./libft
LIBFT_LIB	= -L $(LIBFT_DIR) -lft


CFLAGS	= -Wall -Wextra -Werror
COMFILE_FLAGS = -lreadline -L/$(shell brew --prefix readline)/lib
OBJ_FLAGS = -I/$(shell brew --prefix readline)/include
HEADER	= -include include/minishell.h
NAME	= minishell

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS} ${LIB_OBJS}
	make -C $(LIBFT_DIR)
	${CC} ${CFLAGS} ${HEADER} ${COMFILE_FLAGS} $(LIBFT_LIB) -o $@ $^

%.o: %.c
	${CC} ${CFLAGS} ${OBJ_FLAGS} -c $< -o $@

clean:
	make -C ${LIBFT_DIR} clean
	rm -f ${OBJS}

fclean: clean
	make -C ${LIBFT_DIR} fclean
	rm -f ${NAME}

re: fclean all
