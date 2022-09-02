/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operation3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:19 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 21:05:37 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_check_val(t_node *node)
{
	if (node->value == RA)
		write(1, "ra\n", 3);
	else if (node->value == RB)
		write(1, "rb\n", 3);
	else if (node->value == RR)
		write(1, "rr\n", 3);
	else if (node->value == RRA)
		write(1, "rra\n", 4);
	else if (node->value == RRB)
		write(1, "rrb\n", 4);
	else if (node->value == RRR)
		write(1, "rrr\n", 4);
	else if (node->value == SA)
		write(1, "sa\n", 3);
	else if (node->value == SB)
		write(1, "sb\n", 3);
	else if (node->value == SS)
		write(1, "ss\n", 3);
	else if (node->value == PA)
		write(1, "pa\n", 3);
	else if (node->value == PB)
		write(1, "pb\n", 3);
}

void	print_op(t_op **op)
{
	t_node	*node;

	node = (*op)->operation->top;
	while (node != NULL)
	{
		print_check_val(node);
		node = node->next;
		if (node == NULL)
			return ;
	}
}
