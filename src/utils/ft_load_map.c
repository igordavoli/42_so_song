/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:26:08 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/22 15:36:49 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_count_map_lines(char *map_path)
{
	int		map_fd;
	char	*tmp;
	int		i;

	map_fd = open(map_path, O_RDONLY);
	// validate map_fd
	i = 0;
	while (1)
	{
		tmp = get_next_line(map_fd);
		if (!tmp)
			break ;
		free(tmp);
		i++;
	}
	close(map_fd);
	return (i);
}

void	ft_load_map(t_map *map, char *map_path)
{
	int		i;
	int		map_fd;

	map->y = ft_count_map_lines(map_path);
	map->mtx = (char **)malloc(sizeof(char *) * map->y + 1);
	// validate map
	map_fd = open(map_path, O_RDONLY);
	// validate map_fd
	i = 0;
	while (1)
	{
		map->mtx[i] = get_next_line(map_fd);
		if (!map->mtx[i++])
			break ;
	}
		map->x = ft_strlen(map->mtx[0]);
}

