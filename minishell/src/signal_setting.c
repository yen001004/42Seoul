/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:36 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/26 14:56:32 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sig_handler(int signal)
{
	char	*question_mark;
	char	*result_code_str;

	if (signal == SIGINT)
	{
		question_mark = ft_strdup("?");
		if (flag_set_test(1, 1) == 0)
		{
			write(1, "^C", 2);
			result_code_str = ft_itoa(130);
			env_manage(ENV_QUESTION_MARK, question_mark, result_code_str);
			flag_set_test2(0, 0);
		}
		else
		{
			result_code_str = ft_itoa(1);
			env_manage(ENV_QUESTION_MARK, question_mark, result_code_str);
		}
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		if (flag_set_test(0, 1))
			rl_redisplay();
	}
}

void	sig_handler2(int signal)
{
	char	*question_mark;
	char	*result_code_str;

	if (signal == SIGQUIT)
	{
		if (flag_set_test(1, 1) == 0)
		{
			question_mark = ft_strdup("?");
			write(1, "^\\Quit: 3\n", 10);
			result_code_str = ft_itoa(131);
			env_manage(ENV_QUESTION_MARK, question_mark, result_code_str);
			flag_set_test2(0, 0);
		}
	}
}

void	set_signal(void)
{
	if (flag_set_test(1, 1) == 1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_handler);
	}
	else
	{
		signal(SIGQUIT, sig_handler2);
		signal(SIGINT, sig_handler);
	}
}

int	flag_set_test(int set_flag, int test)
{
	static int	flag = 1;

	if (test)
		return (flag);
	else
		flag = set_flag;
	return (flag);
}

int	flag_set_test2(int set_flag, int test)
{
	static int	flag = 1;

	if (test)
		return (flag);
	else
		flag = set_flag;
	return (flag);
}
