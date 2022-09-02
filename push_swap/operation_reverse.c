/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:04:55 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:02:37 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_stack(t_stack *stack, char flag, int both_flag, t_op **op)
{
	t_node	*temp;

	if (stack->size < 2)
		return ;
	temp = stack->bottom;
	temp->next = stack->top;
	stack->top->prev = temp;
	temp->prev->next = NULL;
	stack->bottom = temp->prev;
	temp->prev = NULL;
	stack->top = stack->top->prev;
	if (!both_flag)
	{
		if (flag == 'a')
			set_operation(op, RRA);
		else
			set_operation(op, RRB);
	}
}

void	reverse_both(t_stack *a, t_stack *b, t_op **op)
{
	reverse_stack(a, 'a', 1, op);
	reverse_stack(b, 'b', 1, op);
	set_operation(op, RRR);
}
