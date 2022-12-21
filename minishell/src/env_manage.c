/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:46 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:55:49 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	print_all_export(t_deque *envs)
{
	t_node	*p;

	p = envs->head;
	while (p)
	{
		if (p->name[0] != '?')
		{
			if (p->value == 0)
				printf("declare -x %s\n", p->name);
			else if (p->value[0] == '\0')
				printf("declare -x %s=\"\"\n", p->name);
			else
				printf("declare -x %s=%s\n", p->name, p->value);
		}
		p = p->next;
	}
}

static void	*action_env_export(char *name, t_deque	*envs, char *value)
{
	t_node	*p;

	if (name == 0)
	{
		print_all_export(envs);
		return (0);
	}
	p = find_node(envs, name);
	if (p)
		export_env_update(name, value, p);
	else
		export_env_append(envs, name, value);
	return (0);
}

void	*env_manage(int action, char *name, char *value)
{
	static t_deque	envs = {.head = 0, .tail = 0, .cnt = 0};
	t_node			*p;

	if (envs.cnt == 0)
		init_envs(&envs);
	if (action == ENV_GET)
	{
		if (name[0] == 0)
			printf(" command not found\n");
		return (get_env_by_key(&envs, name));
	}
	else if (action == ENV_EXPORT)
		return (action_env_export(name, &envs, value));
	else if (action == ENV_UNSET)
		unset_env(&envs, name);
	else if (action == ENV_ALL)
		return (&envs);
	else if (action == ENV_QUESTION_MARK)
	{
		p = find_node(&envs, name);
		if (p)
			export_env_update(name, value, p);
	}
	return (0);
}
