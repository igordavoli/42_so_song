/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:33:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/19 04:09:14 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_handler(int keycode, void *game)
{
    t_game *_game = (t_game *)game;
	t_img	_void;

	_void.ref =  mlx_new_image(_game->mlx, 16, 16);
	_void.pixels = mlx_get_data_addr(_void.ref, &_void.bits, &_void.line, &_void.end);

	if (keycode == ESC_KEY)
		ft_close();
	if (keycode == W_KEY)
    {
		printf("w\n");
		mlx_put_image_to_window(_game->mlx, _game->win, _void.ref, _game->img.x, _game->img.y);
        _game->img.y -= _game->img.height;
    }
	if (keycode == A_KEY)
    {
		printf("a\n");
		mlx_put_image_to_window(_game->mlx, _game->win, _void.ref, _game->img.x, _game->img.y);
		_game->img.x -= _game->img.width;
    }
	if (keycode == S_KEY)
    {
		printf("s\n");
		mlx_put_image_to_window(_game->mlx, _game->win, _void.ref, _game->img.x, _game->img.y);
		_game->img.y += _game->img.height;
    }
	if (keycode == D_KEY)
    {
	    printf("d\n");

		mlx_put_image_to_window(_game->mlx, _game->win, _void.ref, _game->img.x, _game->img.y);
		_game->img.x += _game->img.width;
    }
	return (0);
}
