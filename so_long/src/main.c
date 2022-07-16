/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:27:02 by yewolee           #+#    #+#             */
/*   Updated: 2022/06/29 18:44:02 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(t_game *game, int dir)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
		i++;
	}
	if (game->str[i + dir] == 'C')
	{
		game->col_cnt++;
	}
	if (game->str[i + dir] == 'E' && game->col_cnt == game->collectible)
		exit(0);
	else if (game->str[i + dir] != '1' && game->str[i + dir] != 'E')
	{
		game->str[i] = '0';
		game->str[i + dir] = 'P';
		game->walk_cnt++;
		printf("walk : %d\n", game->walk_cnt);
		setting_img(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move(game, game->wid * -1);
	else if (keycode == KEY_A)
		move(game, -1);
	else if (keycode == KEY_S)
		move(game, game->wid);
	else if (keycode == KEY_D)
		move(game, 1);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	exit_button(void)
{
	exit(0);
}

void	error_exit(void)
{
	printf("Error\n");
	exit(0);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		error_exit();
	game.mlx = mlx_init();
	game_init(&game);
	map_read(&game, av[1]);
	check_wall_row_end(&game);
	check_map_elements(&game);
	game.win = mlx_new_window(game.mlx, game.wid * 64, game.hei * 64, "finn");
	set_mlx_img(&game);
	setting_img(&game);
	mlx_hook(game.win, KEY_EVENT_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, KEY_EVENT_EXIT, 0, &exit_button, &game);
	mlx_loop(game.mlx);
	return (0);
}
