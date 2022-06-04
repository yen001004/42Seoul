/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:44:09 by yewolee           #+#    #+#             */
/*   Updated: 2022/04/02 13:02:26 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_format(va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	s_format(va_list ap)
{
	int		len;
	char	*s;

	len = 0;
	s = (char *)va_arg(ap, char *);
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	p_format(va_list ap)
{
	int					len;
	int					cnt;
	char				c[18];
	unsigned long long	n;

	len = 0;
	cnt = 0;
	n = (unsigned long long)va_arg(ap, void *);
	if (n == 0)
		c[cnt++] = '0';
	while (n > 0)
	{
		c[cnt] = "0123456789abcdef"[n % 16];
		cnt++;
		n /= 16;
	}
	c[cnt++] = 'x';
	c[cnt] = '0';
	len = cnt + 1;
	while (cnt >= 0)
	{
		write(1, &c[cnt], 1);
		cnt--;
	}
	return (len);
}

int	d_format(va_list ap)
{
	int		n;
	int		len;
	char	*s;

	n = va_arg(ap, int);
	s = ft_itoa(n);
	len = nbr_len((long long)n);
	write(1, s, len);
	free(s);
	return (len);
}
