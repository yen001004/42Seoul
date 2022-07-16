/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:35:21 by yewolee           #+#    #+#             */
/*   Updated: 2022/07/04 13:31:15 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_wall_row_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			error_exit();
		i++;
	}
}

void	check_wall_col(int wid, char *line)
{
	if (line[0] != '1' || line[wid - 1] != '1')
		error_exit();
}

void	check_wall_row_end(t_game *game)
{
	int	i;

	i = game->wid * game->hei - 1;
	while (i > game->wid * (game->hei - 1) - 1)
	{
		if (game->str[i] != '1')
			error_exit();
		i--;
	}
}

void	check_map_elements(t_game *game)
{
	int	i;

	i = 0;
	while (game->str[i] != '\0')
	{
		if (game->str[i] == 'C')
			game->collectible++;
		i++;
	}
	i = 0;
	while (game->str[i] != '\0')
	{
		if (game->str[i] == 'E')
			game->is_door++;
		i++;
	}
	i = 0;
	while (game->str[i] != '\0')
	{
		if (game->str[i] == 'P')
			game->is_start++;
		i++;
	}
	if (game->collectible == 0 || game->is_door == 0 || game->is_start != 1)
		error_exit();
}

void	map_read(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0)
		error_exit();
	check_wall_row_start(line);
	game->str = ft_strdup_nonl(line);
	while (line != 0)
	{
		game->prev_wid = ft_strlen(line) - 1;
		line = get_next_line(fd);
		if (line != 0)
		{
			game->wid = ft_strlen(line) - 1;
			check_wall_col(game->wid, line);
			temp = ft_strjoin_nonl(game->str, line);
			game->str = temp;
			game->hei++;
			if (game->prev_wid != game->wid)
				error_exit();
		}
	}
}
