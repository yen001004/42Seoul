/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_and_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:32:09 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:32:36 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	t_node	*min;
	t_node	*node;

	min = stack->top;
	node = stack->top->next;
	while (node != 0)
	{
		if (min->value > node->value)
		{
			min = node;
		}
		node = node->next;
	}
	return (min->value);
}

int	get_max(t_stack *stack)
{
	t_node	*max;
	t_node	*node;

	max = stack->top;
	node = stack->top->next;
	while (node != 0)
	{
		if (max->value < node->value)
		{
			max = node;
		}
		node = node->next;
	}
	return (max->value);
}
