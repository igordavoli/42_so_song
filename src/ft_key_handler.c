/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:33:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/20 06:29:04 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_move_hero(int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass.ref, game->hero.x, game->hero.y);
	game->hero.x = game->hero.x + x;
	game->hero.y = game->hero.y + y;
	mlx_put_image_to_window(game->mlx, game->win, game->hero.ref, game->hero.x, game->hero.y);
}

int	key_handler(int keycode, void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	if (keycode == ESC_KEY)
		ft_close();
	if (keycode == W_KEY)
		ft_move_hero(0, -game->hero.height, game);
	if (keycode == A_KEY)
		ft_move_hero(-game->hero.width, 0, game);
	if (keycode == S_KEY)
		ft_move_hero(0, game->hero.height, game);
	if (keycode == D_KEY)
		ft_move_hero(game->hero.width, 0, game);
	return (0);
}
