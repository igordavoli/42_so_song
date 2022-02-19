/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 04:36:29 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/29 09:57:52 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_space_chr(int n_spaces)
{
	while (n_spaces)
	{
		ft_putchar_fd(' ', 1);
		n_spaces--;
	}
	return (0);
}

int	ft_resolve_chr(char c, t_flags flags)
{
	int	len;

	len = 1;
	if (flags.f_width)
	{
		ft_put_space_chr(flags.f_width - 1);
		len += (flags.f_width - 1);
	}
	ft_putchar_fd(c, 1);
	if (flags.f_minus)
	{
		ft_put_space_chr(flags.f_minus - 1);
		len += (flags.f_minus - 1);
	}
	return (len);
}
