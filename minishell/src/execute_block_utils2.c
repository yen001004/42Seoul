/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_block_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:14:13 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:14:14 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	redir_execute(t_deque *tokens)
{
	int		return_code;
	t_node	*p;

	return_code = 0;
	p = tokens->head;
	while (p != 0)
	{
		if (!ft_strncmp(p->name, "redir", 6))
		{
			return_code = redirection_execute(tokens);
			break ;
		}
		p = p->next;
	}
	return (return_code);
}
