/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_etc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:11:35 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 20:11:08 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_argv(char **argv, t_deque *tokens)
{
	int		i;
	t_node	*node;

	i = 0;
	node = tokens->head;
	while (node != 0)
	{
		if (ft_strncmp(node->name, "redir", 6) == 0)
		{
			if (node->next == 0)
				break ;
			node = node->next;
		}
		else
		{
			argv[i] = ft_strdup(node->value);
			i++;
		}
		if (node->next == 0)
			break ;
		node = node->next;
	}
	argv[i] = 0;
}

void	get_envp(char **envp, t_deque *envs)
{
	int		i;
	int		name_len;
	int		value_len;
	t_node	*node;

	i = 0;
	node = envs->head;
	while (node != 0)
	{
		name_len = ft_strlen(node->name);
		value_len = ft_strlen(node->value);
		envp[i] = (char *)malloc(sizeof(char) * (name_len + value_len + 2));
		envp[i][0] = 0;
		str_push(envp[i], node->name, name_len);
		str_push(envp[i], "=", 1);
		str_push(envp[i], node->value, value_len);
		node = node->next;
		i++;
	}
	envp[i] = 0;
}

int	redir_cnt(t_deque *tokens)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = tokens->head;
	while (node != 0)
	{
		if (ft_strncmp(node->name, "redir", 6) == 0)
		{
			if (node->next == 0)
				break ;
			node = node->next;
			cnt++;
			if (node->next == 0)
				break ;
			node = node->next;
			cnt++;
		}
		node = node->next;
	}
	return (cnt);
}
