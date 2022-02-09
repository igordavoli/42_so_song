/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:31:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/08 20:49:03 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_map(t_game *game, char *map_path)
{
	ft_load_map(game, map_path);
	ft_check_map(game);
	game->capys = (t_capy **)malloc(sizeof(t_capy *) * (game->n_capys + 1));
	game->capys[game->n_capys] = NULL;
}
