/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:23:46 by rromero           #+#    #+#             */
/*   Updated: 2016/11/17 00:23:59 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int b)
{
	char	*num;
	size_t	size;
	int		neg;
	int		mod;

	neg = 0;
	size = ft_digitnum(n, b);
	if (n < 0 && b == 10)
		neg++;
	num = ft_strnew(size);
	if (neg)
		num[0] = '-';
	num[size + neg] = 0;
	while (size--)
	{
		mod = ((n % b) < 0 ? -(n % b) : (n % b));
		num[size + neg] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}
