/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:23:33 by yen               #+#    #+#             */
/*   Updated: 2022/08/16 15:58:22 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->top;
	if (stack->size == 0)
		return ;
	while (node != 0)
	{
		if (node->next != 0)
			next = node->next;
		else
			next = 0;
		free(node);
		if (next != 0)
			node = next;
		else
			break ;
	}
	free(stack);
	stack = 0;
}

void	free_a_b(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	free_all(t_stack *a, t_stack *b, t_op *op)
{
	free_stack(a);
	free_stack(b);
	free_stack(op->operation);
}
