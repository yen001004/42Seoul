/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:03:36 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:02:17 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	from_size_one(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = from->top;
	}
	from->top = NULL;
	from->bottom = NULL;
}

static void	from_size_many(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = from->top;
		from->top = from->top->next;
		from->top->prev = NULL;
		to->top->next = NULL;
	}
	else
	{
		to->top->prev = from->top;
		from->top = from->top->next;
		from->top->prev = NULL;
		to->top->prev->next = to->top;
		to->top = to->top->prev;
	}
}

void	push_stack(t_stack *from, t_stack *to, char flag, t_op **op)
{
	if (from->size == 1)
	{
		from_size_one(from, to);
	}
	else
	{
		from_size_many(from, to);
	}
	(from->size)--;
	(to->size)++;
	if (flag == 'a')
	{
		set_operation(op, PA);
	}
	else
	{
		set_operation(op, PB);
	}
}
