/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:15:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/20 07:03:02 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int ft_update(void *_game)
// {
// 	t_game *game;

// 	game = (t_game *)_game;

// 	return (0);
// }

int main(int argc, char **argv)
{
	t_game	game;

	ft_check_args(argc, argv);
	game.map = ft_get_map(argv[1]);
	game.mlx = mlx_init();
	game.hero = ft_new_sprite(game.mlx, "assets/p_front.xpm");
	game.grass = ft_new_sprite(game.mlx, "assets/grass.xpm");
	game.wall = ft_new_sprite(game.mlx, "assets/wall.xpm");
	game.win = mlx_new_window(game.mlx, game.map.x * game.hero.width, game.map.y * game.hero.height, "so_long");
	ft_put_map(&game);
	mlx_hook(game.win, CLOSE_WIN_EVENT, 1, &ft_close, &game);
	mlx_hook(game.win, KEY_EVENT, 1, &key_handler, &game);
	// mlx_loop_hook(game.mlx, &ft_update, &game);
	mlx_loop(game.mlx);
}
