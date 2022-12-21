/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:13:15 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 20:10:17 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_pipe_idx(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '|')
			return (i);
		if (line[i] == '"' && is_val_quote(line + i + 1, '"'))
		{
			i++;
			while (line[i] != '"')
				i++;
		}
		else if (line[i] == '\'' && is_val_quote(line + i + 1, '\''))
		{
			i++;
			while (line[i] != '\'')
				i++;
		}
		i++;
	}
	return (-1);
}

static char	*get_block_value(char *line, int idx)
{
	char	*value;

	value = ft_substr(line, 0, idx);
	return (value);
}

static char	*get_next_cmd(char *line, int idx)
{
	int		len;
	char	*temp;

	len = ft_strlen(line);
	temp = ft_substr(line, idx + 1, len - 1);
	free(line);
	return (temp);
}

static void	set_block_and_token(char *buffer, int idx, t_blocklist *blocks)
{
	t_block	*new_block;

	new_block = make_block(get_block_value(buffer, idx));
	append_block_tail(blocks, new_block);
	init_tokens(new_block);
}

void	get_exec_blocks(t_blocklist *blocks, char *line)
{
	int		idx;
	char	*buffer;

	buffer = ft_strdup(line);
	while (1)
	{
		idx = get_pipe_idx(buffer);
		if (idx == -1)
			break ;
		set_block_and_token(buffer, idx, blocks);
		buffer = get_next_cmd(buffer, idx);
	}
	if (buffer != 0)
	{
		set_block_and_token(buffer, idx, blocks);
	}
	free(buffer);
}
