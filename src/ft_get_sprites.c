/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:54:22 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/20 23:58:12 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_img	ft_get_sprite(void *mlx, char *sprite)
{
	t_img	img;

	img.ref = mlx_xpm_file_to_image(mlx, sprite, &img.width, &img.height);
	img.pixels = mlx_get_data_addr(img.ref, &img.bits, &img.line, &img.end);
	return (img);
}

void	ft_get_sprites(t_game *game)
{
	game->hero = ft_get_sprite(game->mlx, "assets/p_front.xpm");
	game->grass = ft_get_sprite(game->mlx, "assets/grass.xpm");
	game->wall = ft_get_sprite(game->mlx, "assets/wall.xpm");
	game->coin = ft_get_sprite(game->mlx, "assets/coin.xpm");
}
