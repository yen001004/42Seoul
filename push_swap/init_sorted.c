/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:42:26 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 20:42:38 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int ac, int **sorted)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < ac)
	{
		j = 0;
		while (j < ac - 1)
		{
			if ((*sorted)[j] > (*sorted)[j + 1])
			{
				temp = (*sorted)[j];
				(*sorted)[j] = (*sorted)[j + 1];
				(*sorted)[j + 1] = temp;
			}
			else if ((*sorted)[j] == (*sorted)[j + 1])
				print_error();
			j++;
		}
		i++;
	}
}

int	*set_sorted(int ac, char *av[])
{
	int	i;
	int	*sorted;

	i = 0;
	sorted = malloc(sizeof(int) * ac);
	while (i < ac)
	{
		sorted[i] = atoi(av[i + 1]);
		i++;
	}
	bubble_sort(ac, &sorted);
	return (sorted);
}

void	value_to_index(t_stack **stack, int *sorted)
{
	int		i;
	int		cnt;
	t_node	*node;

	cnt = (*stack)->size;
	node = (*stack)->top;
	while (cnt--)
	{
		i = 0;
		while (sorted != 0)
		{
			if (node->value == sorted[i])
			{
				node->value = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

int	check_sorted(t_stack *a, int *sorted)
{
	int		i;
	t_node	*node;

	i = 0;
	node = a->top;
	while (node != 0)
	{
		if (node->value != sorted[i])
			return (0);
		if (node->next == 0)
			break ;
		node = node->next;
		i++;
	}
	return (1);
}
