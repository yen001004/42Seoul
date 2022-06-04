/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:16:34 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 15:51:39 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;

	i = 0;
	if (s == 0)
		return (0);
	slen = ft_strlen(s);
	if (slen <= start)
		sub = (char *)malloc(sizeof(char));
	else if (slen - start >= len)
		sub = (char *)malloc(sizeof(char) * len + 1);
	else
		sub = (char *)malloc(sizeof(char) * (slen - start) + 1);
	if (sub == 0)
	{
		return (0);
	}
	while (i < len && start + i < slen)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
