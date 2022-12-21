/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:36 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 21:43:31 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_redirect(char *value)
{
	if (!ft_strncmp(value, "<", 2)
		|| !ft_strncmp(value, "<<", 3)
		|| !ft_strncmp(value, ">", 2)
		|| !ft_strncmp(value, ">>", 3))
		return (1);
	return (0);
}

static void	set_node_name(t_node *p, int *cmd_flag)
{
	if (check_redirect(p->value))
		p->name = ft_strdup("redir");
	else if ((*cmd_flag) == 0)
	{
		p->name = ft_strdup("cmd");
		(*cmd_flag) = 1;
	}
	else
		p->name = ft_strdup("str");
}

static void	lexer(t_deque *tokens)
{
	int		cmd_flag;
	t_node	*p;

	cmd_flag = 0;
	p = tokens->head;
	while (p != 0)
	{
		set_node_name(p, (&cmd_flag));
		p = p->next;
	}
}

void	lexer_blocks(t_blocklist *blocks)
{
	t_block	*p;

	p = blocks->head;
	while (p)
	{
		if (p->tokens.cnt != 0)
			lexer(&(p->tokens));
		p = p->next;
	}
}
