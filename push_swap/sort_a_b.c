/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:39:16 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 20:48:56 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_b_two(t_stack *a, char flag, int size, t_op **op)
{
	if (size == 2)
	{
		if (a->top->value > a->top->next->value)
		{
			swap_stack(a, flag, 0, op);
		}
	}
}

static void	push_or_rotate(t_stack *a, t_stack *b, t_value *val, t_op **op)
{
	if (a->top->value >= val->piv2)
	{
		rotate_stack(a, 'a', 0, op);
		val->ra++;
	}
	else
	{
		push_stack(a, b, 'b', op);
		val->pb++;
		if (b->top->value > val->piv1)
		{
			rotate_stack(b, 'b', 0, op);
			val->rb++;
		}
	}
}

static void	rev_rot_back_ra(t_stack *a, t_stack *b, t_value *val, t_op **op)
{
	int	temp_ra;
	int	temp_rb;

	temp_ra = val->ra;
	temp_rb = val->rb;
	if ((*op)->b_cnt > 0)
	{
		temp_ra -= temp_rb;
		while (temp_rb--)
			reverse_both(a, b, op);
		while (temp_ra--)
			reverse_stack(a, 'a', 0, op);
	}
	else
	{
		while (temp_rb--)
			reverse_stack(b, 'b', 0, op);
	}
}

static void	rev_rot_back_rb(t_stack *a, t_stack *b, t_value *val, t_op **op)
{
	int	temp_ra;
	int	temp_rb;

	temp_ra = val->ra;
	temp_rb = val->rb;
	if ((*op)->b_cnt > 0)
	{
		temp_rb -= temp_ra;
		while (temp_ra--)
			reverse_both(a, b, op);
		while (temp_rb--)
			reverse_stack(b, 'b', 0, op);
	}
	else
	{
		while (temp_rb--)
			reverse_stack(b, 'b', 0, op);
	}
}

void	sort_a_to_b(t_stack *a, t_stack *b, int size, t_op **op)
{
	t_value	val;

	if (size < 3)
	{
		sort_a_b_two(a, 'a', size, op);
		return ;
	}
	init_val(&val);
	select_pivot(a, &val, size);
	while (size--)
		push_or_rotate(a, b, &val, op);
	if (val.ra > val.rb)
		rev_rot_back_ra(a, b, &val, op);
	else
		rev_rot_back_rb(a, b, &val, op);
	sort_a_to_b(a, b, val.ra, op);
	sort_b_to_a(a, b, val.rb, op);
	sort_b_to_a(a, b, val.pb - val.rb, op);
}
