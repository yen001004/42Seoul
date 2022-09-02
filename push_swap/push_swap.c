/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:23:32 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/25 16:37:03 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	push_swap(t_stack *a, t_stack *b, int ac, t_op *op)
{
	op->b_cnt = 0;
	op->operation = init_stack();
	make_opstack(&op);
	if (ac == 2)
		return ;
	else if (ac == 3)
		sort_two(a, 'a', &op);
	else if (ac == 4)
		sort_three(a, 'a', &op);
	else if (ac == 6)
		sort_five(a, b, &op);
	else
		sort_a_to_b(a, b, a->size, &op);
	set_operation(&op, 5);
	check_operation(&op);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted;
	t_op	op;

	if (ac > 1)
	{
		check_arg(av);
		a = init_stack();
		make_stack(&a, ac, av);
		b = init_stack();
		sorted = set_sorted(ac - 1, av);
		if (check_sorted(a, sorted))
		{
			free(sorted);
			free_a_b(a, b);
			return (0);
		}
		value_to_index(&a, sorted);
		push_swap(a, b, ac, &op);
		free(sorted);
		free_all(a, b, &op);
	}
	return (0);
}
