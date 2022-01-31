/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:54:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/30 03:48:16 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*ft_get_sprite(t_game *game, char *sprite)
{
	return (mlx_xpm_file_to_image(game->mlx, sprite, &game->img_width,
			&game->img_height));
}

static void ft_load_nbrs_sprites(t_game *game)
{
	game->numbers = (void **)malloc(sizeof(void *) * 11);
	game->numbers[10] = NULL;
	game->numbers[0] = ft_get_sprite(game, ZERO_XPM);
	game->numbers[1] = ft_get_sprite(game, ONE_XPM);
	game->numbers[2] = ft_get_sprite(game, TWO_XPM);
	game->numbers[3] = ft_get_sprite(game, THREE_XPM);
	game->numbers[4] = ft_get_sprite(game, FOUR_XPM);
	game->numbers[5] = ft_get_sprite(game, FIVE_XPM);
	game->numbers[6] = ft_get_sprite(game, SIX_XPM);
	game->numbers[7] = ft_get_sprite(game, SEVEN_XPM);
	game->numbers[8] = ft_get_sprite(game, EIGHT_XPM);
	game->numbers[9] = ft_get_sprite(game, NINE_XPM);
}

static void ft_load_capy_sprites(t_game *game)
{
	game->capy_lay = ft_get_sprite(game, CAPY_LAY_XPM);
	game->capy_front = ft_get_sprite(game, CAPY_FRONT_XPM);
	game->capy_back = ft_get_sprite(game, CAPY_BACK_XPM);
	game->capy_left = ft_get_sprite(game, CAPY_LEFT_XPM);
	game->capy_right = ft_get_sprite(game, CAPY_RIGHT_XPM);
}

static void ft_load_hero_sprites(t_game *game)
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
	ft_load_nbrs_sprites(game);
	ft_load_hero_sprites(game);
	ft_load_capy_sprites(game);
}
