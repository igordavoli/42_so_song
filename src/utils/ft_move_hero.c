/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:00:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/25 23:49:10 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_exec_move(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass,
		game->hero_x * RES, game->hero_y * RES);
	game->hero_x = game->hero_x + x;
	game->hero_y = game->hero_y + y;
	mlx_put_image_to_window(game->mlx, game->win, game->hero,
		game->hero_x * RES, game->hero_y * RES);
}

static void	ft_collect(t_game *game, int x, int y)
{
	game->hero_coins++;
	game->map[game->hero_y + y][game->hero_x + x] = '0';
	game->map_coins--;
}

int	ft_move_hero(t_game *game, int x, int y)
{
	if (game->map[game->hero_y + y][game->hero_x + x] == '1')
		return (0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'E' && game->map_coins)
		return (0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'E' && !game->map_coins)
		ft_close_message(game, "You win!", 0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'C')
		ft_collect(game, x, y);
	ft_exec_move(game, x, y);
	printf("%d\n", ++game->moves);
	return (0);
}
