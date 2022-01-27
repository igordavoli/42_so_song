/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:36:36 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/27 00:59:23 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_free_ptr((void *)&map[i]);
		i++;
	}
	ft_free_ptr((void *)&map);
}

void	ft_free_capy(t_capy **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_capys(t_capy **capys)
{
	int	i;

	if (!capys)
		return ;
	i = 0;
	while (capys[i])
	{
		ft_free_ptr((void *)&capys[i]);
		i++;
	}
	ft_free_ptr((void *)&capys);
}

int	ft_close(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	ft_free_capys(game->capys);
	ft_free_map(game->map);
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
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
