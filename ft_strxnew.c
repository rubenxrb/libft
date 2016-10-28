/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 20:31:52 by rromero           #+#    #+#             */
/*   Updated: 2016/10/27 20:31:53 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strxnew(const char *src, int c)
{
	unsigned char	*p;
	char			*s;
	size_t			i;
	size_t			e;

	i = 0;
	e = 0;
	p = (unsigned char *)src;
	while (p[e])
		if (p[e++] != (unsigned char)c)
			i++;
	s = ft_strnew(i);
	i = 0;
	e = 0;
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
			i++;
		else
			s[e++] = p[i++];
	}
	s[e] = 0;
	return (s);
}
