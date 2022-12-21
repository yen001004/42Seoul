/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:10:11 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 21:34:06 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_option_n(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i] != 0)
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	write_node(t_node	**node)
{
	write(1, (*node)->value, ft_strlen((*node)->value));
	if ((*node)->next != 0)
		write(1, " ", 1);
	*node = (*node)->next;
}

int	builtins_echo(t_deque *tokens)
{
	int		n_flag;
	t_node	*node;

	n_flag = 0;
	if (tokens->head->next == 0)
	{
		printf("\n");
		return (0);
	}
	node = tokens->head->next;
	while (is_option_n(node->value))
	{
		n_flag = 1;
		if (node->next == 0)
		{
			node = node->next;
			break ;
		}
		node = node->next;
	}
	while (node != 0)
		write_node(&node);
	if (!n_flag)
		printf("\n");
	return (0);
}
