/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yen <yen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:08 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 20:54:50 by yen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static const char	*set_strs(char const *s, char **strs, int idx, char c)
{
	if (*s == '"' && is_val_quote(s + 1, '"'))
	{
		s++;
		strs[idx] = word_copy_argv(s - 1, word_len_argv(s, '"') + 2);
		s += word_len_argv(s, '"') + 1;
	}
	else if (*s == '\'' && is_val_quote(s + 1, '\''))
	{
		s++;
		strs[idx] = word_copy_argv(s - 1, word_len_argv(s, '\'') + 2);
		s += word_len_argv(s, '\'') + 1;
	}
	else if (*s)
	{
		strs[idx] = word_copy_argv(s, word_len2_argv(s, c));
		s += word_len2_argv(s, c);
	}
	return (s);
}

char	**ft_split_argv(char const *s, char c)
{
	int		i;
	int		wcnt;
	char	**strs;

	if (s == 0)
		return (0);
	i = 0;
	wcnt = word_count_argv(s, c);
	strs = (char **)ft_malloc(sizeof(char *) * (wcnt + 1));
	if (strs == 0)
		return (0);
	while (i < wcnt)
	{
		while (*s == c || *s == '\t')
			s++;
		s = set_strs(s, strs, i, c);
		if (strs[i++] == 0)
		{
			ft_double_free(strs);
			return (0);
		}
	}
	strs[i] = 0;
	return (strs);
}
