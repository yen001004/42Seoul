/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:10:23 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:10:25 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtins_env(void)
{
	t_deque	*envs;
	t_node	*node;

	envs = (t_deque *)env_manage(ENV_ALL, 0, 0);
	node = envs->head;
	while (node)
	{
		if (node->value != 0 && node->name[0] != '?')
			printf("%s=%s\n", node->name, node->value);
		node = node->next;
	}
	return (0);
}
