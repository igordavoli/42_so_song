/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:15:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/19 03:45:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_update(void *game)
{
	t_game *_game = (t_game *)game;
	mlx_put_image_to_window(_game->mlx, _game->win, _game->img.ref, _game->img.x, _game->img.y);
	return (0);
}

void ft_get_map(char *map_path)
{
	int		map_fd;
	int		i;
	char    *tmp;
	char	**map;

	map_fd = open(map_path, O_RDONLY);
	i = 0;
	while(1)
	{
		tmp = get_next_line(map_fd);
		if(!tmp)
			break ;
		free(tmp);
		i++;
	}
	close(map_fd);
	map_fd = open(map_path, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while(1)
	{
		map[i] = get_next_line(map_fd);
		if (!map[i++])
			break ;
	}
}

int main()
{
	t_game	game;

	ft_get_map("maps/map.ber");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 320, 320, "so_long");
	game.img = ft_new_sprite(game.mlx, "assets/p_front.xpm");
	mlx_hook( game.win, 17, 1, &ft_close, &game);
	mlx_hook( game.win, 2, 0, &key_handler, &game);
	mlx_loop_hook(game.mlx, &ft_update, &game);
	mlx_loop( game.mlx);
}
