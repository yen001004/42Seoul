/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:41:40 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 16:30:22 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *a, t_stack *b, t_op **op)
{
	int	one;
	int	two;
	int	flag;

	one = 0;
	two = 1;
	flag = 0;
	while (flag != 2)
	{
		if (a->top->value == one || a->top->value == two)
		{
			push_stack(a, b, 'b', op);
			flag++;
		}
		else
		{
			rotate_stack(a, 'a', 0, op);
		}
	}
	sort_three(a, 'a', op);
	if (b->top->value < b->top->next->value)
		swap_stack(b, 'b', 0, op);
	push_stack(b, a, 'a', op);
	push_stack(b, a, 'a', op);
}
