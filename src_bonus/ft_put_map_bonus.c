/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:44:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/16 23:30:01 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->h_curr_sprite,
			x * RES, y * RES);
		game->hero_x = x;
		game->hero_y = y;
	}
}

void	ft_put_caps(t_game *game)
{
	int		n;

	n = 0;
	while (game->capys[n])
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->capys[n]->curr_sprite[0], game->capys[n]->x * RES,
			game->capys[n]->y * RES);
		n++;
	}
}

int	ft_put_map(void *_game)
{
	int		i;
	int		j;
	t_game	*game;

	game = (t_game *)_game;
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
	ft_put_caps(game);
	return (0);
}
