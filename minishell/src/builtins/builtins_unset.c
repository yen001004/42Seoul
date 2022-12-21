/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:10:29 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:10:29 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	check_valid_identifier(char *value, int *return_val)
{
	int	i;

	i = 0;
	while (value && value[i])
	{
		if (!(((ft_isdigit(value[i])) && (i != 0))
				|| ft_isalpha(value[i]) || ('_' == value[i])))
		{
			printf("Minishell> unset: `%s': not a valid identifier\n", value);
			*return_val = 1;
			break ;
		}
		i++;
	}
	env_manage(ENV_UNSET, value, 0);
}

int	builtins_unset(t_deque *tokens)
{
	int		return_val;
	t_node	*p;

	return_val = 0;
	if (!tokens->head->next)
		return (0);
	p = tokens->head;
	while (p)
	{
		if (ft_strncmp(p->name, "str", 3) == 0)
		{
			check_valid_identifier(p->value, &return_val);
		}
		p = p->next;
	}
	return (return_val);
}
