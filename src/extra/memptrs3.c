/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memptrs3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:36:12 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:36:13 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new;

	if (!(new = ft_memalloc(new_size)))
		return (0);
	if (size && ptr)
	{
		new = ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
	}
	return (new);
}
