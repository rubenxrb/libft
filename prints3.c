/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:38:05 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:38:05 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// putnbr-nl, puthex, puthex-nl, <empty> & <empty>

void	ft_putnbrnl(int c)
{
	if (c)
	{
		ft_putnbr(c);
		ft_putchar('\n');
	}
}

void	ft_puthex(int c)
{
	(void)c;
}

void	ft_puthexnl(int c)
{
	if (c)
	{
		ft_puthex(c);
		ft_putchar('\n');
	}
}
