/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:54:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/31 21:41:59 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_get_sprite(t_game *game, char *sprite)
{
	return (mlx_xpm_file_to_image(game->mlx, sprite, &game->img_width,
			&game->img_height));
}

static void	ft_load_hero_sprites(t_game *game)
{
	game->hero_front = ft_get_sprite(game, H_FRONT_XPM);
	game->hero_back = ft_get_sprite(game, H_BACK_XPM);
	game->hero_left = ft_get_sprite(game, H_LEFT_XPM);
	game->hero_right = ft_get_sprite(game, H_RIGHT_XPM);
}

void	ft_get_sprites(t_game *game)
{
	game->grass = ft_get_sprite(game, GRASS_XPM);
	game->wall = ft_get_sprite(game, WALL_XPM);
	game->coin = ft_get_sprite(game, COIN_XPM);
	game->exit = ft_get_sprite(game, EXIT_XPM);
	ft_load_hero_sprites(game);
}
