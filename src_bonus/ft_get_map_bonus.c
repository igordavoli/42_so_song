/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:31:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/16 23:24:18 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_create_capys(t_game *game)
{
	int		i;
	int		j;
	int		z;

	game->capys = (t_capy **)malloc(sizeof(t_capy *) * (game->n_capys + 1));
	game->capys[game->n_capys] = NULL;
	i = 0;
	z = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'A')
			{
				game->capys[z] = (t_capy *)malloc(sizeof(t_capy));
				game->capys[z]->curr_sprite = &game->capy_lay;
				game->capys[z]->x = j;
				game->capys[z]->y = i;
				z++;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_map(t_game *game, char *map_path)
{
	ft_load_map(game, map_path);
	ft_check_map(game);
	ft_create_capys(game);
}
