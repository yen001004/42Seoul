/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:24 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:54:30 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	str_push(char *dst, char *src, int cnt)
{
	int	i;
	int	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (i < cnt)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
}

int	replace_str(char **original, char *insert, int start, int end)
{
	char	*new_str;
	int		original_len;
	int		insert_len;
	int		next_idx;

	original_len = ft_strlen(*original);
	if (!insert)
		insert_len = 0;
	else
		insert_len = ft_strlen(insert);
	new_str = (char *)ft_malloc(original_len - (end - start) + insert_len + 1);
	new_str[0] = 0;
	str_push(new_str, *original, start);
	str_push(new_str, insert, insert_len);
	next_idx = ft_strlen(new_str);
	str_push(new_str, (*original) + end, original_len - end);
	free(*original);
	*original = new_str;
	return (next_idx);
}

static int	replace_env_to_value(int *idx, char **str)
{
	int		l;
	char	*env_key;
	char	*env_val;

	l = (*idx) + 1;
	while ((*str)[l])
	{
		if ('?' == (*str)[l])
		{
			l++;
			break ;
		}
		if (!((('0' <= (*str)[l] && (*str)[l] <= '9') && l != ((*idx) + 1))
		|| ('a' <= (*str)[l] && (*str)[l] <= 'z')
		|| ('A' <= (*str)[l] && (*str)[l] <= 'Z')
		|| ('_' == (*str)[l])))
			break ;
		l++;
	}
	env_key = ft_substr(*str, (*idx) + 1, l - (*idx) - 1);
	null_check_exit(env_key);
	env_val = (char *)env_manage(ENV_GET, env_key, 0);
	(*idx) = replace_str(str, env_val, (*idx), l);
	free(env_key);
	return (0);
}

int	is_val_quote(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*replace_env_variable(char *str)
{
	int		i;
	int		quote_flag;

	i = 0;
	quote_flag = 0;
	while (str[i])
	{
		if (str[i] == '"' && quote_flag)
			quote_flag = 0;
		else if ((str[i] == '"') && is_val_quote(str + i + 1, '"'))
			quote_flag = 1;
		if (!quote_flag && (str[i] == '\'') && is_val_quote(str + i + 1, '\''))
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		else if (str[i] == '$')
			replace_env_to_value(&i, &str);
		else
			i++;
	}
	return (str);
}
