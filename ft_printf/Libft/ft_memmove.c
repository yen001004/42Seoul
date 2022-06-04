/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:07:35 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/13 17:15:46 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;

	dtemp = (unsigned char *)dst;
	stemp = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dtemp < stemp)
	{
		while (len--)
		{
			*dtemp++ = *stemp++;
		}
	}
	else
	{
		dtemp += len - 1;
		stemp += len - 1;
		while (len--)
		{
			*dtemp-- = *stemp--;
		}
	}
	return (dst);
}
