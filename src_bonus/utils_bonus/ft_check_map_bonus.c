/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:36:21 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/08 20:49:40 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_check_map(t_game *game)
{
	ft_check_map_lines(game);
	ft_check_map_chars(game);
	ft_check_map_walls(game);
	ft_check_map_items(game);
}
