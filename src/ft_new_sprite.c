/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:39:08 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/20 06:23:31 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	ft_new_sprite(void *mlx, char *sprite)
{
	t_img	img;

	img.ref = mlx_xpm_file_to_image(mlx, sprite, &img.width, &img.height);
	img.pixels = mlx_get_data_addr(img.ref, &img.bits, &img.line, &img.end);
	return (img);
}
