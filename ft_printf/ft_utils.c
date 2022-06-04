/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:47:47 by yewolee           #+#    #+#             */
/*   Updated: 2022/04/01 15:02:21 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len(long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	int			len;
	long long	num;
	char		*result;

	len = nbr_len((long long)n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	num = n;
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[(len--) - 1] = num % 10 + 48;
		num /= 10;
	}
	return (result);
}
