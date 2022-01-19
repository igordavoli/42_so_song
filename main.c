/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:15:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/19 01:30:55 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_update(void *game)
{
	t_game *_game = (t_game *)game;
	mlx_put_image_to_window(_game->mlx, _game->win, _game->img.ref, _game->img.x, _game->img.y);
	return (0);
}

int main()
{
	t_game	game;
	game.map = ft_get_map("maps/map.ber");
	game.mlx = mlx_init();
	game.img = ft_new_sprite(game.mlx, "assets/p_front.xpm");
	game.win = mlx_new_window(game.mlx, game.map.x * game.img.width, game.map.y * game.img.height, "so_long");
	mlx_hook( game.win, CLOSE_WIN_EVENT, 1, &ft_close, &game);
	mlx_hook( game.win, KEY_EVENT, 1, &key_handler, &game);
	mlx_loop_hook(game.mlx, &ft_update, &game);
	mlx_loop( game.mlx);
}
