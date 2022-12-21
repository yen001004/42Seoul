/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_block_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:14:03 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:14:04 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	child_execute_check(t_deque *tokens, int redir)
{
	if (tokens->cnt == 0)
		exit (127);
	del_redir(tokens);
	if (redir != 0)
		exit (redir);
	if (tokens->cnt == 0)
		exit (0);
	return (1);
}

int	normal_execute_check(t_deque *tokens, int redir)
{
	if (tokens->cnt == 0)
		return (127);
	del_redir(tokens);
	if (redir != 0)
		return (redir);
	if (tokens->cnt == 0)
		return (0);
	return (1);
}

int	child_execute(t_deque *tokens)
{
	t_node	*p;

	p = tokens->head;
	while (p != 0)
	{
		if (!ft_strncmp(p->name, "cmd", 4))
			break ;
		p = p->next;
	}
	if (ft_strncmp(p->value, "echo", 5) == 0)
		exit(builtins_echo(tokens));
	else if (ft_strncmp(p->value, "cd", 3) == 0)
		exit(builtins_cd(tokens));
	else if (ft_strncmp(p->value, "pwd", 4) == 0)
		exit(builtins_pwd());
	else if (ft_strncmp(p->value, "export", 7) == 0)
		exit(builtins_export(tokens));
	else if (ft_strncmp(p->value, "unset", 6) == 0)
		exit(builtins_unset(tokens));
	else if (ft_strncmp(p->value, "env", 4) == 0)
		exit(builtins_env());
	else if (ft_strncmp(p->value, "exit", 5) == 0)
		exit(builtins_exit(tokens));
	else
		exit(exec_etc(tokens));
}

int	normal_execute(t_deque *tokens)
{
	t_node	*p;

	p = tokens->head;
	while (p != 0)
	{
		if (!ft_strncmp(p->name, "cmd", 4))
			break ;
		p = p->next;
	}
	if (ft_strncmp(p->value, "echo", 5) == 0)
		return (builtins_echo(tokens));
	else if (ft_strncmp(p->value, "cd", 3) == 0)
		return (builtins_cd(tokens));
	else if (ft_strncmp(p->value, "pwd", 4) == 0)
		return (builtins_pwd());
	else if (ft_strncmp(p->value, "export", 7) == 0)
		return (builtins_export(tokens));
	else if (ft_strncmp(p->value, "unset", 6) == 0)
		return (builtins_unset(tokens));
	else if (ft_strncmp(p->value, "env", 4) == 0)
		return (builtins_env());
	else if (ft_strncmp(p->value, "exit", 5) == 0)
		return (builtins_exit(tokens));
	else
		return (exec_etc(tokens));
}

int	return_execute(t_deque *tokens, int child_flag)
{
	int		return_code;

	return_code = redir_execute(tokens);
	if (child_flag)
	{
		child_execute_check(tokens, return_code);
		return (child_execute(tokens));
	}
	else
	{
		return_code = normal_execute_check(tokens, return_code);
		if (return_code != 1)
			return (return_code);
		return (normal_execute(tokens));
	}
}
