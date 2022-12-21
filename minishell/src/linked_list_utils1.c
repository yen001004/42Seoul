/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:12:12 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:12:12 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*make_node(char *name, char *value)
{
	t_node	*new_node;

	new_node = (t_node *)ft_malloc(1 * sizeof(t_node));
	new_node->name = name;
	new_node->value = value;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	append_head(t_deque *deque, t_node *new_node)
{
	deque->cnt++;
	if (deque->head == 0 && deque->tail == 0)
	{
		deque->head = new_node;
		deque->tail = new_node;
		return ;
	}
	new_node->next = deque->head;
	deque->head->prev = new_node;
	deque->head = new_node;
}

void	append_tail(t_deque *deque, t_node *new_node)
{
	deque->cnt++;
	if (deque->head == 0 && deque->tail == 0)
	{
		deque->head = new_node;
		deque->tail = new_node;
		return ;
	}
	new_node->prev = deque->tail;
	deque->tail->next = new_node;
	deque->tail = new_node;
}

int	del_tail(t_deque *deque)
{
	t_node	*p;

	if (deque->cnt == 0)
		return (0);
	p = deque->tail;
	if (deque->cnt == 1)
	{
		deque->head = 0;
		deque->tail = 0;
	}
	else
	{
		deque->tail->prev->next = 0;
		deque->tail = deque->tail->prev;
	}
	deque->cnt--;
	free(p->name);
	free(p->value);
	free(p);
	return (1);
}

void	init_deque(t_deque *deque)
{
	deque->cnt = 0;
	deque->head = 0;
	deque->tail = 0;
}
