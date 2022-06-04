/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:06:13 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/13 18:11:58 by yewolee          ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	int			len;
	long long	num;
	char		result[12];

	i = 0;
	num = (long long)n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	len = nbr_len(num);
	i = len;
	while (num)
	{
		result[(len--) - 1] = num % 10 + 48;
		num /= 10;
	}
	write(fd, result, i);
}
