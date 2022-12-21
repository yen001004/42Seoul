/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:11:26 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 21:31:23 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	init_token_head_tail(t_deque *tokens)
{
	tokens->head = 0;
	tokens->tail = 0;
}

static void	del_redir_node(t_deque *tokens, t_node *p)
{
	if (p)
	{
		if (tokens->head == p)
		{
			if (tokens->tail == p)
				init_token_head_tail(tokens);
			else
			{
				p->next->prev = 0;
				tokens->head = p->next;
			}
		}
		else if (tokens->tail == p)
		{
			p->prev->next = 0;
			tokens->tail = p->prev;
		}
		else
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		tokens->cnt--;
		free_t_node(p);
	}
}

void	del_redir(t_deque *tokens)
{
	t_node	*p;
	t_node	*save_node;

	p = tokens->head;
	while (p != 0)
	{
		if (!ft_strncmp(p->name, "redir", 6))
		{
			save_node = p->next;
			del_redir_node(tokens, p);
			if (p->next)
			{
				save_node = save_node->next;
				del_redir_node(tokens, p->next);
			}
			p = save_node;
		}
		else
		{
			if (p->next == 0)
				break ;
			p = p->next;
		}
	}
}

int	check_redirection(char **str)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen((*str));
	if (len == 0)
		return (-1);
	if (((*str)[0] == '\'' && (*str)[len - 1] == '\'')
		|| ((*str)[0] == '"' && (*str)[len - 1] == '"'))
	{
		(*str) = remove_quote((*str));
		return (-1);
	}
	while ((*str)[i] != 0)
	{
		if ((*str)[i] == '<' || (*str)[i] == '>')
			return (i);
		i++;
	}
	return (-1);
}

int	redir_one_or_two(char *str, int idx)
{
	if (str[idx + 1] != 0 && str[idx] == str[idx + 1])
	{
		return (2);
	}
	return (1);
}
