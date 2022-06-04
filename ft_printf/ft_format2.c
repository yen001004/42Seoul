/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:46:54 by yewolee           #+#    #+#             */
/*   Updated: 2022/04/01 15:02:12 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_format(va_list ap)
{
	unsigned int	n;
	int				len;
	char			*s;

	n = (unsigned int)va_arg(ap, unsigned int);
	s = ft_utoa(n);
	len = nbr_len(n);
	write(1, s, len);
	free(s);
	return (len);
}

int	x_format(va_list ap, char *hex)
{
	unsigned int	n;
	int				cnt;
	int				len;
	char			c[8];

	cnt = 0;
	len = 0;
	n = (unsigned int)va_arg(ap, unsigned int);
	if (n == 0)
		c[cnt++] = '0';
	while (n > 0)
	{
		c[cnt] = hex[n % 16];
		cnt++;
		n /= 16;
	}
	cnt--;
	len = cnt + 1;
	while (cnt >= 0)
	{
		write(1, &c[cnt], 1);
		cnt--;
	}
	return (len);
}

int	per_format(void)
{
	write(1, "%", 1);
	return (1);
}
