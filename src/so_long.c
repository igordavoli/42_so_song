/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:15:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/08 21:12:54 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *map_arg)
{
	game->map = NULL;
	game->moves = 0;
	game->hero_coins = 0;
	game->map_c = 0;
	game->map_exits = 0;
	game->map_start = 0;
	game->img_height = 0;
	game->img_width = 0;
	game->err_code = 0;
	game->map = NULL;
	ft_get_map(game, map_arg);
	game->mlx = mlx_init();
	ft_get_sprites(game);
	game->win = mlx_new_window(game->mlx, game->map_width * RES,
			game->map_height * RES, "so_long");
	ft_put_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_args(argc, argv);
	game_init(&game, argv[1]);
	mlx_hook(game.win, CLOSE_WIN_EVENT, 1, &ft_close, &game);
	mlx_hook(game.win, KEY_EVENT, 1, &key_handler, &game);
	mlx_loop(game.mlx);
}
