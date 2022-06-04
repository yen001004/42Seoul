/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:33:04 by yewolee           #+#    #+#             */
/*   Updated: 2022/05/11 13:39:39 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*strcut(char **str, int idx)
{
	int		i;
	char	*s;
	char	*temp;

	i = 0;
	s = (char *)malloc(sizeof(char) * idx + 2);
	while (i <= idx)
	{
		s[i] = (*str)[i];
		i++;
	}
	s[i] = '\0';
	if (ft_strlen(*str) == idx + 1)
	{
		free(*str);
		*str = 0;
	}
	else
	{
		temp = ft_strdup(*str + (idx + 1));
		free(*str);
		*str = temp;
	}
	return (s);
}

char	*strupdate(int read_size, char *str, char *buf)
{
	char	*temp;

	temp = 0;
	buf[read_size] = '\0';
	if (str == 0)
	{
		str = ft_strdup(buf);
	}
	else
	{
		temp = ft_strdup(str);
		free(str);
		str = ft_strjoin(temp, buf);
		free(temp);
	}
	return (str);
}

char	*get_return(int read_size, char **str)
{
	int	idx;

	idx = 0;
	if (read_size <= 0 && *str == 0)
		return (0);
	idx = check_new_line(*str);
	if (idx >= 0)
		return (strcut(str, idx));
	if (read_size == 0 && *str != 0)
		return (strcut(str, ft_strlen(*str) - 1));
	return (0);
}

char	*get_next_line(int fd)
{
	int			idx;
	char		*buf;
	static char	*str[OPEN_MAX];
	int			read_size;

	if (fd < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == 0)
		return (0);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		str[fd] = strupdate(read_size, str[fd], buf);
		idx = check_new_line(str[fd]);
		if (idx >= 0)
		{
			free(buf);
			return (strcut(&str[fd], idx));
		}
	}
	free(buf);
	return (get_return(read_size, &str[fd]));
}
