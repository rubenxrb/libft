/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:42:29 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:42:30 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // hextoa, utoutf8, <empty>, <empty> & <empty>
#include <stdio.h>

char	*ft_hextoa(int n, size_t prec)
{
	char	*hex;
	char	*num;
	char	*z;

	num = ft_itoa_base(n, 16);
	hex = num;
	if (prec)
	{
		z = ft_strnew(prec);
		(void)ft_memset(z, '0', prec);
		hex = ft_strinsrt(num, 0, z);
	}
	return ft_strinsrt(hex, 0, "0x");
}

int		uctoutf8(const char *dest, wchar_t ch)
{
	unsigned char	*p;

	p = (unsigned char *)dest;
	if (ch < 0x80)
		*p++ = (unsigned char)(ch);
	else if (ch < 0x800)
	{
		*p++ = (unsigned char)((ch >> 6) | 0xC0);
		*p++ = (unsigned char)((ch & 0x3F) | 0x80);
	}
	else if (ch < 0x10000)
	{
		*p++ = (unsigned char)(((ch >> 12)) | 0xE0);
		*p++ =  (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
		*p++ =  (unsigned char)((ch & 0x3F) | 0x80);
	}
	else if (ch < 0x110000)
	{
		*p++ = (unsigned char)(((ch >> 18)) | 0xF0);
		*p++ = (unsigned char)(((ch >> 12) & 0x3F) | 0x80);
		*p++ = (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
		*p++ = (unsigned char)((ch & 0x3F) | 0x80);
	}
	return ((int)p != (int)dest ? 1 : 0);
}

int		ft_hextoi(const char *hex)
{
	t_byte	hex_p;
	int		ret;

	if (!hex)
		return (0);
	ret = 0;
	while (*hex)
	{
		hex_p = *hex++;
		if (hex_p >= '0' && hex_p <= '9')
			hex_p = hex_p - '0';
		else if (hex_p >= 'a' && hex_p <='f')
			hex_p = hex_p - 'a' + 10;
		else if (hex_p >= 'A' && hex_p <='F')
			hex_p = hex_p - 'A' + 10;
		 ret = (ret << 4) | (hex_p & 0xF);
	}
	return (ret);
}
