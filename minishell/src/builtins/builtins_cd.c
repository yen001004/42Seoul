/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:53 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:09:53 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_pwd(char *nwd)
{
	char	*pwd;

	pwd = (char *)ft_malloc(sizeof(char) * 4);
	str_push(pwd, "PWD", 3);
	env_manage(ENV_EXPORT, pwd, nwd);
}

static void	nwd_str_push(char *nwd, char *cwd, t_node *path)
{
	int		len_cwd;
	int		len_path;

	len_cwd = ft_strlen(cwd);
	len_path = ft_strlen(path->value);
	str_push(nwd, cwd, len_cwd);
	str_push(nwd, "/", 1);
	str_push(nwd, path->value, len_path);
}

static int	chdir_nwd(char **cwd, t_node *path, char **nwd)
{
	int		len_cwd;
	int		len_path;

	len_cwd = ft_strlen(*cwd);
	len_path = ft_strlen(path->value);
	*nwd = (char *)malloc(sizeof(char) * (len_cwd + len_path + 2));
	(*nwd)[0] = 0;
	nwd_str_push(*nwd, *cwd, path);
	free(*cwd);
	if (chdir(*nwd) == -1)
	{
		free(*nwd);
		return (1);
	}
	print_pwd(*nwd);
	return (0);
}

int	builtins_cd(t_deque *tokens)
{
	int		ret;
	char	*cwd;
	char	*nwd;
	t_node	*path;

	path = tokens->head->next;
	if (path == 0)
		return (0);
	if (path->value[0] != '/')
	{
		cwd = getcwd(0, 0);
		if (!cwd)
			return (0);
		ret = chdir_nwd(&cwd, path, &nwd);
		if (ret)
			return (1);
	}
	else
	{
		if (chdir(path->value) == -1)
			return (1);
		nwd = ft_strdup(path->value);
		print_pwd(nwd);
	}
	return (0);
}
