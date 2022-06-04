/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:33:55 by yewolee           #+#    #+#             */
/*   Updated: 2022/05/11 13:38:41 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (str == 0)
	{
		return (0);
	}
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	return (str);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (src[i] != '\0')
	{
		cnt++;
		i++;
	}
	i = 0;
	if (dstsize == 0)
		return (cnt);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (cnt);
}

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	i;
	int	j;
	int	dcnt;
	int	scnt;

	i = 0;
	j = 0;
	dcnt = ft_strlen(dst);
	scnt = ft_strlen(src);
	i = dcnt;
	if (dcnt >= dstsize)
		return (scnt + dstsize);
	while (src[j] != '\0' && dcnt + j < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dcnt + scnt);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
