/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:23:27 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 21:03:37 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define PA 11
# define PB 12

# define SA 21
# define SB 22
# define SS 20

# define RA 31
# define RB 32
# define RR 30

# define RRA 41
# define RRB 42
# define RRR 40

typedef struct s_node	t_node;
typedef struct s_stack	t_stack;
typedef struct s_value	t_value;
typedef struct s_op		t_op;

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};

struct	s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
};

struct	s_value
{
	int	piv1;
	int	piv2;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
};

struct	s_op
{
	int		b_cnt;
	t_stack	*operation;
};

void	check_arg(char *av[]);

void	free_stack(t_stack *stack);
void	free_a_b(t_stack *a, t_stack *b);
void	free_all(t_stack *a, t_stack *b, t_op *op);

int		ft_atoi(char *str);

int		get_min(t_stack *stack);
int		get_max(t_stack *stack);

int		*set_sorted(int ac, char *av[]);
void	value_to_index(t_stack **stack, int *sorted);
int		check_sorted(t_stack *a, int *sorted);

t_stack	*init_stack(void);
t_node	*init_node(void);
void	add_node(t_stack **stack, t_node **node, t_node **new);
void	set_node(t_stack **stack, t_node **node, char *arg);
void	make_stack(t_stack **a, int ac, char *av[]);

void	push_stack(t_stack *from, t_stack *to, char flag, t_op **op);

void	reverse_stack(t_stack *stack, char flag, int both_flag, t_op **op);
void	reverse_both(t_stack *a, t_stack *b, t_op **op);

void	rotate_stack(t_stack *stack, char flag, int both_flag, t_op **op);
void	rotate_both(t_stack *a, t_stack *b, t_op **op);

void	swap_stack(t_stack *stack, char flag, int both_flag, t_op **op);
void	swap_both(t_stack *a, t_stack *b, t_op **op);

void	print_error(void);
void	push_swap(t_stack *a, t_stack *b, int ac, t_op *op);

void	delete_node(t_node *node, t_node *temp);
void	check_operation(t_op **op);
void	set_operation(t_op **op, int op_num);
void	make_opstack(t_op **op);

void	check_node_val(t_node **node, int *flag);

void	print_op(t_op **op);

void	sort_a_to_b(t_stack *a, t_stack *b, int size, t_op **op);
void	sort_b_to_a(t_stack *a, t_stack *b, int size, t_op **op);

void	sort_two(t_stack *stack, char flag, t_op **op);
void	sort_three(t_stack *stack, char flag, t_op **op);
void	sort_five(t_stack *a, t_stack *b, t_op **op);

void	init_val(t_value *val);
int		get_node(t_stack *stack, int i);
void	get_cnt(t_stack *stack, int *cnt, int size, t_value **val);
void	get_piv(t_stack *stack, int size, t_node *node1, int **cnt);
void	select_pivot(t_stack *stack, t_value *val, int size);

#endif
