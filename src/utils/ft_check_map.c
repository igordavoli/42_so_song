/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:36:21 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 23:25:59 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check_map(t_game *game)
{
	ft_check_map_lines(game);
	ft_check_map_chars(game);
	ft_check_map_walls(game);
	ft_check_map_items(game);
}
