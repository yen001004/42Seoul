/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:45:28 by yewolee           #+#    #+#             */
/*   Updated: 2022/06/29 18:43:32 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_init(t_game *game)
{
	game->is_door = 0;
	game->is_start = 0;
	game->col_cnt = 0;
	game->walk_cnt = 0;
	game->collectible = 0;
}

void	set_mlx_img(t_game *game)
{
	int	img_width;
	int	img_height;

	game->grass.img = mlx_xpm_file_to_image(game->mlx, \
			"./img/grass.xpm", &img_width, &img_height);
	game->tree.img = mlx_xpm_file_to_image(game->mlx, \
			"./img/tree.xpm", &img_width, &img_height);
	game->collect.img = mlx_xpm_file_to_image(game->mlx, \
			"./img/collect.xpm", &img_width, &img_height);
	game->door.img = mlx_xpm_file_to_image(game->mlx, \
			"./img/door.xpm", &img_width, &img_height);
	game->character.img = mlx_xpm_file_to_image(game->mlx, \
			"./img/FinnUp.xpm", &img_width, &img_height);
}

void	mlx_put(t_game *game, void *img, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->win, img, w * 64, h * 64);
}

void	setting_img(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->hei)
	{
		w = 0;
		while (w < game->wid)
		{
			mlx_put(game, game->grass.img, w, h);
			if (game->str[h * game->wid + w] == '1')
				mlx_put(game, game->tree.img, w, h);
			else if (game->str[h * game->wid + w] == 'C')
				mlx_put(game, game->collect.img, w, h);
			else if (game->str[h * game->wid + w] == 'E')
				mlx_put(game, game->door.img, w, h);
			else if (game->str[h * game->wid + w] == 'P')
				mlx_put(game, game->character.img, w, h);
			w++;
		}
		h++;
	}
}
