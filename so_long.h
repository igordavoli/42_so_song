/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 23:31:18 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libs/gnl/get_next_line.h"
# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"
# include "so_long_macros.h"

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
	void	*hero;
	void	*grass;
	void	*wall;
	void	*coin;
	void	*exit;
	char	**map;
	int		map_coins;
	int		map_width;
	int		map_height;
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
void	ft_put_map(t_game *_game);
int		key_handler(int keycode, void *game);
int		ft_move_hero(t_game *game, int x, int y);
void	ft_close_message(t_game *game, char *message, int code);
int		ft_close(void *_game);

#endif
