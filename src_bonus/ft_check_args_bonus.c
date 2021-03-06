/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 07:03:23 by idavoli-          #+#    #+#             */
/*   Updated: 2022/02/19 05:11:08 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_args(int argc, char **argv)
{
	int	test_fd;

	if (argc < 2)
	{
		ft_printf("Error\nno argument\n");
		exit(1);
	}
	if (argc > 2)
	{
		ft_printf("Error\nmore then a argument\n");
		exit(1);
	}
	test_fd = open(argv[1], O_RDONLY);
	if (test_fd == -1)
	{
		perror("can not open file");
		close(test_fd);
		exit(1);
	}
	close(test_fd);
}
