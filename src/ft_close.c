/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:36:36 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/30 23:50:50 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_numbers(void *mlx, void **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		mlx_destroy_image(mlx, numbers[i++]);
	free((void *)numbers);
}

void	ft_destroy_images(t_game *game)
{
	ft_destroy_numbers(game->mlx, game->numbers);
	mlx_destroy_image(game->mlx, game->capy_lay);
	mlx_destroy_image(game->mlx, game->capy_front);
	mlx_destroy_image(game->mlx, game->capy_back);
	mlx_destroy_image(game->mlx, game->capy_left);
	mlx_destroy_image(game->mlx, game->capy_right);
	mlx_destroy_image(game->mlx, game->hero_front);
	mlx_destroy_image(game->mlx, game->hero_back);
	mlx_destroy_image(game->mlx, game->hero_left);
	mlx_destroy_image(game->mlx, game->hero_right);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
}

int	ft_close(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	if (game->map)
		ft_free_ptrs((void **)game->map);
	if (game->img_width)
	{
		ft_free_ptrs((void **)game->capys);
		ft_destroy_images(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(game->err_code);
}
