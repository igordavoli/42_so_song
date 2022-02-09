/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hero_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:00:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/08 20:49:21 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_exec_move(t_game *game, int x, int y, void *hero_sprite)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass,
		game->hero_x * RES, game->hero_y * RES);
	game->hero_x = game->hero_x + x;
	game->hero_y = game->hero_y + y;
	mlx_put_image_to_window(game->mlx, game->win, hero_sprite,
		game->hero_x * RES, game->hero_y * RES);
}

static void	ft_collect(t_game *game, int x, int y)
{
	game->hero_coins++;
	game->map[game->hero_y + y][game->hero_x + x] = '0';
	game->map_c--;
}

void	ft_put_moves_win(t_game *game, int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	i = 0;
	while (str[i])
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->numbers[str[i] - '0'], i * 9, 0);
		i++;
	}
	free(str);
}

int	ft_move_hero(t_game *game, int x, int y, void *hero_sprite)
{
	mlx_put_image_to_window(game->mlx, game->win, hero_sprite,
		game->hero_x * RES, game->hero_y * RES);
	if (game->map[game->hero_y + y][game->hero_x + x] == '1')
		return (0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'E' && game->map_c)
		return (0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'A')
		ft_close_message(game, "You lose!", 0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'E' && !game->map_c)
		ft_close_message(game, "You win!", 0);
	if (game->map[game->hero_y + y][game->hero_x + x] == 'C')
		ft_collect(game, x, y);
	ft_exec_move(game, x, y, hero_sprite);
	printf("%d\n", ++game->moves);
	ft_put_moves_win(game, game->moves);
	return (0);
}
