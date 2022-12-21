/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:28 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/26 14:46:54 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_equal_idx(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

static char	*get_env_name(char *str, int idx)
{
	char	*name;

	name = ft_substr(str, 0, idx);
	if (name == 0)
		exit(1);
	return (name);
}

static char	*get_env_value(char *str, int idx)
{
	int		len;
	char	*value;

	len = ft_strlen(str);
	value = ft_substr(str, idx + 1, len - 1);
	return (value);
}

void	init_envs(t_deque	*envs)
{
	extern char	**environ;
	int			i;
	int			idx;
	t_node		*env_node;

	i = 0;
	init_deque(envs);
	env_node = make_node(ft_strdup("?"), ft_strdup("0"));
	append_tail(envs, env_node);
	while (environ[i] != 0)
	{
		idx = get_equal_idx(environ[i]);
		env_node = make_node(get_env_name(environ[i], idx), \
							get_env_value(environ[i], idx));
		append_tail(envs, env_node);
		i++;
	}
}
