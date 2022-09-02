/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:04:20 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:03:00 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack, char flag, int both_flag, t_op **op)
{
	t_node	*temp;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	temp->prev = stack->bottom;
	stack->bottom->next = temp;
	temp->next->prev = NULL;
	stack->top = temp->next;
	temp->next = NULL;
	stack->bottom = stack->bottom->next;
	if (!both_flag)
	{
		if (flag == 'a')
			set_operation(op, RA);
		else
			set_operation(op, RB);
	}
}

void	rotate_both(t_stack *a, t_stack *b, t_op **op)
{
	rotate_stack(a, 'a', 1, op);
	rotate_stack(b, 'b', 1, op);
	set_operation(op, RR);
}
