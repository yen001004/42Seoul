/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:29:54 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/12 16:41:47 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*str;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && is_set(s1[start], set))
	{
		start++;
	}
	while (s1[end] != '\0' && is_set(s1[end], set) && end > 0)
	{
		end--;
	}
	if (start > end)
	{
		str = ft_substr(s1, start, 0);
		return (str);
	}
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
