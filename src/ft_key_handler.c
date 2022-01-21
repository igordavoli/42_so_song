/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:33:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/20 22:57:39 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_move_hero(int x, int y, t_game *game)
{
	if (game->map.mtx[game->hero.y + y][game->hero.x + x] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass.ref, game->hero.x * game->grass.width, game->hero.y * game->grass.height);
		game->hero.x = game->hero.x + x;
		game->hero.y = game->hero.y + y;
		mlx_put_image_to_window(game->mlx, game->win, game->hero.ref, game->hero.x * game->hero.width, game->hero.y * game->hero.height);
	}
}

int	key_handler(int keycode, void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	if (keycode == ESC_KEY)
		ft_close();
	if (keycode == W_KEY)
		ft_move_hero(0, -1, game);
	if (keycode == A_KEY)
		ft_move_hero(-1, 0, game);
	if (keycode == S_KEY)
		ft_move_hero(0, 1, game);
	if (keycode == D_KEY)
		ft_move_hero(1, 0, game);
	return (0);
}
