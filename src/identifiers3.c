/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:56:21 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:49:07 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // <isletter>, <empty>, <empty>, <empty>, <empty>

int		ft_isletter(char c1, char c2)
{
	return (ft_tolower(c1) == ft_tolower(c2));
}
