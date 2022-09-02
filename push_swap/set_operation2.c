/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:09:16 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 18:59:29 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_val(int val1)
{
	if (val1 == RA || val1 == RB)
		return (RR);
	else if (val1 == RRA || val1 == RRB)
		return (RRR);
	return (SS);
}

static void	if_case1(t_node **node, int *flag, int val1, int val2)
{
	if ((*node)->next->value == 5)
	{
		*flag = 1;
		return ;
	}
	if ((*node)->next->value == val1)
	{
		(*node)->value = get_val(val1);
		delete_node((*node), (*node)->next);
		(*node) = (*node)->prev;
	}
	else if ((*node)->next->value == val2)
	{
		delete_node((*node), (*node)->next);
		(*node) = (*node)->prev;
		delete_node((*node), (*node)->next);
	}
	else
	{
		(*node) = (*node)->next;
	}
}

static void	if_case2(t_node **node, int *flag, int val1)
{
	if ((*node)->next->value == 5)
	{
		*flag = 1;
		return ;
	}
	if ((*node)->next->value == val1)
	{
		delete_node((*node), (*node)->next);
		(*node) = (*node)->prev;
		delete_node((*node), (*node)->next);
	}
	else
	{
		(*node) = (*node)->next;
	}
}

static void	if_ss(t_node **node, int *flag)
{
	if ((*node)->next->value == 5)
	{
		*flag = 1;
		return ;
	}
	else
	{
		*node = (*node)->next;
	}
}

void	check_node_val(t_node **node, int *flag)
{
	if ((*node)->value == RA)
		if_case1(node, flag, RB, RRA);
	else if ((*node)->value == RB)
		if_case1(node, flag, RA, RRB);
	else if ((*node)->value == RR)
		if_case2(node, flag, RRR);
	else if ((*node)->value == RRA)
		if_case1(node, flag, RRB, RA);
	else if ((*node)->value == RRB)
		if_case1(node, flag, RRA, RB);
	else if ((*node)->value == RRR)
		if_case2(node, flag, RR);
	else if ((*node)->value == SA)
		if_case1(node, flag, SB, SA);
	else if ((*node)->value == SB)
		if_case1(node, flag, SA, SB);
	else if ((*node)->value == SS)
		if_ss(node, flag);
	else if ((*node)->value == PA)
		if_case2(node, flag, PB);
	else if ((*node)->value == PB)
		if_case2(node, flag, PA);
}
