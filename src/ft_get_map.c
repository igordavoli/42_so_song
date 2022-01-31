/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:31:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/30 21:43:23 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map(t_game *game, char *map_path)
{
	ft_load_map(game, map_path);
	ft_check_map(game);
}
