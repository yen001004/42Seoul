/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:29:43 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/23 13:56:24 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*stemp;
	char	ctemp;

	i = 0;
	stemp = (char *)s;
	ctemp = (char)c;
	while (stemp[i] != ctemp)
	{
		if (stemp[i] == '\0')
			return (0);
		i++;
	}
	return (&stemp[i]);
}
