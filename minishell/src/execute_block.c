/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:13:49 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 20:10:46 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dup2_and_close(int left, int right)
{
	dup2(left, right);
	close(left);
}

void	fork1_exec(t_deque *tokens, int pipefd[2], int *status)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(-1);
	else if (pid == 0)
		exit(pipe_left(tokens, pipefd));
	else
	{
		dup2_and_close(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		waitpid(pid, status, 0);
	}
}

void	fork2_exec(t_block *p, int *status, t_pipefd save)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(-1);
	else if (pid == 0)
		pipe_right(p->next, &(p->next->tokens));
	else
	{
		waitpid(pid, status, 0);
		dup2_and_close(save.in, STDIN_FILENO);
		dup2_and_close(save.out, STDOUT_FILENO);
		(*status) = wexitstatus_custom(*status);
	}
}

int	execute_block(t_block *p, t_deque *tokens)
{
	int			status;
	int			pipefd[2];
	t_pipefd	save;

	save.in = dup(STDIN_FILENO);
	save.out = dup(STDOUT_FILENO);
	if (p->next)
	{
		if (pipe(pipefd) < 0)
			exit(-1);
		fork1_exec(tokens, pipefd, &status);
		fork2_exec(p, &status, save);
		return (status);
	}
	else
	{
		status = return_execute(tokens, 0);
		dup2_and_close(save.in, STDIN_FILENO);
		dup2_and_close(save.out, STDOUT_FILENO);
		return (status);
	}
}

int	execute_all_blocks(t_blocklist *blocks)
{
	t_block	*p;
	char	*question_mark;
	char	*result_code_str;
	int		result_code;

	p = blocks->head;
	question_mark = ft_strdup("?");
	result_code = execute_block(p, &(p->tokens));
	result_code_str = ft_itoa(result_code);
	if (flag_set_test2(1, 1) == 1)
		env_manage(ENV_QUESTION_MARK, question_mark, result_code_str);
	else
	{
		flag_set_test2(1, 0);
		free(question_mark);
		free(result_code_str);
	}
	return (0);
}
