/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:11:00 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:59:26 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_etc(t_deque *tokens)
{
	int		i;
	int		status;
	pid_t	pid;

	i = 0;
	status = 0;
	flag_set_test(0, 0);
	set_signal();
	pid = fork();
	if (pid < 0)
		exit(-1);
	else if (pid == 0)
	{
		exec_etc_child(tokens, i);
		return (0);
	}
	else
	{
		waitpid(pid, &status, 0);
		flag_set_test(1, 0);
		set_signal();
		return (wexitstatus_custom(status));
	}
}
