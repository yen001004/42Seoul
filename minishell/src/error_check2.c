/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:13:39 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/26 15:53:58 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_empty_quote(t_block *p)
{
	char	*question_mark;
	char	*result_code_str;

	if (p->value && ft_strlen(p->value) >= 2)
	{
		if (((p->value[0] == '\'' && p->value[1] == '\'')
				|| (p->value[0] == '"' && p->value[1] == '"'))
			&& (p->value[2] == 0 || p->value[2] == '\t' || p->value[2] == ' '))
		{
			write(2, " : command not found\n", 21);
			question_mark = ft_strdup("?");
			result_code_str = ft_itoa(127);
			env_manage(ENV_QUESTION_MARK, question_mark, result_code_str);
			return (1);
		}
	}
	return (0);
}

int	check_empty_line(t_block *p)
{
	int	i;

	if (check_empty_quote(p))
		return (1);
	if (p->tokens.cnt == 0 && p->next == 0)
		return (1);
	if (p->tokens.head->value[0] == 0 && p->next == 0)
		return (1);
	if (p->next == 0)
	{
		i = 0;
		while (p->value[i] != 0)
		{
			if (p->value[i] != ' ' && p->value[i] != '\t')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
