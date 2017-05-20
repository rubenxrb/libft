/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:01:09 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:01:11 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strtolower(char *str)
{
	char	*p;

	p = str;
	while (*p)
	{
		*p = ft_tolower(*p);
		p++;
	}
	return (str);
}

char	*printfstrdup(const char *s1)
{
	char	*p;

	if (!s1)
		return (ft_strdup("(null)"));
	p = ft_strnew(ft_strlen(s1));
	if (!p)
		return (0);
	p = ft_strcpy(p, s1);
	return (p);
}
