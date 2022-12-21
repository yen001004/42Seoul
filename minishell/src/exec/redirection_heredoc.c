/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:11:08 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 18:00:02 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*make_temp_file(void)
{
	int			temp;
	char		*temp_file;
	struct stat	buf;
	char		*full_file;

	temp = 0;
	while (1)
	{
		temp_file = ft_itoa(temp);
		if (temp_file == 0)
			exit(1);
		full_file = ft_strjoin("/tmp/", temp_file);
		if (full_file == 0)
			exit(1);
		free(temp_file);
		if (lstat(full_file, &buf) == -1)
			break ;
		free(full_file);
		temp++;
	}
	return (full_file);
}

void	readline_heredoc(t_node *p, int new_fd)
{
	char		*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strncmp(line, p->next->value, ft_strlen(p->next->value) + 1))
		{
			free(line);
			break ;
		}
		write(new_fd, line, ft_strlen(line));
		write(new_fd, "\n", 1);
		free(line);
	}
}

int	heredoc(t_node *p, int *infd)
{
	int			new_fd;
	char		*temp_file;

	temp_file = make_temp_file();
	new_fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (new_fd == -1)
		return (1);
	readline_heredoc(p, new_fd);
	close(new_fd);
	new_fd = open(temp_file, O_RDONLY, 0644);
	close(*infd);
	*infd = new_fd;
	free(temp_file);
	return (0);
}
