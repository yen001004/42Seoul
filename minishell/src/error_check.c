/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:13:39 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 17:53:36 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init_tokens_and_node(t_block *block, t_deque *tokens, t_node **p)
{
	*tokens = block->tokens;
	*p = (*tokens).head;
}

static void	write_error_message(t_block *block)
{
	if (block->next)
		write(2, "syntax error near unexpected token `|'\n", 39);
	else
		write(2, "syntax error near unexpected token `newline'\n", 45);
}

static void	write_error_message_with_value(t_node	*p)
{
	write(2, "syntax error near unexpected token `", 36);
	write(2, p->next->value, ft_strlen(p->next->value));
	write(2, "'\n", 2);
}

static int	no_error_on_redirection(t_block *block)
{
	t_deque	tokens;
	t_node	*p;

	init_tokens_and_node(block, &tokens, &p);
	while (p != 0)
	{
		if ((ft_strncmp(p->name, "redir", 6) == 0))
		{
			if (p->next == 0)
			{
				write_error_message(block);
				return (0);
			}
			else
			{
				if (p->next && (ft_strncmp(p->next->name, "redir", 6) == 0))
				{
					write_error_message_with_value(p);
					return (0);
				}
			}
		}
		p = p->next;
	}
	return (1);
}

int	no_error_on_parse(t_blocklist *blocks)
{
	t_block	*p;

	p = blocks->head;
	if (check_empty_line(p))
		return (0);
	while (p)
	{
		if (p->tokens.cnt == 0)
		{
			if ((p->next) && (p->next->tokens.cnt == 0))
			{
				write(2, "syntax error near unexpected token `|'\n", 39);
				return (0);
			}
			if (p->next == 0)
			{
				write(2, "syntax error near unexpected token `newline'\n", 45);
				return (0);
			}
		}
		if (no_error_on_redirection(p) == 0)
			return (0);
		p = p->next;
	}
	return (1);
}
