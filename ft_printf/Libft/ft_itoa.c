/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:18:08 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 17:31:05 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long long n)
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

char	*ft_itoa(int n)
{
	int			len;
	long long	num;
	char		*result;

	len = nbr_len((long long)n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	if (n < 0)
		num = -(long long)n;
	else
		num = n;
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[(len--) - 1] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
	{
		result[0] = '-';
	}
	return (result);
}
