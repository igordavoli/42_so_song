/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/16 21:31:46 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libs/gnl/get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include "so_long_defines_bonus.h"

typedef struct s_capy
{
	void	*curr_sprite;
	int		x;
	int		y;
}	t_capy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		hero_coins;
	int		hero_x;
	int		hero_y;
	int		moves;
	int		img_width;
	int		img_height;
	void 	*h_curr_sprite;
	void	*capy_lay;
	void	*capy_front;
	void	*capy_back;
	void	*capy_left;
	void	*capy_right;
	void	*hero_front;
	void	*hero_back;
	void	*hero_left;
	void	*hero_right;
	void	*grass;
	void	*wall;
	void	*coin;
	void	*exit;
	char	**map;
	int		map_c;
	int		map_width;
	int		map_height;
	int		map_exits;
	int		map_start;
	int		n_capys;
	t_capy	**capys;
	void	**numbers;
	int		err_code;
}	t_game;

void	ft_check_args(int argc, char **argv);
void	ft_get_map(t_game *game, char *map_path);
void	ft_load_map(t_game *game, char *map_path);
void	ft_check_map(t_game *game);
void	ft_check_map_items(t_game *game);
void	ft_check_map_walls(t_game *game);
void	ft_check_map_lines(t_game *game);
void	ft_check_map_chars(t_game *game);
void	ft_get_sprites(t_game *game);
int		ft_put_map(void *_game);
int		key_handler(int keycode, void *game);
int		ft_move_hero(t_game *game, int x, int y, void *hero_sprite);
void	ft_close_message(t_game *game, char *message, int code);
int		ft_close(void *_game);

#endif
