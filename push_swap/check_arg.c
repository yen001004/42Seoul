/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:23:42 by yewolee           #+#    #+#             */
/*   Updated: 2022/08/16 20:40:10 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *arg)
{
	int	i;

	i = 0;
	if (arg == 0)
		return (0);
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while (arg[i] != '\0')
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	is_int(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arg[i++] != 0)
		len++;
	if (arg[0] == '-')
	{
		if (len < 12 && len > 1)
			return (1);
	}
	else
	{
		if (len < 11 && len > 0)
			return (1);
	}
	return (0);
}

void	check_arg(char *av[])
{
	int	i;

	i = 1;
	while (av[i] != 0)
	{
		if (!is_int(av[i]) || !is_num(av[i]))
			print_error();
		i++;
	}
}
