/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_and_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:13:57 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:32:25 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack, char flag, t_op **op)
{
	if (stack->top->value < stack->bottom->value)
		return ;
	else
	{
		swap_stack(stack, flag, 0, op);
	}
}

static void	sort_three_case2(t_stack *stack, int max, char flag, t_op **op)
{
	if (stack->top->value == max)
		rotate_stack(stack, flag, 0, op);
	else
		swap_stack(stack, flag, 0, op);
}

static void	sort_three_case3(t_stack *stack, int max, char flag, t_op **op)
{
	if (stack->top->value == max)
	{
		rotate_stack(stack, flag, 0, op);
		swap_stack(stack, flag, 0, op);
	}
	else
		reverse_stack(stack, flag, 0, op);
}

void	sort_three(t_stack *stack, char flag, t_op **op)
{
	int	min;
	int	max;

	min = get_min(stack);
	max = get_max(stack);
	if (stack->top->value == min)
	{
		if (stack->bottom->value == max)
			return ;
		else
		{
			reverse_stack(stack, flag, 0, op);
			swap_stack(stack, flag, 0, op);
		}
	}
	else if (stack->top->next->value == min)
	{
		sort_three_case2(stack, max, flag, op);
	}
	else
	{
		sort_three_case3(stack, max, flag, op);
	}
}
