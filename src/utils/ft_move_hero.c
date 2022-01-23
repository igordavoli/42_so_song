/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:00:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 02:42:11 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


static void	ft_exec_move(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass,
		game->hero_x * game->img_width, game->hero_y * game->img_height);
	game->hero_x = game->hero_x + x;
	game->hero_y = game->hero_y + y;
	mlx_put_image_to_window(game->mlx, game->win, game->hero,
		game->hero_x * game->img_width, game->hero_y * game->img_height);
}

int	ft_move_hero(t_game *game, int x, int y)
{
	if (game->map[game->hero_y + y][game->hero_x + x] == '1')
		return (0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'E'
		&& game->hero_coins != game->map_coins)
		return (0);
	if ((game->map[game->hero_y + y][game->hero_x + x] == 'E')
		&& (game->hero_coins == game->map_coins))
		ft_close_message(game, "You win!", 0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'C')
		game->hero_coins++;
	printf("%d\n", ++game->moves);
	ft_exec_move(game, x, y);
	return (0);
}
