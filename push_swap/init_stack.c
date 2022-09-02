/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:23:45 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:01:29 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->value = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_node(t_stack **stack, t_node **node, t_node **new)
{
	if (*node == 0)
	{
		*node = *new;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *new;
		(*new)->prev = *node;
		*node = (*node)->next;
	}
}

void	set_node(t_stack **stack, t_node **node, char *arg)
{
	t_node	*new;

	new = init_node();
	new->value = atoi(arg);
	add_node(stack, node, &new);
	(*stack)->size++;
}

void	make_stack(t_stack **a, int ac, char *av[])
{
	int		i;
	t_node	*node;

	i = 1;
	node = 0;
	while (i < ac)
	{
		set_node(a, &node, av[i]);
		i++;
	}
	if (node->next == 0)
		(*a)->bottom = node;
	i = 1;
	while (node->prev != 0)
		node = node->prev;
	while (i < ac)
	{
		(node) = (node)->next;
		i++;
	}
}
