/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 07:03:23 by idavoli-          #+#    #+#             */
/*   Updated: 2022/01/20 07:03:33 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_args(int argc, char **argv)
{
	if (argc < 2)
		ft_close("ERROR: none map was provided");
	if (argc > 2)
		ft_close("ERROR: so much arguments");
	printf("map: %s \n", argv[1]);
}
