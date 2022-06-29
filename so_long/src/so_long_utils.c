/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:01:24 by yewolee           #+#    #+#             */
/*   Updated: 2022/06/29 18:44:10 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup_nonl(char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i - 1] = '\0';
	free(str);
	return (dest);
}

char	*ft_strjoin_nonl(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2) - 1;
	str = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (str == 0)
	{
		return (0);
	}
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	free(s1);
	free(s2);
	return (str);
}

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
