/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_moves_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:29:00 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/19 18:30:05 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
