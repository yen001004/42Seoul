/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manage_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:54 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:56:05 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_env_by_key(t_deque *envs, char *key)
{
	t_node	*p;

	p = find_node(envs, key);
	if (p)
		return (p->value);
	else
		return (0);
}

void	export_env_update(char *key, char *value, t_node *node)
{
	free(key);
	free(node->value);
	node->value = value;
}

void	export_env_append(t_deque *envs, char *key, char *value)
{
	append_tail(envs, make_node(key, value));
}

void	unset_env(t_deque *envs, char *key)
{
	del_node(envs, key);
}
