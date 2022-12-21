/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:11:46 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:11:47 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	exec_by_redir_num(t_node *p, int *flag, int *infd, int *outfd)
{
	int		redir_num;

	redir_num = get_redir_num(p->value);
	if (redir_num == 1)
		*flag = input_redirection(p, infd);
	else if (redir_num == 2)
		*flag = output_redirection(p, outfd);
	else if (redir_num == 3)
		*flag = heredoc(p, infd);
	else
		*flag = output_append_redirection(p, outfd);
}

static void	write_redir_error_message(t_node *p)
{
	write(2, p->next->value, ft_strlen(p->next->value));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

static int	check_is_redir(t_node **p, int *flag, int *infd, int *outfd)
{
	if (!ft_strncmp((*p)->name, "redir", 6))
	{
		if ((*p)->next == 0 || !ft_strncmp((*p)->next->name, "redir", 6))
		{
			write(2, "syntax error near unexpected token `newline'\n", 45);
			return (258);
		}
		exec_by_redir_num(*p, flag, infd, outfd);
		if (*flag == 1)
		{
			write_redir_error_message(*p);
			return (-1);
		}
		if ((*p)->next == 0)
			return (-1);
		*p = (*p)->next;
	}
	return (0);
}

int	redirection_execute(t_deque *tokens)
{
	t_node	*p;
	int		infd;
	int		outfd;
	int		flag;
	int		ret;

	infd = dup(STDIN_FILENO);
	outfd = dup(STDOUT_FILENO);
	p = tokens->head;
	while (p != 0)
	{
		ret = check_is_redir(&p, &flag, &infd, &outfd);
		if (ret == 258)
			return (258);
		else if (ret == -1)
			break ;
		if (p->next == 0)
			break ;
		p = p->next;
	}
	dup2(infd, STDIN_FILENO);
	close(infd);
	dup2(outfd, STDOUT_FILENO);
	close(outfd);
	return (flag);
}
