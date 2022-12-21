/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:14:13 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 17:46:26 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return ((void *)temp);
}
