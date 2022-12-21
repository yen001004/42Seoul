/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:59 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/26 16:00:30 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	env_manage_export(t_node **p, char *v, int i, int l)
{
	if (!(*p)->next)
		env_manage(ENV_EXPORT, ft_substr(v, 0, i), ft_substr(v, i + 1, l - i));
	else
	{
		*p = (*p)->next;
		if ((*p)->value)
			env_manage(ENV_EXPORT, ft_substr(v, 0, i), \
			ft_substr((*p)->value, 0, ft_strlen((*p)->value)));
	}
}

static void	check_valid_id1(t_node **p, char *v, char *idx_char, int *ret)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(v);
	if (v == idx_char)
	{
		printf("Minishell> export: `%s': not a valid identifier\n", v);
		*ret = 1;
	}
	while ((v + i) < idx_char)
	{
		if (!((ft_isdigit(v[i]) && (i != 0))
				|| ft_isalpha(v[i]) || ('_' == v[i])))
		{
			printf("Minishell> export: `%s': not a valid identifier\n", v);
			*ret = 1;
			break ;
		}
		i++;
	}
	if (!(*ret))
		env_manage_export(p, v, i, l);
}

static void	check_valid_identifier2(char *value, int *ret)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (!((ft_isdigit(value[i]) && (i != 0))
				|| ft_isalpha(value[i]) || ('_' == value[i])))
		{
			printf("Minishell> export: `%s': not a valid identifier\n", value);
			*ret = 1;
			break ;
		}
		i++;
	}
	if (!(*ret))
		env_manage(ENV_EXPORT, ft_substr(value, 0, ft_strlen(value)), 0);
}

static void	check_idx_char(t_node **p, char *value, int *return_val)
{
	char	*idx_char;

	idx_char = ft_strchr(value, '=');
	if (idx_char)
		check_valid_id1(p, value, idx_char, return_val);
	else
		check_valid_identifier2(value, return_val);
}

int	builtins_export(t_deque *tokens)
{
	t_node	*p;
	int		return_val;
	int		max_return;

	max_return = 0;
	if (!tokens->head->next)
	{
		env_manage(ENV_EXPORT, 0, 0);
		return (0);
	}
	p = tokens->head->next;
	while (p)
	{
		return_val = 0;
		if (ft_strncmp(p->name, "str", 4) == 0)
		{
			check_idx_char(&p, p->value, &return_val);
		}
		if (max_return < return_val)
			max_return = return_val;
		p = p->next;
	}
	return (max_return);
}
