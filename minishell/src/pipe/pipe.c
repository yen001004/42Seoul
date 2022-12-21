/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:12:00 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:12:01 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pipe_left(t_deque *tokens, int *pipefd)
{
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	return (return_execute(tokens, 1));
}

void	pipe_right(t_block *p, t_deque *tokens)
{
	exit(execute_block(p, tokens));
}
