/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:31:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/22 15:40:16 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	ft_get_map(char *map_path)
{
	t_map	map;

	map.coins = 0;
	ft_load_map(&map, map_path);
	ft_check_map(map);
	return (map);
}
