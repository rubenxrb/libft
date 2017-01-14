/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:25:40 by rromero           #+#    #+#             */
/*   Updated: 2016/10/20 15:25:41 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void 	ft_printc(char c, int fd);

void	ft_putchar_fd(int c, int fd)
{
	if (c < 0x80)
    	ft_printc((char)c, fd);
  	else if (c < 0x800)
	{
    	ft_printc((char)0xC0 | (c >> 6), fd);
    	ft_printc((char)0x80 | (c & 0x3F), fd);
  	}
  	else if (c < 0x10000)
	{
    	ft_printc((char)0xE0 | (c >> 12), fd);
    	ft_printc((char)0x80 | (c >> 6 & 0x3F), fd);
    	ft_printc((char)0x80 | (c & 0x3F), fd);
	}
  	else
	{
	    ft_printc((char)0xF0 | (c >> 18), fd);
	    ft_printc((char)0x80 | (c >> 12 & 0x3F), fd);
	    ft_printc((char)0x80 | (c >> 6 & 0x3F), fd);
	    ft_printc((char)0x80 | (c & 0x3F), fd);
  	}
}

static void ft_printc(char c, int fd)
{
	write(fd ,&c, 1);
}
