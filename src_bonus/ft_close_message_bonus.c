/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_message_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:36:36 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/19 05:11:37 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_close_message(t_game *game, char *message, int code)
{
	if (code == 0)
		ft_printf("%s\n", message);
	else
		ft_printf("Error\n%s\n", message);
	game->err_code = code;
	ft_close(game);
}
