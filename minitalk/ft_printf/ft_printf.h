/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:02:00 by yewolee           #+#    #+#             */
/*   Updated: 2022/04/01 14:02:24 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "Libft/libft.h"

int		ft_printf(const char *str, ...);

int		c_format(va_list ap);
int		s_format(va_list ap);
int		p_format(va_list ap);
int		d_format(va_list ap);

int		u_format(va_list ap);
int		x_format(va_list ap, char *hex);
int		per_format(void);

int		nbr_len(long long n);
char	*ft_utoa(unsigned int n);

#endif
