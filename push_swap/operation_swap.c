/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:05:28 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:03:24 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack, char flag, int both_flag, t_op **op)
{
	t_node	*temp;
	t_node	*next;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	next = stack->top->next;
	temp->next = next->next;
	temp->prev = next;
	next->next = temp;
	next->prev = NULL;
	stack->top = next;
	if (stack->size == 2)
		stack->bottom = temp;
	if (!both_flag)
	{
		if (flag == 'a')
			set_operation(op, SA);
		else
			set_operation(op, SB);
	}
}

void	swap_both(t_stack *a, t_stack *b, t_op **op)
{
	swap_stack(a, 'a', 1, op);
	swap_stack(b, 'b', 1, op);
	set_operation(op, SS);
}
