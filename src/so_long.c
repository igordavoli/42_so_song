/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:15:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 01:49:24 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	ft_get_map(&game, argv[1]);
	game.moves = 0;
	game.hero_coins = 0;
	game.mlx = mlx_init();
	ft_get_sprites(&game);
	game.win = mlx_new_window(game.mlx, game.map_width * game.img_width, game.map_height * game.img_height, "so_long");
	ft_put_map(&game);
	mlx_hook(game.win, CLOSE_WIN_EVENT, 1, &ft_close, &game);
	mlx_hook(game.win, KEY_EVENT, 1, &key_handler, &game);
	// mlx_loop_hook(game.mlx, &ft_update, &game);
	mlx_loop(game.mlx);
}
