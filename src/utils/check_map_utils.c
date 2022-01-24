/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:18:36 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/23 23:24:10 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_check_items(t_game *game, int exits, int start)
{
	if (!game->map_coins)
		ft_close_message(game, "not coins found!", 1);
	if (!exits)
		ft_close_message(game, "not exits found!", 1);
	if (!start)
		ft_close_message(game, "not start found!", 1);
}

void	ft_check_map_items(t_game *game)
{
	int	i;
	int	j;
	int	exits;
	int	start;

	exits = 0;
	start = 0;
	game->map_coins = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->map_coins++;
			if (game->map[i][j] == 'E')
				exits++;
			if (game->map[i][j] == 'P')
				start++;
			j++;
		}
		i++;
	}
	ft_check_items(game, exits, start);
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

void ft_check_map_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if((int)ft_strlen(game->map[i++]) != game->map_width)
			ft_close_message(game, "map is not a retangle", 1);
	}
}

void ft_check_map_chars(t_game *game)
{
	int	i;
	int	j;

	game->map_coins = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
					&& game->map[i][j] != 'P')
				ft_close_message(game, "Invalid character in map", 1);
			j++;
		}
		i++;
	}
}
