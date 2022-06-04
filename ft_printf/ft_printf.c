/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:42:50 by yewolee           #+#    #+#             */
/*   Updated: 2022/04/02 17:16:15 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = c_format(ap);
	else if (c == 's')
		len = s_format(ap);
	else if (c == 'p')
		len = p_format(ap);
	else if (c == 'd')
		len = d_format(ap);
	else if (c == 'i')
		len = d_format(ap);
	else if (c == 'u')
		len = u_format(ap);
	else if (c == 'x')
		len = x_format(ap, "0123456789abcdef");
	else if (c == 'X')
		len = x_format(ap, "0123456789ABCDEF");
	else if (c == '%')
		len = per_format();
	return (len);
}

static int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_write(const char *c)
{
	write(1, c, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			ret += ft_write(str);
		else
		{
			str++;
			if (is_conversion(*str))
				ret += ft_check_format(*str, ap);
			else
				ret += ft_write(str);
		}
		str++;
	}
	va_end(ap);
	return (ret);
}
