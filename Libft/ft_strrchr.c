/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:34:17 by yewolee           #+#    #+#             */
/*   Updated: 2022/03/21 20:14:29 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*stemp;
	char	ctemp;

	stemp = (char *)s;
	ctemp = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (stemp[i] == ctemp)
			return (&stemp[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}
