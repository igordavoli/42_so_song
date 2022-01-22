/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:36:21 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/22 15:39:30 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	check_items(int coins, int exits, int start)
{
	if (!coins)
		ft_close_error("not coins found!");
	if (!exits)
		ft_close_error("not exits found!");
	if (!start)
		ft_close_error("not coins found!");
}

static void	check_map_items(t_map *map)
{
	int	i;
	int	j;
	int	exits;
	int	start;

	exits = 0;
	start = 0;
	i = 0;
	while (map->mtx[i])
	{
		j = 0;
		while (map->mtx[i][j])
		{
			if (map->mtx[i][j] == 'C')
				map->coins++;
			if (map->mtx[i][j] == 'E')
				exits++;
			if (map->mtx[i][j] == 'P')
				start++;
			j++;
		}
		i++;
	}
	check_items(map->coins, exits, start);
}

static void	check_map_walls(t_map map)
{
	int	i;

	i = 0;
	while (map.mtx[0][i])
		if (map.mtx[0][i++] != '1')
			ft_close_error("map do not have north wall complete!");
	i = 0;
	while (map.mtx[map.y - 1][i])
		if (map.mtx[map.y - 1][i++] != '1')
			ft_close_error("map do not have south wall complete!");
	i = 0;
	while (map.mtx[i])
		if (map.mtx[i++][0] != '1')
			ft_close_error("map do not have west wall complete!");
	i = 0;
	while (map.mtx[i])
		if (map.mtx[i++][map.x - 1] != '1')
			ft_close_error("map do not have east wall complete!");
}

void	ft_check_map(t_map map)
{
	check_map_walls(map);
	check_map_items(&map);
	//validate map lines size;
}
