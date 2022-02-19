/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:18:36 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/19 00:17:55 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_check_items(t_game *game)
{
	if (!game->map_c)
		ft_close_message(game, "not coins found!", 1);
	if (!game->map_exits)
		ft_close_message(game, "not exits found!", 1);
	if (game->map_start != 1)
		ft_close_message(game, "must exist just a map start!", 1);
}

void	ft_check_map_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->map_c++;
			if (game->map[i][j] == 'E')
				game->map_exits++;
			if (game->map[i][j] == 'P')
				game->map_start++;
			if (game->map[i][j] == 'A')
				game->n_capys++;
			j++;
		}
		i++;
	}
	ft_check_items(game);
}

void	ft_check_map_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
		if (game->map[0][i++] != '1')
			ft_close_message(game, "map do not have north wall complete!", 1);
	i = 0;
	while (game->map[game->map_height - 1][i])
		if (game->map[game->map_height - 1][i++] != '1')
			ft_close_message(game, "map do not have south wall complete!", 1);
	i = 0;
	while (i < game->map_height)
		if (game->map[i++][0] != '1')
			ft_close_message(game, "map do not have west wall complete!", 1);
	i = 0;
	while (i < game->map_height)
		if (game->map[i++][game->map_width - 1] != '1')
			ft_close_message(game, "map do not have east wall complete!", 1);
}

void	ft_check_map_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i++]) != game->map_width)
			ft_close_message(game, "map is not a rectangle", 1);
	}
}

void	ft_check_map_chars(t_game *game)
{
	int	i;
	int	j;

	game->map_c = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
					&& game->map[i][j] != 'P' && game->map[i][j] != 'A')
				ft_close_message(game, "Invalid character in map", 1);
			j++;
		}
		i++;
	}
}
