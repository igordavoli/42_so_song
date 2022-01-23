/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:54:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 01:29:56 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*ft_get_sprite(t_game *game, char *sprite)
{
	return mlx_xpm_file_to_image(game->mlx, sprite, &game->img_width, &game->img_height);
}

void	ft_get_sprites(t_game *game)
{
	game->hero = ft_get_sprite(game, "assets/p_front.xpm");
	game->grass = ft_get_sprite(game, "assets/grass.xpm");
	game->wall = ft_get_sprite(game, "assets/wall.xpm");
	game->coin = ft_get_sprite(game, "assets/coin.xpm");
}
