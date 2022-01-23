/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:44:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 01:37:34 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_sprite(t_game *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, x * RES, y * RES);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * RES, y * RES);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin, x * RES, y * RES);
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->hero, x * RES, y * RES);
		game->hero_x = x;
		game->hero_y = y;
	}
}

void	ft_put_map(t_game *game)
{

	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_put_sprite(game, game->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
