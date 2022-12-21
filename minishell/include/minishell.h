/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:15:15 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/26 14:41:11 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>

# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define ENV_GET 0
# define ENV_EXPORT 1
# define ENV_UNSET 2
# define ENV_ALL 3
# define ENV_QUESTION_MARK 4

# define LEFT_EXEC 1
# define RIGHT_EXEC 2

typedef struct s_node
{
	char			*name;
	char			*value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_tlist{
	t_node	*head;
	t_node	*tail;
	int		cnt;
}	t_deque;

typedef struct s_block {
	char			*value;
	t_deque			tokens;
	struct s_block	*next;
	struct s_block	*prev;
}	t_block;

typedef struct s_blocklist {
	t_block	*head;
	t_block	*tail;
	int		cnt;
}	t_blocklist;

typedef struct s_pipefd {
	int	in;
	int	out;
}	t_pipefd;

// signal_setting.c
void	sig_handler(int signal);
void	set_signal(void);
int		flag_set_test(int set_flag, int test);
int		flag_set_test2(int set_flag, int test);

// ft_malloc.c
void	free_t_node(t_node *p);
void	*ft_malloc(size_t size);
void	ft_double_free(char **strs);
void	null_check_exit(void *p);

// ft_split_argv
char	**ft_split_argv(char const *s, char c);

// ft_split_argv_utils
int		word_len_argv(char const *str, char c);
int		word_len2_argv(char const *str, char c);
int		word_count_argv(char const *str, char c);
char	*word_copy_argv(char const *str, int len);

//linked_list_utils1.c
t_node	*make_node(char *key, char *value);
void	append_head(t_deque *deque, t_node *new_node);
void	append_tail(t_deque *deque, t_node *new_node);
int		del_tail(t_deque *deque);
void	init_deque(t_deque *deque);

//linked_list_utils2.c
void	print_all_node(t_deque *deque);
void	free_all_node(t_deque *deque);
t_node	*find_node(t_deque *deque, char *key);
int		del_node(t_deque *deque, char *key);

// replace_env_variable.c
int		is_val_quote(char const *str, char c);
void	str_push(char *dst, char *src, int cnt);
char	*replace_env_variable(char *str);

// env_manage.c
void	*env_manage(int action, char *name, char *value);

// env_manage_utils.c
char	*get_env_by_key(t_deque *envs, char *key);
void	export_env_update(char *key, char *value, t_node *node);
void	export_env_append(t_deque *envs, char *key, char *value);
void	unset_env(t_deque *envs, char *key);

// init_envs.c
void	init_envs(t_deque	*envs);

// lexer.c
void	lexer_blocks(t_blocklist *blocks);

// excute_block.c
int		return_execute(t_deque *tokens, int child_flag);
int		execute_block(t_block *p, t_deque *tokens);
int		execute_all_blocks(t_blocklist *blocks);

// execute_block_utils.c
int		child_execute_check(t_deque *tokens, int redir);
int		normal_execute_check(t_deque *tokens, int redir);
int		child_execute(t_deque *tokens);
int		normal_execute(t_deque *tokens);
int		return_execute(t_deque *tokens, int child_flag);

// execute_block_utils2.c
int		redir_execute(t_deque *tokens);

// builtins
int		builtins_echo(t_deque *tokens);
int		builtins_cd(t_deque *tokens);
int		builtins_pwd(void);
int		builtins_export(t_deque *tokens);
int		builtins_unset(t_deque *tokens);
int		builtins_env(void);
int		builtins_exit(t_deque *tokens);

// block_list_utils1.c
t_block	*make_block(char *value);
void	append_block_head(t_blocklist *blocklist, t_block *new_block);
void	append_block_tail(t_blocklist *blocklist, t_block *new_block);
int		del_block_tail(t_blocklist *blocklist);
void	init_blocklist(t_blocklist *blocklist);

// block_list_utils2.c
void	print_all_block(t_blocklist *blocklist);
void	free_all_block(t_blocklist *blocklist);

// get_exec_blocks.c
void	get_exec_blocks(t_blocklist *blocks, char *line);

// init_tokens.c
void	init_tokens(t_block *block);

// exec_etc.c
int		exec_etc(t_deque *tokens);

// exec_etc_child.c
void	exec_etc_child(t_deque *tokens, int i);

// exec_etc_utils.c
void	get_argv(char **argv, t_deque *tokens);
void	get_envp(char **envp, t_deque *envs);
int		redir_cnt(t_deque *tokens);

// redirection.c
int		redirection_execute(t_deque *tokens);

// redirection_heredoc.c
char	*make_temp_file(void);
void	readline_heredoc(t_node *p, int new_fd);
int		heredoc(t_node *p, int *infd);

// redirection_utils1.c
void	del_redir(t_deque *tokens);
int		check_redirection(char **str);
int		redir_one_or_two(char *str, int redir_idx);

// redirection_utils2.c
int		get_redir_num(char *value);
int		input_redirection(t_node *p, int *infd);
int		output_redirection(t_node *p, int *outfd);
int		output_append_redirection(t_node *p, int *outfd);
char	*remove_quote(char *str);

// pipe.c
int		pipe_left(t_deque *tokens, int *pipefd);
void	pipe_right(t_block *p, t_deque *tokens);

// wexitstatus.c
int		wexitstatus_custom(int w);

// error_check.c
int		no_error_on_parse(t_blocklist *blocks);

// error_check2.c
int		check_empty_line(t_block *p);

#endif
