/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:49:11 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/13 18:10:15 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *haystack, char *needle, int i, int j)
{
	if (haystack[i + j] != '\0' && haystack[i + j] == needle[j])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haytemp;
	char	*neetemp;

	i = 0;
	haytemp = (char *)haystack;
	neetemp = (char *)needle;
	if (neetemp[i] == '\0')
		return (haytemp);
	while (haytemp[i] != '\0')
	{
		j = 0;
		if (haytemp[i] == neetemp[j])
		{
			while (check(haytemp, neetemp, i, j) && i + j < len)
			{
				j++;
			}
			if (neetemp[j] == '\0')
				return (haytemp + i);
		}
		i++;
	}
	return (0);
}
