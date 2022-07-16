/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:29:36 by yewolee           #+#    #+#             */
/*   Updated: 2022/07/04 13:30:34 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_opengl/mlx.h"
# include "gnl/get_next_line.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_ESC 53
# define KEY_EVENT_PRESS 2
# define KEY_EVENT_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_image
{
	void	*img;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		wid;
	int		hei;
	int		prev_wid;
	int		is_door;
	int		is_start;
	int		col_cnt;
	int		walk_cnt;
	int		collectible;
	char	*str;
	t_image	character;
	t_image	collect;
	t_image	grass;
	t_image	tree;
	t_image	door;
}	t_game;

void	move(t_game *game, int dir);
int		key_press(int keycode, t_game *game);
int		exit_button(void);
void	error_exit(void);

void	check_wall_row_start(char *line);
void	check_wall_col(int wid, char *line);
void	check_wall_row_end(t_game *game);
void	check_map_elements(t_game *game);
void	map_read(t_game *game, char *filename);

void	game_init(t_game *game);
void	set_mlx_img(t_game *game);
void	mlx_put(t_game *game, void *img, int w, int h);
void	setting_img(t_game *game);

char	*ft_strdup_nonl(char *str);
char	*ft_strjoin_nonl(char *s1, char *s2);

#endif
