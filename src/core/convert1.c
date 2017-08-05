/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:39:14 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:39:16 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	ft_numlen(int n, int base)
{
	int		i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

int		ft_atoi(const char *str)
{
	int n;
	int s;

	s = 0;
	n = 0;
	while (ft_isblank(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		str = (str + (++s));
	while (*str && ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	return ((s) ? -n : n);
}

char	*ft_itoa_base(int n, int b)
{
	char	*num;
	size_t	size;
	int		neg;
	int		mod;

	neg = 0;
	size = ft_numlen(n, b);
	if ((n < 0) && (b == 10))
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

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}
