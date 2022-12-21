/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:49:28 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 18:27:24 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != 0)
	{
		free(strs[i]);
		strs[i] = 0;
		i++;
	}
	free(strs);
	strs = 0;
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] != c))
		i++;
	return (i);
}

static int	word_count(char const *str, char c)
{
	int	cnt;
	int	len;

	cnt = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		len = word_len(str, c);
		str += len;
		if (len != 0)
			cnt++;
	}
	return (cnt);
}

static char	*word_copy(char const *str, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (str[i] != '\0' && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wcnt;
	char	**strs;

	if (s == 0)
		return (0);
	i = 0;
	wcnt = word_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (wcnt + 1));
	if (strs == 0)
		return (0);
	while (i < wcnt)
	{
		while (*s == c)
			s++;
		strs[i] = word_copy(s, word_len(s, c));
		if (strs[i++] == 0)
		{
			ft_free(strs);
			return (0);
		}
		s += word_len(s, c);
	}
	strs[i] = 0;
	return (strs);
}
