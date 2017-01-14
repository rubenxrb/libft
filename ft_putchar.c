/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:03:17 by rromero           #+#    #+#             */
/*   Updated: 2016/09/22 13:03:19 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void 	ft_printc(char c);

void	ft_putchar(int c)
{
	if (c < 0x80)
    	ft_printc((char)c);
  	else if (c < 0x800)
	{
    	ft_printc((char)0xC0 | (c >> 6));
    	ft_printc((char)0x80 | (c & 0x3F));
  	}
  	else if (c < 0x10000)
	{
    	ft_printc((char)0xE0 | (c >> 12));
    	ft_printc((char)0x80 | (c >> 6 & 0x3F));
    	ft_printc((char)0x80 | (c & 0x3F));
	}
  	else
	{
	    ft_printc((char)0xF0 | (c >> 18));
	    ft_printc((char)0x80 | (c >> 12 & 0x3F));
	    ft_printc((char)0x80 | (c >> 6 & 0x3F));
	    ft_printc((char)0x80 | (c & 0x3F));
  	}
}

static void ft_printc(char c)
{
	write(1 ,&c, 1);
}
