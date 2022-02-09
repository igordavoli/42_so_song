/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:33:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/08 20:49:03 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_handler(int keycode, void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	if (keycode == ESC_KEY)
		ft_close_message(game, "closed by user", 0);
	if (keycode == W_KEY)
		ft_move_hero(game, 0, -1, game->hero_back);
	if (keycode == A_KEY)
		ft_move_hero(game, -1, 0, game->hero_left);
	if (keycode == S_KEY)
		ft_move_hero(game, 0, 1, game->hero_front);
	if (keycode == D_KEY)
		ft_move_hero(game, 1, 0, game->hero_right);
	return (0);
}
