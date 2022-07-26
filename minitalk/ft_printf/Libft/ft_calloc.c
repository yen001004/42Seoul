/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:44:37 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 20:00:31 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *)malloc(count * size);
	if (m == 0)
		return (0);
	while (i < count * size)
	{
		m[i] = 0;
		i++;
	}
	return ((void *)m);
}
