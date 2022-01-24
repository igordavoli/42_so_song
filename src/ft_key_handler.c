/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:33:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 23:45:59 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_handler(int keycode, void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	if (keycode == ESC_KEY)
		ft_close_message(game, "close by user", 0);
	if (keycode == W_KEY)
		ft_move_hero(game, 0, -1);
	if (keycode == A_KEY)
		ft_move_hero(game, -1, 0);
	if (keycode == S_KEY)
		ft_move_hero(game, 0, 1);
	if (keycode == D_KEY)
		ft_move_hero(game, 1, 0);
	return (0);
}
