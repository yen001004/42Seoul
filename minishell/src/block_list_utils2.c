/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_list_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:00 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:08:01 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_all_block(t_blocklist *blocklist)
{
	t_block	*p;

	printf("------ block ------\n");
	printf("[head]\n");
	p = blocklist->head;
	while (p)
	{
		printf("[%s]\n", p->value);
		p = p->next;
	}
	printf("[tail]\n");
}

void	free_all_block(t_blocklist *blocklist)
{
	while (1)
	{
		if (del_block_tail(blocklist) == 0)
			break ;
	}
}
