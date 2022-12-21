/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_etc_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:11:18 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/25 22:40:40 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**malloc_and_set(char ***argv, t_deque *tokens, char ***envp)
{
	int		cnt;
	char	**path;
	char	*env_path;
	t_deque	*envs;

	cnt = redir_cnt(tokens);
	*argv = (char **)ft_malloc(sizeof(char *) * (tokens->cnt - cnt + 1));
	envs = (t_deque *)env_manage(ENV_ALL, 0, 0);
	*envp = (char **)ft_malloc(sizeof(char *) * (envs->cnt + 1));
	get_argv(*argv, tokens);
	get_envp(*envp, envs);
	env_path = env_manage(ENV_GET, "PATH", 0);
	path = ft_split(env_path, ':');
	return (path);
}

static void	get_exec_path(int i, char **path, char **argv, char **exec_path)
{
	char		*temp;

	temp = ft_strjoin(path[i], "/");
	*exec_path = ft_strjoin(temp, argv[0]);
	free(temp);
}

static void	write_free(char ***argv, char ***envp, char ***path, t_deque *t)
{
	write(2, t->head->value, ft_strlen(t->head->value));
	write(2, ": command not found\n", 20);
	if (*argv != 0)
		ft_double_free(*argv);
	if (*envp != 0)
		ft_double_free(*envp);
	if (*path != 0)
		ft_double_free(*path);
	exit(127);
}

static int	period_check(t_node *p)
{
	if (p->value)
	{
		if (ft_strncmp(p->value, "..", 3) == 0)
		{
			write(2, "..: command not found\n", 22);
			return (1);
		}
		if (ft_strncmp(p->value, ".", 2) == 0)
		{
			write(2, ".: command not found\n", 21);
			return (1);
		}
	}
	return (0);
}

void	exec_etc_child(t_deque *tokens, int i)
{
	struct stat	buf;
	char		*exec_path;
	char		**path;
	char		**argv;
	char		**envp;

	if (period_check(tokens->head))
		exit(127);
	path = malloc_and_set(&argv, tokens, &envp);
	i = 0;
	while (path && path[i] != 0)
	{
		get_exec_path(i, path, argv, &exec_path);
		if (lstat(exec_path, &buf) == 0)
			execve(exec_path, argv, envp);
		else
			i++;
		free(exec_path);
	}
	if (lstat(argv[0], &buf) == 0)
		execve(argv[0], argv, envp);
	else
		write_free(&argv, &envp, &path, tokens);
}
