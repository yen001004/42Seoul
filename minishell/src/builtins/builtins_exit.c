/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:10:37 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:10:38 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtins_exit(t_deque *tokens)
{
	t_node	*p;

	p = tokens->head;
	printf("exit\n");
	if (p->next)
	{
		p = p->next;
		if (is_all_digit(p->value))
		{
			if (p->next)
			{
				write(2, "exit: too many arguments\n", 25);
				exit(1);
			}
			exit(ft_atoi(p->value));
		}
		else
		{
			write(2, "exit: ", 6);
			write(2, p->value, ft_strlen(p->value));
			write(2, ": numeric argument required\n", 28);
			exit(255);
		}
	}
	exit(0);
}
