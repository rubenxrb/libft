/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:43:02 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:42:30 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // <ulltoa-base>, <empty>, <hempty>, <empty> & <empty>

char	*ft_ulltoa_base(unsigned long long n, int b)
{
	char	*num;
	size_t	len;
	long	mod;

	len = ft_ulnumlen(n, b);
	num = ft_strnew(len);
	while (len--)
	{
		mod = n % b;
		num[len] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}
