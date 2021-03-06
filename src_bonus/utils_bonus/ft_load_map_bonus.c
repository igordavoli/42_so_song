/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:26:08 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/08 20:49:31 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_count_map_lines(char *map_path)
{
	int		map_fd;
	char	*tmp;
	int		i;

	map_fd = open(map_path, O_RDONLY);
	i = 0;
	while (1)
	{
		tmp = get_next_line(map_fd, 0);
		if (!tmp)
			break ;
		free(tmp);
		i++;
	}
	close(map_fd);
	return (i);
}

void	ft_load_map(t_game *game, char *map_path)
{
	int		i;
	int		map_fd;

	game->map_height = ft_count_map_lines(map_path);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	map_fd = open(map_path, O_RDONLY);
	i = 0;
	while (i <= game->map_height)
	{
		game->map[i] = get_next_line(map_fd, 0);
		i++;
	}
	game->map_width = ft_strlen(game->map[0]);
}
