/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:17 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:09:18 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_input_mode(struct termios *term)
{
	tcgetattr(STDIN_FILENO, term);
	term->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, term);
}

void	prompt(t_blocklist	*blocks)
{
	char	*line;

	line = readline("\033[32mMinishell>\033[0m ");
	if (line)
	{
		get_exec_blocks(blocks, line);
		add_history(line);
		free(line);
	}
	else
	{
		printf("\033[1A");
		printf("\033[10C");
		printf(" exit\n");
		exit(0);
	}
}

int	main(void)
{
	struct termios	term;
	t_blocklist		blocks;

	set_input_mode(&term);
	set_signal();
	while (1)
	{
		init_blocklist(&blocks);
		prompt(&blocks);
		lexer_blocks(&blocks);
		if (no_error_on_parse(&blocks))
		{
			execute_all_blocks(&blocks);
			if (errno != 0)
			{
				write(2, strerror(errno), ft_strlen(strerror(errno)));
				write(2, "\n", 1);
			}
		}
		free_all_block(&blocks);
	}
	return (0);
}
