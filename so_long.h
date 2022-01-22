/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/22 15:41:05 by idavoli-         ###   ########.fr       */
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

# ifndef CLOSE_WIN_EVENT
#  define CLOSE_WIN_EVENT 17
# endif

# ifndef KEY_EVENT
#  define KEY_EVENT 2
# endif

# ifndef ESC_KEY
#  define ESC_KEY 65307
# endif

# ifndef W_KEY
#  define W_KEY 119
# endif

# ifndef A_KEY
#  define A_KEY 97
# endif

# ifndef S_KEY
#  define S_KEY 115
# endif

# ifndef D_KEY
#  define D_KEY 100
# endif

typedef struct s_img
{
	void	*ref;
	char	*pixels;
	int		width;
	int		height;
	int		bits;
	int		line;
	int		end;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	char	**mtx;
	int     coins;
	int		x;
	int		y;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		coins_col;
	int		moves;
	t_img	hero;
	t_img	grass;
	t_img	wall;
	t_img	coin;
	t_map	map;
}	t_game;

t_map	ft_get_map(char *map_path);
int		key_handler(int keycode, void *game);
int		ft_close(void);
int		ft_close_error(char *message);
void	ft_put_map(t_game *_game);
void	ft_check_args(int argc, char **argv);
void	ft_get_sprites(t_game *game);
void	ft_check_map(t_map map);
void	ft_load_map(t_map *map, char *map_path);

#endif
