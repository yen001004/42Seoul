/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:39:00 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 20:49:12 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_a_two(t_stack *a, t_stack *b, int size, t_op **op)
{
	if (size == 1)
	{
		push_stack(b, a, 'a', op);
	}
	if (size == 2)
	{
		if (b->top->value < b->top->next->value)
		{
			swap_stack(b, 'b', 0, op);
		}
		push_stack(b, a, 'a', op);
		push_stack(b, a, 'a', op);
	}
}

static void	push_or_rotate(t_stack *a, t_stack *b, t_value *val, t_op **op)
{
	if (b->top->value <= val->piv1)
	{
		rotate_stack(b, 'b', 0, op);
		val->rb++;
	}
	else
	{
		push_stack(b, a, 'a', op);
		val->pa++;
		if (a->top->value <= val->piv2)
		{
			rotate_stack(a, 'a', 0, op);
			val->ra++;
		}
	}
}

static void	rev_rot_back_ra(t_stack *a, t_stack *b, t_value *val, t_op **op)
{
	int	temp_ra;
	int	temp_rb;

	temp_rb = val->rb;
	temp_ra = val->ra - temp_rb;
	while (temp_rb--)
		reverse_both(a, b, op);
	while (temp_ra--)
		reverse_stack(a, 'a', 0, op);
}

static void	rev_rot_back_rb(t_stack *a, t_stack *b, t_value *val, t_op **op)
{
	int	temp_ra;
	int	temp_rb;

	temp_ra = val->ra;
	temp_rb = val->rb - temp_ra;
	while (temp_ra--)
		reverse_both(a, b, op);
	while (temp_rb--)
		reverse_stack(b, 'b', 0, op);
}

void	sort_b_to_a(t_stack *a, t_stack *b, int size, t_op **op)
{
	t_value	val;

	((*op)->b_cnt)++;
	if (size < 3)
	{
		sort_b_a_two(a, b, size, op);
		return ;
	}
	init_val(&val);
	select_pivot(b, &val, size);
	while (size--)
		push_or_rotate(a, b, &val, op);
	sort_a_to_b(a, b, val.pa - val.ra, op);
	if (val.ra > val.rb)
		rev_rot_back_ra(a, b, &val, op);
	else
		rev_rot_back_rb(a, b, &val, op);
	sort_a_to_b(a, b, val.ra, op);
	sort_b_to_a(a, b, val.rb, op);
}
