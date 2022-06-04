/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:13:07 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 16:26:02 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dcnt;
	size_t	scnt;

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
