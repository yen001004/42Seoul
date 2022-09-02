/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:47:19 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 19:24:56 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_val(t_value *val)
{
	val->pa = 0;
	val->pb = 0;
	val->ra = 0;
	val->rb = 0;
}

int	get_node(t_stack *stack, int i)
{
	t_node	*node;

	node = stack->top;
	while (i--)
	{
		node = node->next;
	}
	return (node->value);
}

void	get_cnt(t_stack *stack, int *cnt, int size, t_value **val)
{
	int	i;

	i = 0;
	while (cnt[i] != -1)
	{
		if (cnt[i] == (size / 3))
			(*val)->piv1 = get_node(stack, i);
		if (cnt[i] == ((size / 3) * 2))
			(*val)->piv2 = get_node(stack, i);
		i++;
	}
}

void	get_piv(t_stack *stack, int size, t_node *node1, int **cnt)
{
	int		i;
	int		size1;
	int		size2;
	t_node	*node2;

	i = 0;
	size1 = size;
	while (size1--)
	{
		size2 = size;
		node2 = stack->top;
		(*cnt)[i] = 0;
		while (size2--)
		{
			if (node2->value < node1->value)
				(*cnt)[i]++;
			node2 = node2->next;
		}
		node1 = node1->next;
		i++;
	}
	(*cnt)[i] = -1;
}

void	select_pivot(t_stack *stack, t_value *val, int size)
{
	int		*cnt;
	t_node	*node1;

	node1 = stack->top;
	cnt = (int *)malloc(sizeof(int) * (size + 1));
	if (!cnt)
		return ;
	get_piv(stack, size, node1, &cnt);
	get_cnt(stack, cnt, size, &val);
	free(cnt);
}
