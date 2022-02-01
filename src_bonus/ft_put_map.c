/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:44:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/30 21:43:23 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_capy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->capy_lay, x * RES,
		y * RES);
	game->n_capys--;
	game->capys[game->n_capys] = (t_capy *)malloc(sizeof(t_capy));
	game->capys[game->n_capys]->x = x;
	game->capys[game->n_capys]->y = y;
}

void	ft_put_sprite(t_game *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, x * RES,
			y * RES);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * RES,
			y * RES);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin, x * RES,
			y * RES);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x * RES,
			y * RES);
	if (c == 'A')
		ft_put_capy(game, x, y);
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->hero_front, x * RES,
			y * RES);
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
