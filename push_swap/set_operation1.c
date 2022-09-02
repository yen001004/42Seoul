/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operation1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:09:24 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 19:04:59 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node(t_node *node, t_node *temp)
{
	temp->next->prev = node;
	node->next = temp->next;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
}

void	check_operation(t_op **op)
{
	int		flag;
	t_node	*node;

	if ((*op)->operation->size == 0)
		return ;
	flag = 0;
	node = (*op)->operation->top;
	while (node != NULL)
	{
		if (node->value == 0)
			node = node->next;
		if (node->value == 5)
			return ;
		else
			check_node_val(&node, &flag);
		if (flag)
		{
			print_op(op);
			return ;
		}
	}
}

void	set_operation(t_op **op, int op_num)
{
	t_node	*new;

	new = init_node();
	new->value = op_num;
	add_node(&((*op)->operation), &((*op)->operation->bottom), &new);
	(*op)->operation->size++;
}

void	make_opstack(t_op **op)
{
	t_node	*node;

	node = init_node();
	node->value = 0;
	(*op)->operation->top = node;
	(*op)->operation->bottom = node;
	(*op)->operation->size++;
}
