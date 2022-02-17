/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:00:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/16 20:24:18 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_exec_move(t_game *game, int x, int y, void *hero_sprite)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass,
		game->hero_x * RES, game->hero_y * RES);
	game->map[game->hero_y][game->hero_x] = '0';
	game->hero_x = game->hero_x + x;
	game->hero_y = game->hero_y + y;
	game->map[game->hero_y][game->hero_x] = 'P';
	game->h_curr_sprite = hero_sprite;
	mlx_put_image_to_window(game->mlx, game->win, hero_sprite,
		game->hero_x * RES, game->hero_y * RES);
}

static void	ft_collect(t_game *game, int x, int y)
{
	game->hero_coins++;
	game->map[game->hero_y + y][game->hero_x + x] = '0';
	game->map_c--;
}

int	ft_move_hero(t_game *game, int x, int y, void *hero_sprite)
{
	mlx_put_image_to_window(game->mlx, game->win, hero_sprite,
		game->hero_x * RES, game->hero_y * RES);
	if (game->map[game->hero_y + y][game->hero_x + x] == '1')
		return (0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'E' && game->map_c)
		return (0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'A')
		ft_close_message(game, "You lose!", 0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'E' && !game->map_c)
		ft_close_message(game, "You win!", 0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'C')
		ft_collect(game, x, y);
	ft_exec_move(game, x, y, hero_sprite);
	printf("%d\n", ++game->moves);
	return (0);
}
