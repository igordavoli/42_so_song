/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:15:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/27 01:02:57 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_update(void *_game)
{
	t_game	*game;
	int		i;

	game = (t_game *)_game;
	i = 0;
	while (game->capys[i])
	{
		if (game->capys[i]->x - game->hero_x < 5
			&& game->capys[i]->x - game->hero_x > -5
			&& game->capys[i]->y - game->hero_y < 5
			&& game->capys[i]->y - game->hero_y > -5)
			mlx_put_image_to_window(game->mlx, game->win, game->capy_left,
				game->capys[i]->x * RES, game->capys[i]->y * RES);
		i++;
	}
	return (0);
}

void	game_init(t_game *game, char *map_arg)
{
	game->map = NULL;
	game->moves = 0;
	game->hero_coins = 0;
	game->map_coins = 0;
	game->n_capys = 0;
	game->map_exits = 0;
	game->map_start = 0;
	ft_get_map(game, map_arg);
	game->capys = (t_capy **)malloc(sizeof(t_capy *) * (game->n_capys + 1));
	game->capys[game->n_capys] = NULL;
	printf("n_capys: %d\n", game->n_capys);
	game->mlx = mlx_init();
	ft_get_sprites(game);
	game->win = mlx_new_window(game->mlx, game->map_width * RES,
			game->map_height * RES, "so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_args(argc, argv);
	game_init(&game, argv[1]);
	ft_put_map(&game);
	mlx_hook(game.win, CLOSE_WIN_EVENT, 1, &ft_close, &game);
	mlx_hook(game.win, KEY_EVENT, 1, &key_handler, &game);
	mlx_loop_hook(game.mlx, &ft_update, &game);
	mlx_loop(game.mlx);
}
