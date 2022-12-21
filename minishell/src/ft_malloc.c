/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:29 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:09:30 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_t_node(t_node *p)
{
	if (p == 0)
		return ;
	if (p->name != 0)
		free(p->name);
	if (p->value != 0)
		free(p->value);
	if (p != 0)
		free(p);
}

void	*ft_malloc(size_t size)
{
	void	*p;

	p = (void *)malloc(size);
	if (p == 0)
		exit(1);
	return (p);
}

void	ft_double_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != 0)
	{
		free(strs[i]);
		strs[i] = 0;
		i++;
	}
	free(strs);
	strs = 0;
}

void	null_check_exit(void *p)
{
	if (p == 0)
		exit(1);
}
