/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:18 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/23 00:48:42 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	word_len_argv(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] != c) && (str[i] != '\t'))
		i++;
	return (i);
}

int	word_len2_argv(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] != c) && (str[i] != '\t'))
	{
		if ((str[i] == '"') && is_val_quote(str + i + 1, '"'))
			break ;
		if ((str[i] == '\'') && is_val_quote(str + i + 1, '\''))
			break ;
		i++;
	}
	return (i);
}

int	word_count_argv(char const *str, char c)
{
	int	cnt;
	int	len;

	cnt = 0;
	while (*str != '\0')
	{
		while (*str == c || *str == '\t')
			str++;
		if ((*str == '"' && is_val_quote(str + 1, '"'))
			|| (*str == '\'' && is_val_quote(str + 1, '\'')))
		{
			str++;
			len = word_len_argv(str, *(str - 1));
			str += len + 1;
			cnt++;
		}
		else if (*str)
		{
			len = word_len2_argv(str, c);
			str += len;
			cnt++;
		}
	}
	return (cnt);
}

char	*word_copy_argv(char const *str, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)ft_malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (str[i] != '\0' && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
