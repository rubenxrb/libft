/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:18:26 by rromero           #+#    #+#             */
/*   Updated: 2016/10/22 16:18:27 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	char	*ps;
	char	*pd;
	char	tmp;

	if (!s || !*s)
		return ((char *)s);
	ps = (char *)s;
	pd = ps + (ft_strlen(s) - 1);
	while (pd > ps)
	{
		tmp = *ps;
		*ps++ = *pd;
		*pd-- = tmp;
	}
	return ((char *)s);
}
