/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:11:42 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 21:30:12 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_redir_num(char *value)
{
	if (!ft_strncmp(value, "<", 2))
		return (1);
	else if (!ft_strncmp(value, ">", 2))
		return (2);
	else if (!ft_strncmp(value, "<<", 3))
		return (3);
	else
		return (4);
}

int	input_redirection(t_node *p, int *infd)
{
	int	new_fd;

	new_fd = open(p->next->value, O_RDONLY, 0644);
	if (new_fd == -1)
	{
		return (1);
	}
	close(*infd);
	*infd = new_fd;
	return (0);
}

int	output_redirection(t_node *p, int *outfd)
{
	int	new_fd;

	new_fd = open(p->next->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (new_fd == -1)
		return (1);
	close(*outfd);
	*outfd = new_fd;
	return (0);
}

int	output_append_redirection(t_node *p, int *outfd)
{
	int	new_fd;

	new_fd = open(p->next->value, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (new_fd == -1)
		return (1);
	close(*outfd);
	*outfd = new_fd;
	return (0);
}

char	*remove_quote(char *str)
{
	int		i;
	char	*new_str;
	size_t	len;

	i = 0;
	len = ft_strlen(str) - 2;
	new_str = (char *)ft_malloc(len + 1);
	null_check_exit(new_str);
	i++;
	while (str[i + 1] != 0)
	{
		new_str[i - 1] = str[i];
		i++;
	}
	new_str[i - 1] = 0;
	free(str);
	return (new_str);
}
