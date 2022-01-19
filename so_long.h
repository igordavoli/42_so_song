/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/19 01:34:08 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "libs/gnl/get_next_line.h"
#include "libs/libft/libft.h"
#include "libs/mlx/mlx.h"

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
# define D_KEY 100
# endif

typedef struct	s_img
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
} t_img;

typedef struct	s_map
{
	char	**mtx;
	int		x;
	int		y;
} t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
} t_game;

t_map	ft_get_map(char *map_path);
t_img	ft_new_sprite(void *mlx, char *sprite);
int		key_handler(int keycode, void *game);
int		ft_close(void);
#endif
