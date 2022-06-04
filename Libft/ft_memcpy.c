/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:28:49 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/13 16:27:09 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dtemp;
	unsigned char	*stemp;

	i = 0;
	dtemp = (unsigned char *)dst;
	stemp = (unsigned char *)src;
	if (n == 0)
		return (dst);
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		dtemp[i] = stemp[i];
		i++;
	}
	return (dst);
}
