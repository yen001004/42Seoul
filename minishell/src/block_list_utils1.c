/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_list_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:07:49 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:07:52 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_block	*make_block(char *value)
{
	t_block	*new_block;

	new_block = (t_block *)ft_malloc(1 * sizeof(t_block));
	new_block->value = value;
	new_block->next = 0;
	new_block->prev = 0;
	return (new_block);
}

void	append_block_head(t_blocklist *blocklist, t_block *new_block)
{
	blocklist->cnt++;
	if (blocklist->head == 0 && blocklist->tail == 0)
	{
		blocklist->head = new_block;
		blocklist->tail = new_block;
		return ;
	}
	new_block->next = blocklist->head;
	blocklist->head->prev = new_block;
	blocklist->head = new_block;
}

void	append_block_tail(t_blocklist *blocklist, t_block *new_block)
{
	blocklist->cnt++;
	if (blocklist->head == 0 && blocklist->tail == 0)
	{
		blocklist->head = new_block;
		blocklist->tail = new_block;
		return ;
	}
	new_block->prev = blocklist->tail;
	blocklist->tail->next = new_block;
	blocklist->tail = new_block;
}

int	del_block_tail(t_blocklist *blocklist)
{
	t_block	*p;

	if (blocklist->cnt == 0)
		return (0);
	p = blocklist->tail;
	if (blocklist->cnt == 1)
	{
		blocklist->head = 0;
		blocklist->tail = 0;
	}
	else
	{
		blocklist->tail->prev->next = 0;
		blocklist->tail = blocklist->tail->prev;
	}
	blocklist->cnt--;
	free_all_node(&(p->tokens));
	free(p->value);
	free(p);
	return (1);
}

void	init_blocklist(t_blocklist *blocklist)
{
	blocklist->cnt = 0;
	blocklist->head = 0;
	blocklist->tail = 0;
}
