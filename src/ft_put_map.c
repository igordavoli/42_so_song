/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:44:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/22 13:37:27 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_sprite(t_game *_game, char c, int x, int y)
{
	t_game	*game;

	game = (t_game *) _game;
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass.ref, x * game->grass.width, y * game->grass.height);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.ref, x * game->grass.width, y * game->grass.height);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin.ref, x * game->grass.width, y * game->grass.height);
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->hero.ref, x * game->hero.width, y * game->hero.height);
		game->hero.x = x;
		game->hero.y = y;
	}
}

void	ft_put_map(t_game *_game)
{
	char	**map;
	t_game	*game;
	int		i;
	int		j;

	game = (t_game *)_game;
	map = game->map.mtx;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_put_sprite(game, map[i][j], j, i);
			j++;
		}
		i++;
	}
}
