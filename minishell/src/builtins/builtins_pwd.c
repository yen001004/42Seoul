/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:10:17 by hyujang           #+#    #+#             */
/*   Updated: 2022/11/22 17:10:18 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtins_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	if (!pwd)
		return (0);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
