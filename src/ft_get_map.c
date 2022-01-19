/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:31:16 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/19 01:33:42 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int count_map_lines(char *map_path)
{
	int		map_fd;
	char	*tmp;
	int		i;

	map_fd = open(map_path, O_RDONLY);
	// validate map_fd
	i = 0;
	while(1)
	{
		tmp = get_next_line(map_fd);
		if(!tmp)
			break ;
		free(tmp);
		i++;
	}
	close(map_fd);
	return (i);
}

static char **load_map(int n_lines, char *map_path)
{
	char	**map;
	int		i;
	int		map_fd;

	map = (char **)malloc(sizeof(char *) * n_lines + 1);
	// validate map
	map_fd = open(map_path, O_RDONLY);
	// validate map_fd
	i = 0;
	while(1)
	{
		map[i] = get_next_line(map_fd);
		if (!map[i++])
			break ;
	}
	return (map);
}

t_map ft_get_map(char *map_path)
{
	t_map	map;

	map.y = count_map_lines(map_path);
	map.mtx = load_map(map.y, map_path);
	map.x = ft_strlen(*map.mtx) - 1;
    //validate map lines size;
	return (map);
}
