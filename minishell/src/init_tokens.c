/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:12 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 21:32:17 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*set_redir_str(char *str, int r_idx, char **redirection)
{
	char	*file_name;
	int		redir_cnt;

	redir_cnt = 0;
	file_name = 0;
	redir_cnt = redir_one_or_two(str, r_idx);
	if (redir_cnt == 1)
		(*redirection) = (char *)ft_malloc(sizeof(char) * 2);
	else
		(*redirection) = (char *)ft_malloc(sizeof(char) * 3);
	(*redirection)[0] = str[r_idx];
	if (redir_cnt == 1)
	{
		(*redirection)[1] = 0;
		if (str[r_idx + 1] != 0)
			file_name = ft_substr(str, r_idx + 1, ft_strlen(str) - r_idx - 1);
	}
	else
	{
		(*redirection)[1] = str[r_idx + 1];
		(*redirection)[2] = 0;
		if (str[r_idx + 2] != 0)
			file_name = ft_substr(str, r_idx + 2, ft_strlen(str) - r_idx - 2);
	}
	return (file_name);
}

void	cmd_append(int redir_idx, char *str, t_block *block)
{
	char	*cmd_str;

	if (redir_idx != 0)
	{
		cmd_str = ft_substr(str, 0, redir_idx);
		append_tail(&(block->tokens), make_node(0, cmd_str));
	}
}

void	redir_append(char *file_name, char *redirection, t_block *block)
{
	append_tail(&(block->tokens), make_node(0, redirection));
	if (file_name && file_name[0] != 0)
		append_tail(&(block->tokens), make_node(0, file_name));
}

void	init_tokens(t_block *block)
{
	int		i;
	char	**token_strs;
	int		redir_idx;
	char	*redirection;
	char	*file_name;

	i = 0;
	init_deque(&(block->tokens));
	block->value = replace_env_variable(block->value);
	token_strs = ft_split_argv(block->value, ' ');
	while (token_strs[i] != 0)
	{
		redir_idx = check_redirection(&token_strs[i]);
		if (redir_idx != -1)
		{
			file_name = set_redir_str(token_strs[i], redir_idx, &redirection);
			cmd_append(redir_idx, token_strs[i], block);
			redir_append(file_name, redirection, block);
			free(token_strs[i]);
		}
		else
			append_tail(&(block->tokens), make_node(0, token_strs[i]));
		i++;
	}
	free(token_strs);
}
