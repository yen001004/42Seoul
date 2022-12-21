/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:12:17 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:12:17 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*find_node(t_deque *deque, char *key)
{
	t_node	*p;

	p = deque->head;
	while (p)
	{
		if (ft_strncmp(p->name, key, ft_strlen(p->name) + 1) == 0)
			return (p);
		p = p->next;
	}
	return (0);
}

static void	del_3_case(t_deque *deque, t_node *p)
{
	if (deque->head == p)
	{
		p->next->prev = 0;
		deque->head = p->next;
	}
	else if (deque->tail == p)
	{
		p->prev->next = 0;
		deque->tail = p->prev;
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
}

int	del_node(t_deque *deque, char *key)
{
	t_node	*p;

	p = deque->head;
	while (p)
	{
		if (ft_strncmp(p->name, key, ft_strlen(p->name) + 1) == 0)
		{
			del_3_case(deque, p);
			deque->cnt--;
			free_t_node(p);
			return (1);
		}
		p = p->next;
	}
	return (0);
}

void	free_all_node(t_deque *deque)
{
	while (1)
	{
		if (del_tail(deque) == 0)
			break ;
	}
}

void	print_all_node(t_deque *deque)
{
	t_node	*p;

	printf("------ token ------\n");
	printf("[head]\n");
	p = deque->head;
	while (p)
	{
		printf("[%s] : %s\n", p->name, p->value);
		p = p->next;
	}
	printf("[tail]\n");
	printf("----------\n");
}
